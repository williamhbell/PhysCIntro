#ifndef GEN_DATA_H
#define GEN_DATA_H

/* The maximum size of an event sample. */
#define MAX_PTS 500

/* A struct to contain a sine wave sample.  */
typedef struct {
  float x[MAX_PTS]; /* The x value */
  float y[MAX_PTS]; /* The y value */
  int pts; /* Number of points in the sample */
} sample;

/* A function to generate a sine wave sample */
void gen_data(sample *);

#endif
