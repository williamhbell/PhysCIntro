#include <stdio.h>
#include <string.h>
#include "data_record.h"

/* Define a global C string containing the file name for writing and
   reading */
char particle_file[] = "particles.dat";

/* A function to find and read one record within a binary file. */
int find_record(record *dat, int index) {
  FILE *file_ptr;
  int offset = index - 1;

  file_ptr = fopen(particle_file,"r"); /* Open the file for reading */
  if (!file_ptr) { /* If the file cannot be opened report an error */
    fprintf(stderr," Error: unable to open \'%s\' for reading.\n", particle_file);
    return 1;
  }

  /* Fast forwarding to the selected record */
  if(fseek(file_ptr, (long)(sizeof(*dat)*offset), 0) != 0) {
    fprintf(stderr," Error: unable to fseek record %d\n", index);
    return 1;
  }

  /* Read the selected record */ 
  printf("Reading particle record %d\n", index);
  fread(dat, sizeof(*dat), 1, file_ptr);

  fclose(file_ptr);

  return 0;
} 

/* A functions to write 10 particle records to a binary file. */
int write_records() {
  int i, j;
  FILE *file_ptr;
  record particle_data[12];
  
  /* This style of data entry is not clever but it gives the
  ** opportunity to demonstrate what happens to the array indices with a
  ** typedef argument of this form.
  */

  particle_data[0][RECORD_ID].id = 22;
  particle_data[0][RECORD_MASS].mass = 0.E+00;
  strcpy(particle_data[0][RECORD_NAME].name,"gamma");
  particle_data[0][RECORD_CHARGE].charge = 0;

  particle_data[1][RECORD_ID].id = 24;
  particle_data[1][RECORD_MASS].mass = 8.042E+04;
  strcpy(particle_data[1][RECORD_NAME].name,"W");
  particle_data[1][RECORD_CHARGE].charge =  1;
  
  particle_data[2][RECORD_ID].id = 23;
  particle_data[2][RECORD_MASS].mass = 9.11876E+04;
  strcpy(particle_data[2][RECORD_NAME].name,"Z");
  particle_data[2][RECORD_CHARGE].charge =0;
  
  particle_data[3][RECORD_ID].id = 11;
  particle_data[3][RECORD_MASS].mass = 5.10998902E-01;
  strcpy(particle_data[3][RECORD_NAME].name,"e");
  particle_data[3][RECORD_CHARGE].charge =-1;
  
  particle_data[4][RECORD_ID].id = 13;
  particle_data[4][RECORD_MASS].mass = 1.05658357E+02;
  strcpy(particle_data[4][RECORD_NAME].name,"mu");
  particle_data[4][RECORD_CHARGE].charge =-1;
  
  particle_data[5][RECORD_ID].id = 15;
  particle_data[5][RECORD_MASS].mass = 1.77699E+03;
  strcpy(particle_data[5][RECORD_NAME].name,"tau");
  particle_data[5][RECORD_CHARGE].charge =-1;
  
  particle_data[6][RECORD_ID].id = 12;
  particle_data[6][RECORD_MASS].mass = 0.E+0;
  strcpy(particle_data[6][RECORD_NAME].name,"nu(e)");
  particle_data[6][RECORD_CHARGE].charge =0;
  
  particle_data[7][RECORD_ID].id = 14;
  particle_data[7][RECORD_MASS].mass = 0.E+00;
  strcpy(particle_data[7][RECORD_NAME].name,"nu(mu)");
  particle_data[7][RECORD_CHARGE].charge =0;
  
  particle_data[8][RECORD_ID].id = 16;
  particle_data[8][RECORD_MASS].mass = 0.E+00;
  strcpy(particle_data[8][RECORD_NAME].name,"nu(tau)");
  particle_data[8][RECORD_CHARGE].charge =0;
  
  particle_data[9][RECORD_ID].id = 211;
  particle_data[9][RECORD_MASS].mass = 1.3957018E+02;
  strcpy(particle_data[9][RECORD_NAME].name,"pi");
  particle_data[9][RECORD_CHARGE].charge =1;
  
  particle_data[10][RECORD_ID].id = 111;
  particle_data[10][RECORD_MASS].mass = 1.349766E+02;
  strcpy(particle_data[10][RECORD_NAME].name,"pi");
  particle_data[10][RECORD_CHARGE].charge = 0;
  
  particle_data[11][RECORD_ID].id = 221;
  particle_data[11][RECORD_MASS].mass = 5.4730E+02;
  strcpy(particle_data[11][RECORD_NAME].name,"eta");
  particle_data[11][RECORD_CHARGE].charge = 0;
  
  file_ptr = fopen(particle_file,"w"); /* Open a file for writing. */
  if (!file_ptr) { /* If the file could not be opened. */
    fprintf(stderr," Error: unable to open \'%s\' for writing.\n", particle_file);
    return 1;
  }

  /* Write each particle record header to the screen. */
  printf("Writing particle records:\n");
  printf("\t Id \t Mass    \t Name          \t Charge \n");
  for (i=0; i<12; i++) {
    /* Write each record to the screen */
    printf("\t %d \t %3.3e \t %-12s \t %d \n", 
	 particle_data[i][RECORD_ID].id,
	 particle_data[i][RECORD_MASS].mass,
	 particle_data[i][RECORD_NAME].name,
	 particle_data[i][RECORD_CHARGE].charge);

    /* Write each element of a record to the binary file. */
    for (j=0; j<4; j++) {
      fwrite(&particle_data[i][j], 16, 1, file_ptr);
    }
  }
  printf("\n");

  fclose(file_ptr);

  return 0;
}
