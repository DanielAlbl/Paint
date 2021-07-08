/*************************************************************************//**
* @file
* @brief
*****************************************************************************/
#ifndef RECTANGLE
#define RECTANGLE

#include "shapeClass.h"

class Rect : public Shapes {
  void setVertices();

public:
  Rect(Points limits, float * borderColor, float * fillColor) :
    Shapes(limits, borderColor, fillColor) {}
  void draw();
  void drawFilled();
  bool contains(int, int);
};

#endif
