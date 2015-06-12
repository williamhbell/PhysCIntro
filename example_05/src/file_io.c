/* W. H. Bell
** Two simple functions to write and read integers from a file.  The
** integers are stored in ascii format.
*/

#include <stdio.h>

/* A function to write an ASCII file containing numbers between 1 and
** 20. */
void file_write(char *filename) {
  FILE *outputfile;
  int i;

  outputfile = fopen(filename,"w"); /* Open the output file */
  if (outputfile) { /* The file was opened successfully */
    /* Print the numbers 1 to 20 into the file */
    for(i=1;i<=20;i++) {
      fprintf(outputfile,"%d",i);

      /* If the number is a multiple of 5 append a new line */
      if(i%5==0) { 
        fprintf(outputfile,"\n");
      }
      else { /* Otherwise append a space */
        fprintf(outputfile," ");
      }
    }
    fclose(outputfile);
  }
  else { /* Report an error */
    printf ("Error: could not open %s for writing\n",filename);
  }
}

/* A function to write an ASCII file containing numbers between 1 and
** 20. */
void file_read(char *filename) {
  FILE *inputfile;
  int i,j;
  char c, str[10];

  inputfile = fopen(filename,"r"); /* Open a file for reading */
  if (inputfile) { /* If the file was opened successfully */
    printf("Reading file %s\n",filename);

    j=0;
    i=0;
    /* Read characters from the file until EOF is reached or the
       buffer is full (including the room needed for \0)*/
    while((c=fgetc(inputfile)) != EOF  && j<9) {
      if( c != ' ' && c != '\n') {
        str[j] = c;  /* Add this character to the buffer */
        j++; /* Increment the buffer index */
      }
      else if (j>0) { /* If a ' ' or '\n' and the buffer contains
			 something */
        str[j+1]='\0'; /* Append the string terminator */
        sscanf(str, "%d", &i); /* Scan the string into an int */
        printf("%d ",i); /* Print the value of the int */
        if(i%5==0) printf("\n"); /* If i is a multiple of 5 print '\n' */
        j=0;
      }
    }
    fclose(inputfile);
  }
  else { /* Print an error if the file cannot be opened */
    printf ("Error: could not open %s for reading\n",filename);
  }
}
