/* W. H. Bell
* A program to convert an input file into csv format suitable for use
* with a spreadsheet package.
*/

#include <stdio.h>

int main(int argc, char *argv[]) {
  int new_line_counter;
  FILE *input_ptr, *output_ptr;
  char c;

  int loop_number;
  double value;

  /* Check if the needed command line variables are set */
  if(argc!=3) {
    printf("Usage %s: <input file name> <output file name>\n",argv[0]);
    return 1;
  }

  /* Open the input file for reading */
  input_ptr = fopen(argv[1],"r");
  if (!input_ptr) {
    printf("ERROR: could not open %s for reading\n",argv[1]);
    return 2;
  }

  /* Open the output file for writing */
  output_ptr = fopen(argv[2],"w");
  if (!output_ptr) {
    printf("ERROR: could not open %s for writing\n",argv[2]);
    return 3;
  }

  /* Skip the first two lines */
  new_line_counter=0;
  while((c = fgetc(input_ptr)) != EOF && new_line_counter<2) {
    if( c == '\n') {
      new_line_counter++;
    }
  }

  /* Read the values from the file until EOF is reached */
  while(fscanf(input_ptr,"%d | %lf", &loop_number, &value)!= EOF) {
    /* Print the values into the CSV file using ',' to delimit them */
    fprintf(output_ptr,"%d, %lf\n",loop_number, value);
  }

  /* Close the output and input files */
  fclose(output_ptr);
  fclose(input_ptr);
  return 0;
}
