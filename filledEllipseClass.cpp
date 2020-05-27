#include "filledEllipseClass.h"

void FilledEllip::drawFilled()
{
/*
  float xRad = abs( (limits.x_st - limits.x_end) / 2.0);
  float yRad = abs( (limits.y_st - limits.y_end) / 2.0);
  float x_cent = limits.x_st;
  float y_cent = limits.y_st;

  // Find center of shape on x axis.
  x_cent += startPointOffset(limits.x_end,  limits.x_st);    
  // Find center of shape on y axis.
  y_cent -= startPointOffset(limits.y_st, limits.y_end);

  // stretch circle into ellipse
  float radius = xRad < yRad ? xRad : yRad;
  glColor3fv(borderColor);
  glMatrixMode( GL_MODELVIEW );
  glLoadIdentity();
  glTranslatef( x_cent, y_cent, 0 );
    
    // by ratio of major to minor axes
  glScalef( xRad / radius, yRad / radius, 1.0 );	
  GLUquadricObj *disk = gluNewQuadric();
  gluDisk( disk, 0, radius, int( radius ), 1 );
  gluDeleteQuadric( disk );
  glLoadIdentity();
  glFlush();
  */
}
