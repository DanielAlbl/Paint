/*************************************************************************//**
* @file
* @brief
*****************************************************************************/
#ifndef FILLEDELLIPSE
#define FILLEDELLIPSE

#include "ellipse.h"

class FilledEllip : public Ellip {
public:
  char shape;

  FilledEllip(Points limits, float * borderColor, float * fillColor) :
    Ellip(limits, borderColor, fillColor) {
    filled = true;
  }
};

#endif
