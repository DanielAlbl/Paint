#include "shapeClass.h"

Shapes::Shapes(Points l, float bColor[4], float fColor[4])
{
  limits.x_st = l.x_st;
  limits.y_st = l.y_st;
  limits.x_end = l.x_end;
  limits.y_end = l.y_end;

  borderColor[0] = bColor[0];
  borderColor[1] = bColor[1];
  borderColor[2] = bColor[2];
  borderColor[3] = bColor[3];

  fillColor[0] = fColor[0];
  fillColor[1] = fColor[1];
  fillColor[2] = fColor[2];
  fillColor[3] = fColor[3];
}

Shapes::~Shapes(){}

std::list<Shapes*> Shapes::printQue;
std::list<Shapes*> Shapes::palette;
