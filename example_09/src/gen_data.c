#include <stdlib.h>
#include <math.h>

#include "gen_data.h"

typedef float limits[2];

/* A function to generate a random floating point number between two 
** limits using a flat random number generator.
*/
float gen_value(limits lim) {
  float max, value;
  max = lim[1]-lim[0];
  value = (float)rand()/RAND_MAX;
  value = value*max + lim[0];
  return value;
}

/* A function to generate one sine wave sample */
void gen_data(sample *dat) {
  float a,b,c,step_size,y;
  int i;

  /* Set the limits of the parameters to be generated */
  limits pts_lim={10., 100.}, a_lim={0.5, 2.0}, b_lim={0.0, 0.5}, c_lim={0., M_PI_2};

  /* Generate the number of points to be calculated */
  dat->pts = gen_value(pts_lim);

  /* Generate the parameters of the sine function */
  a = gen_value(a_lim);
  b = gen_value(b_lim);
  c = gen_value(c_lim);
 
  /* Write out the generated values */
  printf("\'pts\' = %d ", dat->pts);
  printf("\'a\' = %f ", a);
  printf("\'b\' = %f ", b);
  printf("\'c\' = %f\n", c);

  /* Calculate the step size from the x range 0 to 2PI */
  step_size=(M_PI*2)/dat->pts;

  /* Fill the data sample with points from the generated sine wave
  ** while there is space in the event record. 
  */
  i=0;
  while (i<dat->pts && i<MAX_PTS) {
    dat->x[i] = step_size*i; /* x value */
    dat->y[i] = a*sin((double)(b*dat->x[i] + c)); /* y value */
    i++;
  }
}

