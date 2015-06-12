#include <stdio.h>
#include <math.h>
#include "hepevt.h"
#include "histogram.h"
#include "hepevt_io.h"
#include "tools.h"
#include "kinematics.h"

int main(int argc, char *argv[]) {
  int ievt, ibm;
  int nevents, nevts;
  FILE *file_ptr;

  int n_b_mesons; /* Number of B mesons in an event */
  int bm_indices[NMXHEP]; /* The indices of B mesons in an event */
  HEPEVT hepevt; /* The event record */

  int h_index[2]; /* Histogram indices */

  double b_pt, b_Lxy, b_ctau;
  double mean_b_ctau = 0;

  /* Check the number of input arguments */
  if(argc<2 || argc>3) {
    fprintf(stderr," Usage: %s <file name> [<num events>]\n",argv[0]);
    return 1;
  }
  
  /* Open the input file */
  file_ptr = fopen(argv[1],"r");
  if (!file_ptr) {
    fprintf(stderr," Error: unable to open \'%s\' for reading.\n",argv[1]);
    return 1;
  }

  /* Read the number of events */
  fread(&nevents, sizeof(nevents), 1, file_ptr);
  printf(" Info: \'%s\' contains %d events\n", argv[1], nevents); 

  if (argc==3) {
    /* Catch a non-number string */
    if(sscanf(argv[2], "%d", &nevts)!=1) {
      fprintf(stderr," Error: bad number of events \'%s\'\n",argv[2]);
      return 2;
    }
    /* Catch a number of events that is not valid */
    else if (nevts<=nevents && nevts > 0) {
      nevents = nevts;
    }
  }

  /* Create the histograms */
  h_index[0] = hist_create("B pt", 50, 0., 50.);
  h_index[1] = hist_create("B ctau", 50, 0., 1.);

  printf(" Info: reading the first %d events\n", nevents);

  /* Loop over the selected events */
  for(ievt=0;ievt<nevents;ievt++) {
    /* Read one event into the event record */
    read_hepevt(file_ptr, &hepevt);

    /* Find the B mesons in this event */
    n_b_mesons = find_B_mesons(&hepevt, bm_indices);

    /* Loop over the B mesons in this event */
    for(ibm=0;ibm<n_b_mesons;ibm++){
      /* Calculate the pt of the meson and histogram it */
      b_pt = pt(&hepevt,bm_indices[ibm]);
      hist_book(h_index[0],b_pt, 1.0);

      /* Calculate the ctau of the B meson and histogram it */
      b_ctau = ctau(&hepevt,bm_indices[ibm]);
      hist_book(h_index[1],b_ctau, 1.0);

      /* Very crudely calculate the mean.  (It would be better to use
      ** an exponential fit to the histogram.) */ 
      mean_b_ctau += b_ctau/(double)nevents;
    }
  }
  
  fclose(file_ptr);

  hist_plot(h_index[0]);
  hist_plot(h_index[1]);

  printf(" Result: The mean ctau for the B meson sample is %lf (mm)\n",mean_b_ctau);

  return 0;
}
