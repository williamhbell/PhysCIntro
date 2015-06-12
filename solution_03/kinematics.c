#include "hepevt.h"
#include <math.h>
#include <stdio.h>

/* A function to calculate the pt of a given particle within the
** HEPEVT event record. */ 
double pt(HEPEVT *hepevt, int part_index) {
  double pt_sqd; /* pt^2 */

  pt_sqd = pow(hepevt->phep[part_index][0],2.0)*pow(hepevt->phep[part_index][0],2.0);
  if(pt_sqd<=0.) {
    return 0.;
  }
  else {
    return sqrt(pt_sqd);
  }
}

/* A function to calculate displacement of the decay vertex from
** the production vertex of within the HEPEVT event record. */ 
double lxy(HEPEVT *hepevt, int part_index) {
  int idpart; /* Daughter index */
  double lx, ly; /* Distance from production and decay vertex */ 
  double lxy_sqd; /* Lxy^2 */

  if(hepevt->isthep[part_index]==1) {
    fprintf(stderr, "ERROR: Particle with index %d is stable!\n",part_index);
    return 0;
  }
  if(hepevt->jdahep[part_index][0]<=0) {
    fprintf(stderr, "ERROR: Particle with index %d has no daughters!\n",part_index);
    return 0;
  }

  idpart=hepevt->jdahep[part_index][0];
  lx = hepevt->vhep[part_index][0] - hepevt->vhep[idpart][0];
  ly = hepevt->vhep[part_index][1] - hepevt->vhep[idpart][1];

  lxy_sqd = pow(lx,2.0)*pow(ly,2.0);
  if(lxy_sqd<=0.) {
    return 0.;
  }
  else {
    return sqrt(lxy_sqd);
  }
}

double ctau(HEPEVT *hepevt, int part_index) {
  double part_pt;

  part_pt = pt(hepevt,part_index);
  if(part_pt<=0.) {
    return 0.;
  }
  else {
    return lxy(hepevt,part_index)*(hepevt->phep[part_index][4]/part_pt);
  }
}
