/* W. H. Bell
** A program to either generate sine wave spectra and save them to a
** binary file or read the spectra from a binary file.  The last
** spectrum either write to or read from the file is plotted with gnuplot.
*/

#include <stdio.h>
#include "gen_data.h"

/* A function to report the usage of this program */
void usage(char *exename) {
  fprintf(stderr," Usage: %s <file name> <-r/-w> [<num events>]\n",exename);
}

int main(int argc, char *argv[]) {
  int i, nevents, nevents_selected;
  sample dat;
  FILE *file_ptr;

  /* Check the number of input arguments */
  if(argc<3 || argc>4) {
    usage(argv[0]);
    return 1;
  }
  
  /* Check the file read or write flag */
  if(!strcmp(argv[2],"-w")) {

    /* Check the number of events flag */
    if(argc==3) {
      printf(" Info: number of events not specified.  Generating 10 events.\n"); 
      nevents=10;
    }
    else {
      /* Catch a non-number string */
      if(sscanf(argv[3], "%d", &nevents)!=1) {
	fprintf(stderr," Error: bad number of events \'%s\'\n",argv[3]);
	usage(argv[0]);
	return 1;
      }
    }

    /* Open an output file */
    file_ptr = fopen(argv[1],"w");
    if (!file_ptr) {
      fprintf(stderr," Error: unable to open \'%s\' for writing.\n",argv[1]);
      return 1;
    }

    /* write the header */
    fwrite(&nevents, sizeof(nevents), 1, file_ptr);

    /* Generate the number of events needed */
    for (i=0;i<nevents;i++) {
      /* Generate the sine wave sample */
      gen_data(&dat); 

      /* Write the sample to a binary file */
      write_data(file_ptr, &dat);
    }

    /* Plot the last event with gnuplot */
    plot_data(&dat);

    fclose(file_ptr);
  }
  else if(!strcmp(argv[2],"-r")) {
    /* Open an input file */
    file_ptr = fopen(argv[1],"r");
    if (!file_ptr) {
      fprintf(stderr," Error: unable to open \'%s\' for reading.\n",argv[1]);
      return 1;
    }
    
    /* Read the number of events contained in the binary file */
    fread(&nevents, sizeof(nevents), 1, file_ptr);

    /* Check the number of events flag */
    if(argc==3) {
      printf(" Info: number of events not specified.  Reading all %d events from file %s.\n",nevents,argv[1]);
    }
    else {
      /* Catch a string which cannot be scanned into an int */
      if(sscanf(argv[3], "%d", &nevents_selected)!=1) {
	fprintf(stderr," Error: bad number of events \'%s\'\n",argv[3]);
	usage(argv[0]);
	fclose(file_ptr);
	return 1;
      }
      else { 
	/* Make sure the number of events requested are available */
	if(nevents_selected <= nevents && nevents_selected > 0) {
	  nevents = nevents_selected;
	}
	printf(" Info: reading the first %d events from the file %s\n", nevents, argv[1]);
      }
    }
    
    /* Read each sine wave data sample from the binary file */
    for (i=0;i<nevents;i++) {
      read_data(file_ptr, &dat);
    }

    /* Plot the last event with gnuplot */
    plot_data(&dat);

    fclose(file_ptr);
  }
  else {
    /* Report a error if the flag supplied is unknown */
    fprintf(stderr," Error: unknown flag \'%s\'\n",argv[2]);
    usage(argv[0]);
    return 1;
  }
  return 0;
}
