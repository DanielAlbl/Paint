/*************************************************************************//**
* @file
* @brief 
*****************************************************************************/
#ifndef __GUI_H
#define __GUI_H

#include <GL/freeglut.h>
#include <cstring>
#include "color.h"
#include "filledRectangleClass.h"
#include "filledEllipseClass.h"
#include "currentSelectionClass.h"
#include "lineClass.h"
#include "shapeClass.h"

  void keyboard(unsigned char, int, int);
  void mouse(int, int, int, int);
  void constructPalette();
  void buildPalette();
  void drawPaletteShapes();

  Shapes * selectShape(Points, float*, float*, char);

#endif
