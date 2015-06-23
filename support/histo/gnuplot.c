#include <stdlib.h>
#include <stdio.h>

/* 
** A function to provide a command interface with gnuplot
*/
int gnuplot(const char *gnucommand)
{
  char syscommand[1024];

  /* Build the gnuplot command: leaving gnuplot running after the
     program finishes execution. */
  sprintf(syscommand, "echo \"%s\" | gnuplot -persist", gnucommand);

  /* Use a system call to run gnuplot and return the return value. */
  return system(syscommand);
}
