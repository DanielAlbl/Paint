/***************************************************************************//**
 * @file
 *
 * @mainpage Encapsulation example
 *
 * @author Daniel Albil, Daniel Lindsay
 *
 * @date Feb 12, 2019
 *
 * @par Instructor:
 *      Dr. Hinker
 *
 * @par Course:
 *      CSC 315 - Data Structures - 10:00am
 *
 * @par Location:
 *      McLaury Building, Room 315
 *
 * @par Description:
 *      This program allows the user to draw rectangles, ellipses and lines,
 *      both filled and unfilled. Each shape can be drawn in any combination of
 *      colors displayed in the color palette by selecting the color and shape
 *      with the left mouse button, then dragging on the black field. Upon
 *      release, the shape will be created. Once the shapes have been created,
 *      the user can move them using the right mouse button in the same way the
 *      shape was created. By pressing ‘d’ the top shape will be deleted, and
 *      ‘c’ clears the entire screen. Both ‘q’ and Esc will exit the program
 *      and any other key will redraw the entire screen. This program is
 *      dependent on FreeGlut for graphical support and requires related library’s.
 *
 * @section todo_bugs_modification_section Todo, Bugs, and Modifications
 *      Program leaks memory due to dynamic allication not being fully cleaned
 *      up..
 *
 ******************************************************************************/

#include "gl.h"

/***************************************************************************//**
 * @brief main function
 *
 * @param[in] argc - Command line argument count
 * @param[in] argv - Command line argument values stored in c string array.
 *
 * @return main does not return due to glutMainLoop having no return.
 ******************************************************************************/
int main(int argc, char** argv) {
  // Open window with inital settings.
  initOpenGL(argc, argv, 800, 600);

  // Enter glut main loop and leave main.
  glutMainLoop();

  // Exit w/o errors.
  return 0;
}
