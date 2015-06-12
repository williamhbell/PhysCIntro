#include "hepevt.h"

/* A function to find the indices of all B mesons in the event */
/* The function inputs are a HEPEVT event record and an array to hold
** the indices of the B mesons. */
int find_B_mesons(HEPEVT *hepevt, int *bm_indices) {
  int particle_id;
  int ipart = 0, n_b_mesons = 0;

  while (ipart<hepevt->nhep && n_b_mesons < NMXHEP) {
    particle_id = hepevt->idhep[ipart];
    if(particle_id<0) particle_id = -particle_id;
    if(particle_id == 511 || particle_id == 521 || particle_id == 531) {
      bm_indices[n_b_mesons] = ipart; /* Store the index of the B meson */
      n_b_mesons++;
    }
    ipart++;
  }
  return n_b_mesons;
}
