/*************************************************************************//**
* @file
* @brief
*****************************************************************************/
#ifndef FILLEDRECTANGLE
#define FILLEDRECTANGLE

#include "rectangle.h"

class FilledRect : public Rect {
public:
  FilledRect(Points limits, float * borderColor, float * fillColor) :
    Rect(limits, borderColor, fillColor) {
    filled = true;
  }
  static std::list<FilledRect*> palette;
};

#endif
