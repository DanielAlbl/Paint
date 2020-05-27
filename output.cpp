#include "output.h"
#include <iostream>

// Initilze glut window.
void initOpenGL(int argc, char** argv, int length, int height)
{
  glutInit(&argc, argv);

  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
  
  glutInitWindowSize(length, height);
  glutInitWindowPosition(length / 4, height + 50);
  glutCreateWindow(argv[0]);
  glClearColor(Color[Black][R], Color[Black][G], Color[Black][B], Color[Black][A]);
  glutDisplayFunc(drawDisplay);
  clearScreen();
  glutReshapeFunc(reshapeWindow);

  glutKeyboardFunc(keyboard);
  glutMouseFunc(mouse);
}

void clearScreen()
{
  glClear(GL_COLOR_BUFFER_BIT);
  for ( auto i : Shapes::printQue )
      delete i;
  Shapes::printQue.clear();
  buildPalette();
  glutSwapBuffers();
}

void redraw()
{
  for(auto i : Shapes::printQue)
    i->draw();
}

void reshapeWindow(const int w, const int h)
{
  glMatrixMode( GL_PROJECTION );      // use an orthographic projection
  glLoadIdentity();                   // initialize transformation matrix
  gluOrtho2D( 0.0, w, 0.0, h );       // make OpenGL coordinates
  glViewport( 0, 0, w, h );           // the same as the screen coordinates
}

void drawDisplay()
{
  glClear(GL_COLOR_BUFFER_BIT);

  buildPalette();
  redraw();

  glutSwapBuffers();  
}

void drawSquare(float x1, float y1, float x2, float y2, const float color[])
{
  glColor3fv(color);
  glBegin(GL_POLYGON);
    glVertex2f(x1, y1);
    glVertex2f(x2, y1);
    glVertex2f(x2, y2);
    glVertex2f(x1, y2);
  glEnd();
}

void drawBox(float x1, float y1, float x2, float y2, const float color[])
{
  glLineWidth(2);
  glColor3fv(color);
  glBegin(GL_LINE_LOOP);
    glVertex2f(x1, y1);
    glVertex2f(x2, y1);
    glVertex2f(x2, y2);
    glVertex2f(x1, y2);
  glEnd();
}
