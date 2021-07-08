#include "ellipseClass.h"

Ellip::Ellip(Points limits, float * borderColor, float * fillColor) :
  Shapes(limits, borderColor, fillColor) {}

void Ellip::calcHelper() {
  xRad = abs(startPointOffset(limits.x_st, limits.x_end));
  yRad = abs(startPointOffset(limits.y_st, limits.y_end));
  x_cent = std::min(limits.x_st, limits.x_end);
  y_cent = std::min(limits.y_st, limits.y_end);

  // Find center of shape on x and y axis.
  x_cent += abs( startPointOffset(limits.x_end,  limits.x_st) );
  y_cent += abs( startPointOffset(limits.y_st, limits.y_end) );

  radius = std::max(xRad, yRad);
}

void Ellip::drawHelper(float inner) {
  // stretch circle into ellipse
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef(x_cent, y_cent, 0);

  // by ratio of major to minor axes
  glScalef(xRad / radius, yRad / radius, 1.0);
  GLUquadricObj *disk = gluNewQuadric();
  gluDisk(disk, inner, radius, int(radius), 1 );
  gluDeleteQuadric(disk);
  glLoadIdentity();
  glFlush();
}

void Ellip::draw() {
  calcHelper();

  // Call Filled function if filled ellipse is needed.
  if(filled)
    drawFilled();

  glColor3fv(borderColor);
  drawHelper(radius-2);
}

void Ellip::drawFilled() {
  glColor3fv(fillColor);
  drawHelper(0);
}

bool Ellip::contains(int x, int y) {
  calcHelper();

  float x_ele = (float(x)-x_cent) / xRad;
  float y_ele = (float(y)-y_cent) / yRad;

  // Square each value.
  x_ele *= x_ele, y_ele *= y_ele;

  // If sum of squares is within one, point is in ellipse.
  return x_ele + y_ele <= 1;
}
