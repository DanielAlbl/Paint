/*************************************************************************//**
* @file
* @brief
*****************************************************************************/
#ifndef LINE
#define LINE

#include "shape.h"

class Line : public Shapes {
public:
  Line(Points limits, float * borderColor, float * fillColor) :
    Shapes(limits, borderColor, fillColor) {}
  void draw();
  void drawFilled();
  bool contains(int, int);
};

#endif
