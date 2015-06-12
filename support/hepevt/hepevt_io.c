/* W. H. Bell
** Functions to provide binary i/o for the HEPEVT event record.
*/

#include <stdio.h>
#include "hepevt.h"

/* A function to read a HEPEVT event record from a binary file */
/* This function must match the file creation code write_event() */ 
void read_hepevt(FILE *file_ptr, HEPEVT *hepevt) {
  int ipart, icomp;

  fread(&hepevt->nevhep, sizeof(hepevt->nevhep), 1, file_ptr);
  fread(&hepevt->nhep, sizeof(hepevt->nhep), 1, file_ptr);

  /* Read all particles. */
  for(ipart=0;ipart<hepevt->nhep;ipart++) {
    fread(&hepevt->isthep[ipart], sizeof(hepevt->isthep[ipart]), 1, file_ptr);
    fread(&hepevt->idhep[ipart], sizeof(hepevt->idhep[ipart]), 1, file_ptr);

    /* Read all components */
    for(icomp=0;icomp<2;icomp++)
      fread(&hepevt->jmohep[ipart][icomp], sizeof(hepevt->jmohep[ipart][icomp]), 1, file_ptr);

    /* Read all components */
    for(icomp=0;icomp<2;icomp++)
      fread(&hepevt->jdahep[ipart][icomp], sizeof(hepevt->jdahep[ipart][icomp]), 1, file_ptr);

    /* Read all components */
    for(icomp=0;icomp<5;icomp++)
      fread(&hepevt->phep[ipart][icomp], sizeof(hepevt->phep[ipart][icomp]), 1, file_ptr);

    /* Read all components */
    for(icomp=0;icomp<4;icomp++)
      fread(&hepevt->vhep[ipart][icomp], sizeof(hepevt->vhep[ipart][icomp]), 1, file_ptr);
  }
}

/* A function to write a HEPEVT event record to a binary file */
void write_hepevt(FILE *file_ptr, HEPEVT *hepevt) {
  int ipart, icomp;

  /* Save this event */
  fwrite(&hepevt->nevhep, sizeof(hepevt->nevhep), 1, file_ptr);
  fwrite(&hepevt->nhep, sizeof(hepevt->nhep), 1, file_ptr);
  
  /* Write all particles in this event to the file. */
  for(ipart=0;ipart<hepevt->nhep;ipart++) {
    fwrite(&hepevt->isthep[ipart], sizeof(hepevt->isthep[ipart]), 1, file_ptr);
    fwrite(&hepevt->idhep[ipart], sizeof(hepevt->idhep[ipart]), 1, file_ptr);

    /* Write all components */
    for(icomp=0;icomp<2;icomp++)
      fwrite(&hepevt->jmohep[ipart][icomp], sizeof(hepevt->jmohep[ipart][icomp]), 1, file_ptr);

    /* Write all components */
    for(icomp=0;icomp<2;icomp++)
      fwrite(&hepevt->jdahep[ipart][icomp], sizeof(hepevt->jdahep[ipart][icomp]), 1, file_ptr);

    /* Write all components */
    for(icomp=0;icomp<5;icomp++)
      fwrite(&hepevt->phep[ipart][icomp], sizeof(hepevt->phep[ipart][icomp]), 1, file_ptr);

    /* Write all components */
    for(icomp=0;icomp<4;icomp++)
      fwrite(&hepevt->vhep[ipart][icomp], sizeof(hepevt->vhep[ipart][icomp]), 1, file_ptr);
  }
}
