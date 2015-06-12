#ifndef RANDOM_DIST_H
#define RANDOM_DIST_H

/* W. H. Bell
** Functions to provide random numbers following different
** distributions.  These functions use the pseudo-random number
** generator rand from stdlib.h
*/

/* A function to set the seed of the random number generator */
void set_seed(unsigned int seed);

/* A function to return a floating point random number between 0. and
** 1. */
double random_dist_flat(void);

/* A function to return a floating point random number following a
** Gaussian distribution with a given sigma */
double random_dist_gaus(double sigma);

#endif
