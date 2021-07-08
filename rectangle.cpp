#include "rectangle.h"

void Rect::setVertices() {
  glVertex2f(limits.x_st, limits.y_st);
  glVertex2f(limits.x_end, limits.y_st);
  glVertex2f(limits.x_end, limits.y_end);
  glVertex2f(limits.x_st, limits.y_end);
}

void Rect::draw() {
  if(filled)
    drawFilled();

  glLineWidth(2);
  glColor3fv(borderColor);
  glBegin(GL_LINE_LOOP);
  setVertices();
  glEnd();
}

void Rect::drawFilled() {
  glColor3fv(fillColor);
  glBegin(GL_POLYGON);
  setVertices();
  glEnd();
}


bool Rect::contains( int x, int y) {
  if(x < std::min(limits.x_st, limits.x_end)) return false;
  if(x > std::max(limits.x_st, limits.x_end)) return false;
  if(y < std::min(limits.y_st, limits.y_end)) return false;
  if(y > std::max(limits.y_st, limits.y_end)) return false;

  return true;
}

