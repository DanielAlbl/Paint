/*************************************************************************//**
* @file
* @brief
*****************************************************************************/
#ifndef __OUTPUT_H
#define __OUTPUT_H

#include "palette.h"
#include "utilities.h"
#include "color.h"
#include "filledRectangle.h"
#include "filledEllipse.h"
#include "line.h"
#include "event.h"
#include <cstring>

void initOpenGL(int, char**, int, int);
void clearScreen();
void redraw();
void reshapeWindow(const int, const int);
void drawSquare(float, float, float, float, const float[]);
void drawBox(float, float, float, float, const float[]);
void drawDisplay();

#endif
