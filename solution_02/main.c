/* W. H. Bell
** 
** A program to sample the CPU and memory usage of a LINUX system every 
** second for a given number of minutes.  The data are written to file
** and plotted at the end of running.
*/

#include "status_utils.h"

/* Needed for sleep */
#include <unistd.h>

#include <stdio.h>

/* A function to print the usage of this program */
void usage(char *exename) {
  fprintf(stderr," Usage: %s <runtime>\n",exename);
  fprintf(stderr,"   where <runtime> is given in seconds\n");
}

int main(int argc, char *argv[]) {
  int run_time;
  char filename[] = "monitor.txt"; /* Output file name */
  FILE *file_ptr;
  status_point status_pt;

  /* Check the number of input arguments */
  if(argc!=2) {
    usage(argv[0]);
    return 1;
  }
  else {
    /* Check the value is a number */
    if(sscanf(argv[1], "%d", &run_time)!=1) {
      fprintf(stderr," Error: bad number of seconds \'%s\'\n",argv[1]);
      usage(argv[0]);
      return 1;
    }
  }

  /* Open an output file to store the monitoring data */
  file_ptr = fopen(filename,"w");
  if (!file_ptr) {
    fprintf(stderr," Error: unable to open \'%s\' for writing.\n",filename);
    return 1;
  }

  /* Read the system status for the given number of minutes */
  while(read_status(&status_pt) < run_time) {

    /* Write the status point to file */
    write_point(file_ptr, &status_pt);

    /* Sleep for 1 second */
    sleep(1);
  }
  fclose(file_ptr);

  /* Plot all of the accumulated data with gnuplot */
  plot_data(filename);

  return 0;
}
