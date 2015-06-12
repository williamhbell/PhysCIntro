/* W. H. Bell
** A program to histogram numbers produced from a Gaussian and flat
** random number generator.  The histograms are plotted with gnuplot.
*/

#include "histogram.h"
#include "random_dist.h"

#include <stdio.h>

int main() {
  int i, h_index[2];
  double value;

  /* Create two histograms */
  h_index[0]=hist_create("Gaus",20,-3.0,3.0);
  h_index[1]=hist_create("Flat",20,0.0,1.0);

  for (i=0;i<10000;i++) {
    /* Generate a random number following a Gaussian distribution */
    value = random_dist_gaus(1.0);

    /* Add this number to the histogram */
    hist_book(h_index[0],value,1.0);

    /* Generate a random number following a flat distribution */
    value = random_dist_flat();

    /* Add this number to the histogram */
    hist_book(h_index[1],value,1.0);
  }

  /* Plot both histograms using gnuplot */
  hist_plot(h_index[0]);
  hist_plot(h_index[1]);

  return 0;
}
