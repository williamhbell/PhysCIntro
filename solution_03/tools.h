#ifndef TOOLS_H
#define TOOLS_H

#include "hepevt.h"

/* A function to find the indices of all B mesons in the event */
/* The function inputs are a HEPEVT event record and an array to hold
** the indices of the B mesons. */
int find_B_mesons(HEPEVT *hepevt, int *bm_indices);

#endif
