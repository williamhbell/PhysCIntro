#ifndef READ_STATUS
#define READ_STATUS

#include <stdio.h>

typedef struct {
  long time; /* In seconds */
  long memory_usage; /* In kbytes */
} status_point;

long read_status(status_point *status_pt);
void write_point(FILE *file_ptr, status_point *status_pt);
void plot_data(char *filename);

#endif
