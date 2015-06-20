/* W. H. Bell
** This simple program demonstrates the principle of using pointers in C
*/

#include <stdio.h>

void fun(int, int *);

int main() {
  int np = 1, p = 1; /* Initialise two int variables. */

  int v[] = {1,2,3,4}; /* Initialse an int array with four entries */

  /* Initialise a pointer with the address of the first element of the
  ** array. */
  int *pv = &v[0]; 

  int i; /* int used in for loop */

  /* Print the initial values to the standard out */
  printf("Before fun(): np=%d p=%d\n",np,p);

  /* Call the function */
  fun(np, &p);

  /* Print the values after the function call. */
  printf("After fun(): np=%d p=%d\n",np,p);

  /* Use a pointer to iterate over the array entries. */
  for(i=0;i<4;i++) {
    /* Print the element number, value in the element and the address
    ** of the element. */
    printf("v[%d]=%d\t &v[%d]=%p\n",i,*pv,i,pv);
   
    /* Increment the pointer to point at the next address */
    pv++;
  }
}

void fun(int np, int *p) {
  np = 2;  /* Assign 2 to the local variable np. */
  *p = 2;  /* Assign 2 to the memory of p defined in the main */
}
