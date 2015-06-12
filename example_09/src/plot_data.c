#include <stdio.h>

#include "gnuplot.h"
#include "gen_data.h"

/* A function to plot a data sample with gnuplot */
int plot_data(sample *dat) {
  int i;
  FILE *tmpfile;
  char gnuplot_command[250];
  char *filename = "gnuplot_tmp.txt"; /* name of temp file */

  /* Create a temporary file for gnuplot to read. */
  tmpfile = fopen(filename,"w");
  if (!tmpfile) {
    printf ("Error: could not open %s for writing\n",filename);
    return 1;
  }
  i=0;
  /* Write the data in an ASCII form that can be read by gnuplot */
  while (i<dat->pts && i<MAX_PTS) {
    fprintf(tmpfile,"%f %f\n",dat->x[i], dat->y[i]);
    i++;
  }
  fclose(tmpfile);

  /* Construct the gnuplot command */
  sprintf(gnuplot_command, "plot \'%s\'\n", filename);

  /* Call gnuplot to create the plot */
  gnuplot(gnuplot_command);

  /* Remove the temporary file */
  remove(filename);

  return 0;
}
