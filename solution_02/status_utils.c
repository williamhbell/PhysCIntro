#include "status_utils.h"
#include "gnuplot.h"

/* Needed for sysinfo */
#include <sys/sysinfo.h>

/* Needed for time */
#include <time.h>

#include <stdio.h>

/* A global variable to store the start time. */
time_t start_time = -1;

/* A function to read the status of the system and pack the result
** into the status point struct. 
*/
long read_status(status_point *status_pt) {
  struct sysinfo info;
  time_t current_time;

  /* If this is the first time the function has been called set the 
  ** start_time */
  if(start_time == -1) {
    time(&start_time);
    printf("Read status starting at %s\n",ctime(&start_time));
  }

  /* Check the current time and calculate the relative time in seconds */
  time(&current_time);
  status_pt->time = current_time-start_time;

  /* Query the system info and calculate the current memory usage */
  sysinfo(&info);
  status_pt->memory_usage = (info.totalram - info.freeram)/1024;

  return status_pt->time/60; /* Time elapsed in minutes */
}

/* Write out a data point to file */
void write_point(FILE *file_ptr, status_point *status_pt) {
  fprintf(file_ptr,"%ld %ld\n",status_pt->time, status_pt->memory_usage);
}

/* Plot all the data accumulated in a file with gnuplot */
void plot_data(char *filename) {
  char gnuplot_command[250];

  /* Plot the data */
  sprintf(gnuplot_command, "plot \'%s\'\n", filename);
  gnuplot(gnuplot_command);
}
