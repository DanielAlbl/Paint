#include "event.h"
/***************************************************************************//**
 * @author Daniel Albl/Lindsay
 * @brief calls keyboard functions  
 *
 * @param[in] key - keyboard button
 * @param[in] x - screen x coordinate
 * @param[in] y - screen y coordinate
 *  
 ******************************************************************************/
void keyboard(unsigned char key, int x, int y)
{
  // Quit glut on Escape.
  QuitOnEsc(key);
  
  // Clear on c key.
  ClearOnC(key);

  // removeLastItem(key);
  deleteLastShape(key);
}
/***************************************************************************//**
 * @author Daniel Albl/Lindsay
 *
 * @brief calls mouse functions  
 *
 * @param[in] button - mouse button
 * @param[in] state - up or down click
 * @param[in] x - screen x coordinate
 * @param[in] y - screen y coordinate
 *  
 ******************************************************************************/
void mouse(int button, int state, int x, int y)
{
  // Convert 'y' once for whole function.
  y = convertY(y);
  //select colors/shapes if click in palette
  colorPaletteClick(x,y, button);
  //left click draws
  if( button == GLUT_LEFT_BUTTON )
  {
    //store start points
    if( state == GLUT_DOWN )
    {
      CurrentSelection::current.limits.x_st = x;
      CurrentSelection::current.limits.y_st = y;
    }
	else if( state == GLUT_UP )
    {
        //store endpoints
       CurrentSelection::current.limits.x_end = x;
       CurrentSelection::current.limits.y_end = y;
       //push new shape onto list
       Shapes::printQue.push_back( selectShape(CurrentSelection::current.limits, 
         CurrentSelection::current.border, CurrentSelection::current.fill,
         CurrentSelection::current.shape));
       drawDisplay();
    }
  }
  //right click moves
  else if( button == GLUT_RIGHT_BUTTON )
  {
    if( state == GLUT_DOWN )
    {
      for (auto i : Shapes::printQue)
        if( i->contains(x,y))
        {
            //store start points 
          CurrentSelection::currentMove.x = x;
          CurrentSelection::currentMove.y = y;
           //and pointer to shape to be moved
          CurrentSelection::currentMove.shape = i;
        }
    }
	else if ( state == GLUT_UP )
    {
        //if corresponding down click was not in a shape
      if( CurrentSelection::currentMove.x == -1 )
        return;
     
      int x_dist = x - CurrentSelection::currentMove.x;
      int y_dist = y - CurrentSelection::currentMove.y;
      
      Shapes::printQue.remove(CurrentSelection::currentMove.shape);
      //basically vector addition
      CurrentSelection::currentMove.shape->limits.x_st  += x_dist;
      CurrentSelection::currentMove.shape->limits.x_end += x_dist;
      CurrentSelection::currentMove.shape->limits.y_st  += y_dist;
      CurrentSelection::currentMove.shape->limits.y_end += y_dist;

      Shapes::printQue.push_back(CurrentSelection::currentMove.shape);
      //essentially undo moving object flag
      CurrentSelection::currentMove.x = -1;
      
      drawDisplay(); 
    } 
  }
}

/***************************************************************************//**
 * @author Daniel Albl/Lindsay
 *
 * @brief if click is in the palette 
 *
 * @param[in] button - mouse button
 * @param[in] state - up or down click
 * @param[in] x - screen x coordinate
 * @param[in] y - screen y coordinate
 *  
 * @returns true - click is in palette
 * @returns flase - not in palette
 ******************************************************************************/
bool colorPaletteClick( int x, int y, int button)
{
  //loop through drawn shapes
  for ( auto i : Shapes::palette )
  {
    if ( i->contains(x,y) )
    {
  	  //if preview window
  	if( i->shape == 'X' )
  	  return true;
  	if(button == GLUT_LEFT_BUTTON) {
        //if a color window
  	  if (! i->shape)
        std::memcpy( CurrentSelection::current.fill, i->fillColor, 16);
  		//if shape window
	  else
  	    CurrentSelection::current.shape = i->shape;
  	}
  	else if(button == GLUT_RIGHT_BUTTON and !i->shape)
  	  std::memcpy( CurrentSelection::current.border, i->fillColor, 16);
  		   
  	drawDisplay();
  	return true;
    }
  }
  return false;
}

/***************************************************************************//**
 * @author Daniel Albl/Lindsay
 *
 * @brief quits program 
 *
 * @param[in] key - keyboard key
 *
 ******************************************************************************/
void QuitOnEsc(unsigned char key)
{
  if(key == Esc || key == int('q'))
    {
       glutLeaveMainLoop();

        for (auto i : Shapes::palette )
            delete i;
        for (auto i : Shapes::printQue )
            delete i;
        //get out to avoid seg fault
        exit(0);      
    }
}
/***************************************************************************//**
 * @author Daniel Albl/Lindsay
 *
 * @brief clears screen
 *
 * @param[in] key - keyboard button
 *
 ******************************************************************************/
void ClearOnC(unsigned char key)
{
  if(key == int('c'))
    clearScreen();
}

/***************************************************************************//**
 * @author Daniel Albl/Lindsay
 *
 * @brief deletes last shape on the que 
 *
 * @param[in] key - keyboard button
 *  
 ******************************************************************************/
void deleteLastShape(unsigned char key)
{
  if(key == int('d'))
  {
     if( Shapes::printQue.empty() )
       return;
     delete Shapes::printQue.back();
     Shapes::printQue.pop_back();
     drawDisplay();
  }
}

