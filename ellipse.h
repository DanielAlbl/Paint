/*************************************************************************//**
* @file
* @brief
*****************************************************************************/
#ifndef ELLIPSE
#define ELLIPSE

#include "shape.h"
#include "utilities.h"

class Ellip : public Shapes {
  float xRad, yRad, x_cent, y_cent, radius;

  void calcHelper();
  void drawHelper(float);

public:
  Ellip(Points, float*, float*);
  void draw();
  void drawFilled();
  bool contains(int, int);
};

#endif
