/* W. H. Bell
** A program to produce simulated pp->b bbar decays at the LHC.
** The program uses the un-tuned Pythia defaults and just MSEL(5)
** i.e. hard scatter.
*/

#include <stdio.h>
#include "hepevt.h"
#include "hepevt_io.h"
#include "pythia.h"

extern PYSUBS pysubs_;
extern HEPEVT hepevt_;

int main(int argc, char *argv[]) {
  int ievt, ipart, icomp, mstat, mconv, b_mesons, particle_id;
  double ecm;
  int nevents;
  FILE *file_ptr;

  /* Check the number of input arguments */
  if(argc!=3) {
    fprintf(stderr," Usage: %s <file name> <num events>\n",argv[0]);
    return 1;
  }
  
  /* Catch a non-number string */
  if(sscanf(argv[2], "%d", &nevents)!=1) {
    fprintf(stderr," Error: bad number of events \'%s\'\n",argv[2]);
    return 2;
  }

  /* Open an output file */
  file_ptr = fopen(argv[1],"w");
  if (!file_ptr) {
    fprintf(stderr," Error: unable to open \'%s\' for writing.\n",argv[1]);
    return 1;
  }

  /* write the header */
  fwrite(&nevents, sizeof(nevents), 1, file_ptr);

  /* Set the centre of mass energy to be 14TeV. */
  ecm=14000.0;

  /* Select bbar production via hard scatter only. */
  pysubs_.msel=5;

  /* Initialise PYTHIA with the setup and beam energy */
  pyinit_("CMS","p","p",&ecm,3,1,1);

  /* ??? */
  mstat=1;
  pystat_(&mstat);

  /* Generate the requested number of events */
  ievt=0;
  while(ievt<nevents) {
    pyevnt_(); /* Generate an event with PYTHIA */

    /* Copy the event record into the HEPEVT common block */
    mconv=1;
    pyhepc_(&mconv);

    /* If this event contains a B0 or B+ or Bs meson keep it. */
    b_mesons=0;
    ipart=0;
    while(b_mesons==0 && ipart<hepevt_.nhep) {
      particle_id = hepevt_.idhep[ipart];
      if(particle_id<0) particle_id = -particle_id;
      if(particle_id == 511 || particle_id == 521 || particle_id == 531) {
        b_mesons++;
      }
      ipart++;
    }
    if(b_mesons>0) { 
      write_hepevt(file_ptr, &hepevt_);
      ievt++; /* Only count events that are kept */
    }
  }

  fclose(file_ptr);

  return 0;
}
