#include <stdio.h>
#include "file_io.h"

/* A function to write a data sample to a binary file */
int write_data(FILE *file_ptr, sample *dat) {
  int i=0;

  /* Write the number of points header */
  fwrite(&dat->pts, sizeof(dat->pts), 1, file_ptr);

  /* Write the sample data */
  while (i<dat->pts && i<MAX_PTS) {
    fwrite(&dat->x[i], sizeof(dat->x[i]), 1, file_ptr);
    fwrite(&dat->y[i], sizeof(dat->y[i]), 1, file_ptr);
    i++;
  }

  return 0;
}

/* A function to read a data sample from a binary file */
int read_data(FILE *file_ptr, sample *dat) {
  int i=0;

  /* Read the number of points header */
  fread(&dat->pts, sizeof(dat->pts), 1, file_ptr);

  /* Read the sample data */
  while (i<dat->pts && i<MAX_PTS) {
    fread(&dat->x[i], sizeof(dat->x[i]), 1, file_ptr);
    fread(&dat->y[i], sizeof(dat->y[i]), 1, file_ptr);
    i++;
  }

  return 0;
}
