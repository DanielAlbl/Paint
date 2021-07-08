/*************************************************************************//**
* @file
* @brief
*****************************************************************************/
#ifndef __GUI_H
#define __GUI_H

#include <GL/freeglut.h>
#include "color.h"
#include "filledRectangle.h"
#include "filledEllipse.h"
#include "currentSelection.h"
#include "line.h"
#include "event.h"

void constructPalette();
void buildPalette();
void drawPaletteShapes();

Shapes * selectShape(Points, float*, float*, char);

#endif
