/* W. H. Bell
** A program to write and read a file.  The file name is specified at 
** the command line.  The program can either be used to write or read 
** the output file.
*/

#include <stdio.h>
#include <string.h>

#include "file_io.h"

void usage(char *);

int main(int argc, char *argv[]) {
  char ioFlag[50];

  if(argc < 2 || argc > 3) { /* Check the number of input arguments */
    usage(argv[0]); /* Print the usage statement */
    return 0;
  }
  else if(argc==2) { /* If no flag is given set the default to be -w */
    strcpy(ioFlag, "-w");
  }
  else { /* Use the file name and flag as given */
    strcpy(ioFlag, argv[2]);
  }
  
  /* Check if the flag is -w or -r and if not return an error */
  if(!strcmp(ioFlag,"-w")) {
    printf("Writing new file named %s\n",argv[1]);
    file_write(argv[1]);  /* Write the file */
  }
  else if(!strcmp(ioFlag,"-r")) {
    printf("Reading from file named %s\n",argv[1]);
    file_read(argv[1]); /* Read the file */
  }
  else {
    printf("Error: unknown file ioFlag \'%s\'\n",ioFlag);
    usage(argv[0]); /* Print the usage statement */
  }

  return 0;
} 

/* A function to print the program usage */
void usage(char *exename) {
  printf("Usage: %s <file name> [<file io flag>]\n",exename);
  printf(" where <file io flag> = -w (write) or -r (read).\n");
}
