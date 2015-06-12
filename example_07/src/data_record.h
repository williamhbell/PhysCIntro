#ifndef DATA_RECORD_H
#define DATA_RECORD_H

/* Precompiler definitions to make handling the indices easier for the
   developer. */
#define RECORD_ID 0
#define RECORD_MASS 1
#define RECORD_NAME 2
#define RECORD_CHARGE 3

/* Definition of a union typedef entry */
typedef union {
  int id;
  double mass;
  char name[16];
  int charge;
} entry;

/* Defining a typedef record as an array of 4 entries */
typedef entry record[4];

int write_records();
int find_record(record *, int);

#endif
