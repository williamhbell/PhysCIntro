/* W. H. Bell
** This simple program to compare the behaviour of different types of
** pointers.
*/

#include <stdio.h>

/* Define a struct containing two members */
struct st {
  int i;
  int array[2];
};

void fun(int, int *, int *, struct st, struct st *);

int main() {
  int np = 1, p = 1, arr[]={1,1}; /* Initialise two variables and an array */
  struct st dat, dat_p; /* Instantiate two struct instances */

  /* Assign both structs with the same data */
  dat.i=1;
  dat.array[0]=1;
  dat.array[1]=1;
  dat_p.i=1;
  dat_p.array[0]=1;
  dat_p.array[1]=1;

  /* Print the values contained the variables, the array and the two
     struct instances */
  printf("Before fun():\n \t np=%d p=%d\n",np,p);
  printf("\t arr[0] = %d, arr[1] = %d\n", arr[0], arr[1]);
  printf("\t dat.i = %d, dat.array[0] = %d, dat.array[1] = %d\n", dat.i, dat.array[0], dat.array[1]);
  printf("\t dat_p.i = %d, dat_p.array[0] = %d, dat_p.array[1] = %d\n\n", dat_p.i, dat_p.array[0], dat_p.array[1]);
  
  /* Call the function to modify some of the values */
  fun(np, &p, arr, dat, &dat_p);
  
  /* Print the values contained the variables, the array and the two
     struct instances */
  printf("After fun():\n \t np=%d p=%d\n",np,p);
  printf("\t arr[0] = %d, arr[1] = %d\n", arr[0], arr[1]);
  printf("\t dat.i = %d, dat.array[0] = %d, dat.array[1] = %d\n", dat.i, dat.array[0], dat.array[1]);
  printf("\t dat_p.i = %d, dat_p.array[0] = %d, dat_p.array[1] = %d\n", dat_p.i, dat_p.array[0], dat_p.array[1]);
}

/* A function to demonstrate the behaviour of structs and arrays when
   passed to a function */
void fun(int np, int *p, int *arr, struct st dat, struct st *dat_ptr) {
  /* Assign a number to the local variable np.  */
  np = 2; 

  /* Assign a number to the memory of the variable p declared in the
     main */
  *p = 2; 

  /* Assign numbers to the elements of the array declared in the main */  
  arr[0]=3; arr[1]=4; 

  /* Assign numbers to the members of the local struct instance dat */
  dat.i=5; dat.array[0]=6; dat.array[1]=7; 

  /* Assign numbers to the members of the struct instance dat_p
     declared in the main. */
  dat_ptr->i=5; dat_ptr->array[0]=6; dat_ptr->array[1]=7;
}
