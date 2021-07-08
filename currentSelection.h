/*************************************************************************//**
* @file
* @brief
*****************************************************************************/
#ifndef CURRENTSELECTION
#define CURRENTSELECTION

#include "points.h"
#include "color.h"
#include "shape.h"

struct Selection {
  char shape = 'R';   //Rectangle
  Points limits;
  float border[4] = {1.0, 1.0, 1.0, 1.0}; //White
  float fill[4]   = {0.8721, 0.625, 0.025, 1.0}; //Maroon
};

struct MoveContainer {
  int x = -1, y = -1;
  Shapes * shape;
};

class CurrentSelection {
public:
  static Selection current;
  static MoveContainer currentMove;
};

#endif
