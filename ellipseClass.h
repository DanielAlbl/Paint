/*************************************************************************//**
* @file
* @brief 
*****************************************************************************/
#ifndef ELLIPSE
#define ELLIPSE

#include <cmath>
#include "shapeClass.h"
#include "utilities.h"
#include <algorithm>
#include <iostream>

class Ellip : public Shapes
{
  float xRad,
        yRad,
        x_cent,
      	y_cent;
 
  public:
    Ellip(Points, float*, float*);
    void draw();
    void drawFilled();
    bool contains(int, int);
};

#endif
