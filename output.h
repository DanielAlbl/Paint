/*************************************************************************//**
* @file
* @brief 
*****************************************************************************/
#ifndef __OUTPUT_H
#define __OUTPUT_H

#include "gui.h"
#include "utilities.h"
#include "color.h"
#include "filledRectangleClass.h"
#include "lineClass.h"
#include "filledEllipseClass.h"
#include <cstring>

  void initOpenGL(int, char**, int, int);
  void clearScreen();
  void redraw();
  void reshapeWindow(const int, const int);
  void drawSquare(float, float, float, float, const float[]);
  void drawBox(float, float, float, float, const float[]);
  void keyboard(unsigned char, int, int);
  void mouse(int, int, int, int);
  void drawDisplay();

#endif
