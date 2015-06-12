/* W. H. Bell
** A very simple C program to read arguments from the command line
** and print them.
*/

#include <stdio.h>

int main(int argc, char *argv[]) {
  int i;

  /* Print the number of arguments given at the command line */
  printf("argc=%d (argc => size of argv array)\n", argc);

  /* Print each argument */
  for(i=0;i<argc;i++) {
    printf("argv[%d]=%s\n",i,argv[i]);
  }
  return 0;
}
