#include "gui.h"
/***************************************************************************//**
 * @author Daniel Albl/Lindsay
 *
 * @brief draws palette and shapes 
 *
 ******************************************************************************/

Shapes * selectShape(Points limits, float * border, float * fill, char ch)
{
  switch (ch)
  {
    case 'r':
      return new Rect(limits,border,fill);
    case 'R':
      return new FilledRect(limits,border,fill); 
    case 'e':
      return new Ellip(limits,border,fill);    
    case 'E':
      return new FilledEllip(limits,border,fill);
    case 'l':
      return new Line(limits,border,fill);
    default:
      return nullptr;
  }
}
/***************************************************************************//**
 * @author Daniel Albl/Lindsay
 *
 * @brief pushes palette shapes onto the Q 
 *
 ******************************************************************************/

void drawPaletteShapes()
{
  Points limits;
    //dynamic size of palette squares
  int offset = getOffset(13);
  int indent_x = 0.10 * offset;
  int indent_y = 0.20 * offset;
  
  float border[4];
  float fill[4];
    //palette shapes are plum  
  std::memcpy(border, Color[16], 16);
  std::memcpy(fill, Color[16], 16);
    //hardcode in locations of shapes
  limits.x_st = indent_x;
  limits.y_st = convertY(offset * 10 + indent_y);
  limits.x_end = offset - indent_x;
  limits.y_end = convertY(offset + offset * 10 - indent_y);
   
  Shapes::palette.push_back( new Rect(limits, border, fill) );

  limits.y_st = convertY(offset * 11 + indent_y);
  limits.y_end = convertY(offset + offset * 11 - indent_y);
    
  Shapes::palette.push_back( new Ellip(limits, border, fill) );

  limits.y_st = convertY(offset * 12 + indent_y);
  limits.y_end = convertY(offset + offset * 12 - indent_y);
   
  Shapes::palette.push_back( new Line(limits, border, fill) );

  limits.x_st = offset + indent_x;
  limits.y_st = convertY(offset * 10 + indent_y);
  limits.x_end = offset * 2 - indent_x;
  limits.y_end = convertY(offset + offset * 10 - indent_y);
   
  Shapes::palette.push_back( new FilledRect(limits, border, fill) );

  limits.y_st = convertY(offset * 11 + indent_y);
  limits.y_end = convertY(offset + offset * 11 - indent_y);
    
  Shapes::palette.push_back( new FilledEllip(limits, border, fill) );

  limits.y_st = convertY(offset * 12 + indent_y);
  limits.y_end = convertY(offset + offset * 12 - indent_y);
    //draw the current selection in the last palette window
  Shapes::palette.push_back( selectShape(limits, CurrentSelection::current.border,
          CurrentSelection::current.fill, CurrentSelection::current.shape));
}
/***************************************************************************//**
 * @author Daniel Albl/Lindsay
 *
 * @brief pushes rectangles of appropriate color and location onto que 
 *
 ******************************************************************************/
void constructPalette()
{
  Points limits;
  float border[4];
  float fill[4];
  float offset = getOffset(13);
  float height = 0;
  //these will be put into shapes on the palette as identifiers
  char  shapeFlags[7] = "rReElX";
  int   count = 0;
  int   clr = 0;

  for(auto i : Shapes::palette)
     delete i;

  Shapes::palette.clear();
    //make border plum
  std::memcpy(border, Color[16], 16);
  for(int i = 0; i < 10; ++i)
    for(int j = 0; j < 2; ++j)
    {
        //size of squares dynamically changes
      limits.x_st = height + offset * j;
      limits.y_st = convertY(offset * i);
      limits.x_end = offset + offset * j;
      limits.y_end = convertY(offset + offset * i);
        //loop through color array
      std::memcpy(fill, Color[clr++], 16);
      Shapes::palette.push_back(new FilledRect(limits, border, fill));
    }
    //set fill to black
  std::memcpy(fill, Color[14], 16);

  for(int i = 10; i < 13; ++i)
    for(int j = 0; j < 2; ++j)
    {
      limits.x_st = height + offset * j;
      limits.y_st = convertY(offset * i);
      limits.x_end = offset + offset * j;
      limits.y_end = convertY(offset + offset * i);
      FilledRect *fr = new FilledRect(limits, border, fill);
        //these are for telling current selection what shape to make
      fr->shape = shapeFlags[count++]; 
      Shapes::palette.push_back(fr);
    }
}
/***************************************************************************//**
 * @author Daniel Albl/Lindsay
 *
 * @brief builds the palette boxes and shapes, and draws them 
 *
 ******************************************************************************/
void buildPalette()
{
  constructPalette();
  drawPaletteShapes();

  for (auto i : Shapes::palette)
    i->draw();
}
