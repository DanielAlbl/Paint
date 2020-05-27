#include "utilities.h"

// Gets true value of y. (code taken from final callbacks.cpp)
int convertY(int y)
{
  return glutGet(GLUT_WINDOW_HEIGHT) - y;
}

int getOffset(int tiles)
{
  int height = glutGet(GLUT_WINDOW_HEIGHT);

  return height / tiles;
}

// Find center between two points.
float startPointOffset(int p_st, int p_end)
{
   return (p_st - p_end) / 2.0;
}     

// Find center between two points.
int pointDiff(int p_st, int p_end)
{
   return (p_st - p_end);
}     
