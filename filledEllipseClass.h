/*************************************************************************//**
* @file
* @brief
*****************************************************************************/
#ifndef FILLEDELLIPSE
#define FILLEDELLIPSE

#include "ellipseClass.h"

class FilledEllip : public Ellip {
public:
  char shape;

  FilledEllip(Points limits, float * borderColor, float * fillColor) :
    Ellip(limits, borderColor, fillColor) {
    filled = true;
  }
};

#endif
