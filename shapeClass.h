/*************************************************************************//**
* @file
* @brief This is the base calss used by the drawn shapes in paint. 
*****************************************************************************/
#ifndef SHAPES
#define SHAPES

#include <list>
#include <GL/freeglut.h>
#include "points.h"

/*!
 * @brief This is the base class for all geometric classes.
 */
class Shapes
{
 public:
  Points limits;
  static std::list<Shapes*> printQue;
  static std::list<Shapes*> palette;
  float borderColor[4];
  float fillColor[4];
  bool filled = false;
  char shape = '\0';

  Shapes(Points l, float[4], float[4]); /*!<Baseclass constructor*/
  virtual ~Shapes() = 0;
  virtual void draw() = 0;  
  virtual void drawFilled() = 0;
  virtual bool contains(int x, int y) = 0;
};

#endif
