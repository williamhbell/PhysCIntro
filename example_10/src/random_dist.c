/* W. H. Bell
** Functions to provide random numbers following different
** distributions.  These functions use the pseudo-random number
** generator rand from stdlib.h
*/

#include <math.h>
#include <stdlib.h>

/* 1 => spare random deviate stored. */
static int random_dist_gaus_status = 0;

/* A function to set the seed of the random number generator */
void set_seed(unsigned int seed) {
  srand(seed);
}

/* A function to return a floating point random number between 0. and
** 1. */
double random_dist_flat() {
  double random_num;
  random_num = (double)rand()/RAND_MAX;
  return random_num;
}

/* A function to return a floating point random number following a
** Gaussian distribution with a given sigma */
double random_dist_gaus(double sigma) {
  static double spare_num;
  double random_num, x, rand_num_1, rand_num_2, rsq, fac;

  /* We don't have an extra deviate handy */
  if (random_dist_gaus_status != 1) {
    do {
      /* Pick two uniform numbers in the square extending from -1 to +1
      ** in each direction. */
      rand_num_1 = 2.0*random_dist_flat()-1.0;
      rand_num_2 = 2.0*random_dist_flat()-1.0;

      /* See if they are in the unit circle. */
      rsq = pow(rand_num_1,2.0)+pow(rand_num_2,2.0);
    } while (rsq >= 1.0 || rsq == 0);

    /* Now make the Box-Muller transformation to get two normal deviates. 
    ** Return one and save the other for next time. */
    fac = sqrt (-2.*log(rsq)/rsq);
    random_num = rand_num_1 * fac * sigma;
    spare_num = rand_num_2 * fac;
    random_dist_gaus_status = 1;
  }
  else {
    /* Use the extra deviate */
    random_num = spare_num * sigma;
    random_dist_gaus_status = 0;
  }
  return random_num;
}
