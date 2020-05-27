#include "ellipseClass.h"

Ellip::Ellip(Points limits, float * borderColor, float * fillColor) : 
       Shapes(limits, borderColor, fillColor)
{
  }

void Ellip::draw()
{
  xRad = abs( (limits.x_st - limits.x_end) / 2.0);
  yRad = abs( (limits.y_st - limits.y_end) / 2.0);
  x_cent = std::min( limits.x_st, limits.x_end );
  y_cent = std::min( limits.y_st, limits.y_end );
  
  // Find center of shape on x and y axis.
  x_cent += abs( startPointOffset(limits.x_end,  limits.x_st) );    
  y_cent += abs( startPointOffset(limits.y_st, limits.y_end) );

  // Call Filled function if filled ellipse is needed.
  if(filled)
    drawFilled();

  // stretch circle into ellipse
  float radius = xRad < yRad ? xRad : yRad;
  glColor3fv(borderColor);
  glMatrixMode( GL_MODELVIEW );
  glLoadIdentity();
  glTranslatef( x_cent, y_cent, 0 );
    
  // by ratio of major to minor axes
  glScalef( xRad / radius, yRad / radius, 1.0 );	
  GLUquadricObj *disk = gluNewQuadric();
  gluDisk( disk, radius - 2, radius, int( radius ), 1 );
  gluDeleteQuadric( disk );
  glLoadIdentity();
  glFlush();
}

void Ellip::drawFilled()
{
  xRad = abs( (limits.x_st - limits.x_end) / 2.0);
  yRad = abs( (limits.y_st - limits.y_end) / 2.0);
  x_cent = std::min( limits.x_st, limits.x_end );
  y_cent = std::min( limits.y_st, limits.y_end );
  
  // Find center of shape on x and y axis.
  x_cent += abs( startPointOffset(limits.x_end,  limits.x_st) );    
  y_cent += abs( startPointOffset(limits.y_st, limits.y_end) );

  // stretch circle into ellipse
  float radius = xRad < yRad ? xRad : yRad;
  glColor3fv(fillColor);
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
}

bool Ellip::contains( int x, int y)
{
  xRad = abs( (limits.x_st - limits.x_end) / 2.0);
  yRad = abs( (limits.y_st - limits.y_end) / 2.0);
  x_cent = std::min( limits.x_st, limits.x_end );
  y_cent = std::min( limits.y_st, limits.y_end );
  
  // Find center of shape on x and y axis.
  x_cent += abs( startPointOffset(limits.x_end,  limits.x_st) );    
  y_cent += abs( startPointOffset(limits.y_st, limits.y_end) );

  float x_ele = (float(x)-x_cent) / xRad;
  float y_ele = (float(y)-y_cent) / yRad;

  // Square each value.
  x_ele *= x_ele;
  y_ele *= y_ele;

  // If sum of squares is within one, point is in ellipse.
  if(x_ele + y_ele <= 1)
    return true;

  // Defult to false.
  return false;
}
