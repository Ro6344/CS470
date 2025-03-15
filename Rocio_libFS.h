
#ifndef Rocio_LIBFS_H
#define Rocio_LIBFS_H

#include <stdio.h>
#include <stdlib.h>

// Function declarations
int fileCreate(const char *filename);
int fileOpen(const char *filename, const char *mode, FILE **file);
int fileWrite(FILE *file, const char *content);
int fileRead(FILE *file);
int fileClose(FILE *file);
int fileDelete(const char *filename);
void menu();

#endif 
