#ifndef HEPEVT_IO_H
#define HEPEVT_IO_H

/* A function to read a HEPEVT event record from a binary file */
/* This function must match the file creation code write_event() */
void read_hepevt(FILE *file_ptr, HEPEVT *hepevt);

/* A function to write a HEPEVT event record to a binary file */
void write_hepevt(FILE *file_ptr, HEPEVT *hepevt);

#endif
