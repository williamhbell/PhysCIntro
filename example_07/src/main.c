/* W. H. Bell
** A program to write several records to a binary file and read back
** the 7th record.  The program demonstrates the usage of union and
** typedef statements.
*/

#include <stdio.h>
#include "data_record.h"

int main() {
  int ret_val;

  /* Instantiate an instance of the typedef record */
  record dat;

  /* Print the size of the union */
  /* (Any index could be used for these print statements.) */
  printf("The size of one entry = %d\n", sizeof(dat[RECORD_ID]));

  /* Print the size of each member of the union to demonstrate the
     relationship between the size of the union members and the
     union. */
  /* (Any index could be used for these print statements.) */
  printf("The size of each member of the entry union:\n");
  printf("\t sizeof(id)=%d\n", sizeof(dat[RECORD_ID].id));
  printf("\t sizeof(mass)=%d\n", sizeof(dat[RECORD_ID].mass));
  printf("\t sizeof(name)=%d\n", sizeof(dat[RECORD_ID].name));
  printf("\t sizeof(charge)=%d\n\n", sizeof(dat[RECORD_ID].charge));

  /* Write all particle records to a binary file.  If an error is
     returned exit passing the return value to the OS.*/
  if((ret_val = write_records())!=0) {
    return ret_val;
  }

  /* Read data from the 7th record. If an error is
     returned exit passing the return value to the OS.*/
  if((ret_val = find_record(&dat,7))!=0) {
    return ret_val;
  }
  
  /* Print the values from the 7th record.*/
  printf("\t Id \t Mass    \t Name          \t Charge \n");
  printf("\t %d \t %3.3e \t %-12s \t %d \n", 
	 dat[RECORD_ID].id,
	 dat[RECORD_MASS].mass,
	 dat[RECORD_NAME].name,
	 dat[RECORD_CHARGE].charge);
  
  return 0;
}
