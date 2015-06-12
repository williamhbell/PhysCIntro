#ifndef HEPEVT_H
#define HEPEVT_H

/* W. H. Bell
** The standard HEPEVT common block matching this version of Pythia
*/

/* Maximum number of particles */
#define NMXHEP 4000

typedef struct {
  int nevhep; /* The event number */
  int nhep; /* The number of particles in the event */
  int isthep[NMXHEP]; /* Particle status code */
  int idhep[NMXHEP]; /* Particle identifier (PDG standard) */
  int jmohep[NMXHEP][2]; /* Mother index/indices ranges */
  int jdahep[NMXHEP][2]; /* Daughter index/indices ranges */
  double phep[NMXHEP][5]; /* Four vector and mass */
  double vhep[NMXHEP][4]; /* Production vertex */
} HEPEVT;

/*
** Assuming ipart > 0 and < NMXHEP
**
** isthep[ipart] can contain: 
**   0 : null entry.
**   1 : Particle has not decayed or fragmented
**   2 : Particle has decayed or fragmented
**   3 : Kept for documentation
**
** 
** jmohep[ipart][0] : index of the position where the mother is
** stored. The value is 0 for initial entries. 
**
** jmohep[ipart][1] : index of position of second mother. Normally
** only one mother exists, in which case the value 0 is to be used. In
** PYTHIA, entries with codes 91-94 are the only ones to have two
** mothers. The flavour contents of these objects, as well as details
** of momentum sharing, have to be found by looking at the mother
** partons, i.e. the two partons in positions jmohep[ipart][0] and
** jmohep[ipart][1] for a cluster or a shower system, and the range
** jmohep[ipart][0]-jmohep[ipart][1] for a string or an independent
** fragmentation parton system.
**
**
** jdahep[ipart][0] : index of the position of the first
** daughter. If an entry has not decayed, this is 0.
** 
** jdahep[ipart][1] : index of the position of the last daughter. If
** an entry has not decayed, this is 0. It is assumed that daughters
** are stored sequentially, so that the whole range
** jdahep[ipart][0]-jdahep[ipart][1] contains daughters. This variable
** should be set also when only one daughter is present, as in K^0 to
** K_S^0 decays, so that looping from the first daughter to the last
** one works transparently. Normally daughters are stored after
** mothers, but in backwards evolution of initial-state radiation the
** opposite may appear, i.e. that mothers are found below the
** daughters they branch into. Also, the two daughters then need not
** appear one after the other, but may be separated in the event
** record.
** 
**
** phep[ipart][0] : momentum in the x direction, in GeV/c.
**
** phep[ipart][1] : momentum in the y direction, in GeV/c.
**
** phep[ipart][2] : momentum in the z direction, in GeV/c.
**
** phep[ipart][3] : energy, in GeV.
**
** phep[ipart][4] : mass, in GeV/c^2. For space-like partons, it is allowed to use a
** negative mass, according to phep[ipart][4] $ = -\sqrt{-m^2}$.
**
**
** vhep[ipart][0] : production vertex x position, in mm.
** 
** vhep[ipart][1] : production vertex y position, in mm.
**
** vhep[ipart][2] : production vertex z position, in mm.
**
** vhep[ipart][3] : production time, in mm/c ( $\approx 3.33 \times 10^{-12}$ s).
**  
*/

#endif
