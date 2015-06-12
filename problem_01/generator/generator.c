/* W. H. Bell
** A program to generate random numbers obeying a Landau distribution
** using the GNU scientific libraries.
*/

#include <stdio.h>

/* Header files needed for the Landau distribution generator */
#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>

int main() {
  int i;
  double ran_num;

  const gsl_rng_type * T;
  gsl_rng * r;

  /* Initialise the random number generator */
  gsl_rng_env_setup();
  T = gsl_rng_default;
  r = gsl_rng_alloc (T);
  printf("Loop Num | Value\n");
  printf("----------------\n");
  for (i=0;i<2500;i++) {

    /* Generate a random number obeying the Landau distribution */
    ran_num=gsl_ran_landau (r);

    printf("%.4d     | %lf\n", i, ran_num);
  }

  return 0;
}
