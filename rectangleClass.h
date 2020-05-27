/*************************************************************************//**
* @file
* @brief 
*****************************************************************************/
#ifndef RECTANGLE
#define RECTANGLE

#include "shapeClass.h"
#include <algorithm> 

  void drawSquare(float, float, float, float, const float[]);
  void drawBox(float, float, float, float, const float[]);

class Rect : public Shapes
{
  public:
    Rect(Points limits, float * borderColor, float * fillColor) : 
         Shapes(limits, borderColor, fillColor){}
    void draw();
    void drawFilled();
    bool contains(int, int);
};

#endif
