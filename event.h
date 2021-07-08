/*************************************************************************//**
* @file
* @brief
*****************************************************************************/
#ifndef __EVENT_H
#define __EVENT_H

#include "rectangle.h"
#include "filledRectangle.h"
#include "line.h"
#include "ellipse.h"
#include "gl.h"

const char Esc = 27;
const char Bs  = 8;

void keyboard(unsigned char key, int x, int y);
void mouse(int, int, int, int);
void QuitOnEsc(unsigned char);
void ClearOnC(unsigned char);
bool colorPaletteClick(int, int, int);
void redrawEverything();
void deleteLastShape(unsigned char);

#endif
