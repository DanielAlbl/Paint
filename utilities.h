/*************************************************************************//**
* @file
* @brief Utilities contains general functions to assist other functs.
*****************************************************************************/
#ifndef __UTILITIES_H
#define __UTILITIES_H

#include <GL/freeglut.h>

// Basic functions to aid program execution.
int convertY(int);
int getOffset(int);
float startPointOffset(int, int);
int pointDiff(int p_st, int p_end);

#endif
