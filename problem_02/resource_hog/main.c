/* W. H. Bell
** A program to produce an oscillating memory and CPU load.
*/

/* Needed for malloc */
#include <stdlib.h>

/* Needed for sleep */
#include <unistd.h>

/* Needed for time */
#include <time.h>

#include <stdio.h>

#define MEGABYTE 1048576

/* A megabyte sized buffer */
typedef unsigned char meg_buffer[MEGABYTE];

/* Function pre-declarations */
void memory_hog(int num_megs, unsigned int alloc_delay, unsigned int pause, unsigned int dealloc_delay);
void fill_buffer(meg_buffer buffer);
void cpu_hog(unsigned int run_time);

int main() {
  /* Loop forever */
  while(1) {
    /* Allocate 20Mbytes of memory in steps and then free it again. */
    memory_hog(20,1,4,1);

    /* Load the CPU of the machine for 6 seconds. */
    cpu_hog(6);
  }
  return 0;
}

/* A function to allocate an amount of seconds over the course of a
** number of seconds.  The memory is then freed, with an adjustable
** time delay. */
void memory_hog(int num_megs, unsigned int alloc_delay, 
		unsigned int pause, unsigned int dealloc_delay) {
  /* Define an array of points of the correct type to keep track of
  ** the memory dynamically allocated. */
  meg_buffer *large_buffer[num_megs];

  int i;
  /* Allocate dynamic memory until the number of megabytes requested
  ** is equal to num_megs */
  for(i=0;i<num_megs;i++) {
    /* Sleep for some number of seconds */
    sleep(alloc_delay);
    
    /* Request a Megabyte block of memory and store a pointer to it. */
    large_buffer[i] = (meg_buffer*)malloc(sizeof(meg_buffer));
    
    /* Memory is only virtually allocated unless it is filled.
    ** Therefore fill the allocated memory. */
    fill_buffer(*large_buffer[i]);
  }
  
  /* Pause before freeing memory */
  sleep(pause);

  /* Free allocated memory */
  for(i=0;i<num_megs;i++) {
    sleep(alloc_delay);
    free(large_buffer[i]); /* Free one megabyte */
  }
}

/* Fill a Megabyte buffer with random numbers */
void fill_buffer(meg_buffer buffer) {
  long i;
  for(i=0;i<MEGABYTE;i++) {
    buffer[i] = (unsigned char)rand();
  }
}

/* A function to use up a lot of CPU for a given number of seconds */
void cpu_hog(unsigned int run_time) {
  time_t start_time, current_time;
  time(&start_time);
  current_time = start_time;
  while(current_time-start_time < run_time) {
    time(&current_time);
  }
}
