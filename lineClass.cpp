#include "lineClass.h"

void Line::draw() {
  glLineWidth(2);
  glColor3fv(borderColor);
  glBegin(GL_LINES);
  glVertex2f(limits.x_st, limits.y_st);
  glVertex2f(limits.x_end, limits.y_end);
  glEnd();
}

bool Line::contains(int x, int y) {
  double x_min = double(std::min(limits.x_st, limits.x_end));
  double y_min = double(std::min(limits.y_st, limits.y_end));
  double x_max = double(std::max(limits.x_st, limits.x_end));
  double y_max = double(std::max(limits.y_st, limits.y_end));

  double m = (y_max-y_min)/(x_max-x_min);
  double b = limits.y_st - m*limits.x_st;

  if(x > x_max   + 30) return false;
  if(x < x_min   - 30) return false;
  if(y < y_min   - 30) return false;
  if(y > y_max   + 30) return false;
  if(y > m*x + b + 30) return false;
  if(y < m*x + b - 30) return false;

  return true;
}

void Line::drawFilled() {}
