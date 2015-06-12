#ifndef FILE_IO_H
#define FILE_IO_H

#include <stdio.h>

/* Included for definition of 'sample' */
#include "gen_data.h"

/* A function to write a data sample to a binary file */
int write_data(FILE *, sample *);

/* A function to read a data sample from a binary file */
int read_data(FILE *, sample *);

#endif
