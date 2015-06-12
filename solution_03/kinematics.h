#ifndef KINEMATICS_H
#define KINEMATICS_H

#include "hepevt.h"

/* A function to calculate the pt of a given particle within the
** HEPEVT event record. */ 
double pt(HEPEVT *hepevt, int part_index);

/* A function to calculate displacement of the decay vertex from
** the production vertex of within the HEPEVT event record. */ 
double lxy(HEPEVT *hepevt, int part_index);

/* A function to calculate the proper lifetime in terms of ctau */
double ctau(HEPEVT *hepevt, int part_index);

#endif
