/* W. H. Bell
** A set of functions to provide histogram functionality.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "histogram.h"
#include "gnuplot.h"

/* A struct to contain the information for each histogram */
typedef struct {
  char hname[250]; /* Histogram name. */
  int num_bins; /* Number of bins. */
  double lower_lim; /* Lower limit of the histogram. */
  double upper_lim; /* upper limit of the histogram. */
  double bins[MAX_BINS]; /* The bin contents. */
  double bin_size; /* Cached to reduce booking time. */
} hist_entry;

/* Static memory to contain histogram data */
static int num_hist = 0;
static hist_entry h_dat[MAX_HIST];

/* A function to create a histogram */
int hist_create(char *hname, int num_bins, double lower_lim, double upper_lim) {
  int i;

  /* Check if memory has been defined for this histogram */
  if(num_hist >= MAX_HIST) {
    fprintf(stderr,"ERROR: Out of histogram memory!\n");
    return -1;
  }
  
  /* Reserve two bins for underflow and overflow */
  if(num_bins > (MAX_BINS-2) || num_bins < 1) {
    fprintf(stderr,"ERROR: num_bins is out of range!\n");
    return -1;
  } 

  /* Fill the static memory with this histogram */
  strcpy(h_dat[num_hist].hname,hname);
  h_dat[num_hist].num_bins=num_bins;
  h_dat[num_hist].lower_lim=lower_lim;
  h_dat[num_hist].upper_lim=upper_lim;
  
  /* Calculate the bin size from the limits and the number of bins */
  h_dat[num_hist].bin_size=(h_dat[num_hist].upper_lim-h_dat[num_hist].lower_lim)/h_dat[num_hist].num_bins;

  /* Initialise the bin contents to be zero */
  for(i=0;i<(num_bins+2);i++) {
    h_dat[num_hist].bins[i] = 0;
  }  
  num_hist++;

  /* Return the histogram index for the user. */
  return num_hist-1;
}

/* A function to add a value to an existing histogram */
int hist_book(int h_index, double value, double weight) {
  int i;

  if(h_index == MAX_HIST || h_index >= num_hist) {
    fprintf(stderr,"ERROR: num_hist out of range\n");
    return 1;
  }

  /* Underflow */
  if(value<h_dat[h_index].lower_lim) {
    h_dat[h_index].bins[h_dat[h_index].num_bins] += weight;
  }
  /* Overflow */
  else if (value>=h_dat[h_index].upper_lim) {
    h_dat[h_index].bins[h_dat[h_index].num_bins+1] += weight;
  }
  /* Book the value */
  else {
    i=0;
    while(value >= (h_dat[h_index].bin_size*i+h_dat[h_index].lower_lim) && 
	  i<h_dat[h_index].num_bins) i++;
    i--;
    if(i<0) {
      fprintf(stderr,"CRITICAL ERROR: something has gone very wrong!\n");
      exit(1);
    }

    h_dat[h_index].bins[i] += weight;
  }

  return 0;
}

/* A function to plot a histogram's contents using gnuplot. */
int hist_plot(int h_index) {
  int i;

  FILE *tmpfile;
  char gnuplot_command[250];
  char tmp_filename[]="/tmp/gnuplot.XXXXXX";
  int file_descriptor;

  if(h_index == MAX_HIST || h_index >= num_hist) {
    fprintf(stderr,"ERROR: num_hist out of range\n");
    return 1;
  }

  /* Create a temporary file */
  file_descriptor = mkstemp(tmp_filename);
  if(file_descriptor == -1) {
     printf ("Error: mkstemp could not create a suitable temporary file with the template /tmp/gnuplot.XXXXXX\n");
    return 1; 
  }
 
  /* Open the temporary file for gnuplot to read. */
  tmpfile = fdopen(file_descriptor, "w");
  if (!tmpfile) {
    printf ("Error: could not open %s for writing\n",tmp_filename);
    return 1;
  }

  /* Write the bin centres and their contents to file. */
  i=0;
  while (i<h_dat[h_index].num_bins+2 && i<MAX_BINS) {
    fprintf(tmpfile,"%lf %lf\n",
	    h_dat[h_index].bin_size*((double)i+0.5)+h_dat[h_index].lower_lim,
	    h_dat[h_index].bins[i]);
    i++;
  }
  fclose(tmpfile); /* Closes the file stream and the file descriptor */

  /* Create the gnuplot command */
  sprintf(gnuplot_command, "plot \'%s\' tit \'%s\' with boxes\n", tmp_filename, h_dat[h_index].hname);

  /* Plot the data */
  gnuplot(gnuplot_command);

  /* Remove the temporary file */
  remove(tmp_filename);

  return 0;
}

/* A function to get the histogram definition information */
int hist_get_info(int h_index, char *hname, int *num_bins, double *lower_lim, double *upper_lim) {
  if(h_index == MAX_HIST || h_index >= num_hist) {
    fprintf(stderr,"ERROR: num_hist out of range\n");
    return 1;
  }

  strcpy(hname, h_dat[h_index].hname);
  *num_bins = h_dat[h_index].num_bins;
  *lower_lim = h_dat[h_index].lower_lim;
  *upper_lim = h_dat[h_index].upper_lim;

  return 0;
}

/* A function to get the bin contents of a histogram */
/* *bins is assumed to be an array of size num_bins+2. */
int hist_get_contents(int h_index, double *bins) {
  int i;

  if(h_index == MAX_HIST || h_index >= num_hist) {
    fprintf(stderr,"ERROR: num_hist out of range\n");
    return 1;
  }

  i=0;
  while (i<h_dat[h_index].num_bins+2 && i<MAX_BINS) {
    bins[i] = h_dat[h_index].bins[i];
    i++;
  }

  return 0;
}

