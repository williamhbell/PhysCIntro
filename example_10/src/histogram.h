#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#define MAX_BINS 2002
#define MAX_HIST 20

/* W. H. Bell
** A set of functions to provide histogram functionality.
*/

/* A function to create a histogram */
int hist_create(char *hname, int num_bins, double lower_lim, double upper_lim);

/* A function to add a value to an existing histogram */
int hist_book(int num_hist, double value, double weight);

/* A function to plot a histogram's contents using gnuplot. */
int hist_plot(int h_index);

/* A function to get the histogram definition information */
int hist_get_info(int h_index, char *hname, int *num_bins, double *lower_lim, double *upper_lim);

/* A function to get the bin contents of a histogram */
/* *bins is assumed to be an array of size num_bins+2. */
int hist_get_contents(int h_index, double *bins);

#endif
