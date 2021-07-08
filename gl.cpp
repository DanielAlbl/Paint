#include "gl.h"

// Initilze glut window.
void initOpenGL(int argc, char** argv, int length, int height) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

  glutInitWindowSize(length, height);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("Paint");
  glClearColor(Color[Black][R], Color[Black][G], Color[Black][B], Color[Black][A]);

  glutDisplayFunc(drawDisplay);
  glutReshapeFunc(reshapeWindow);
  glutKeyboardFunc(keyboard);
  glutMouseFunc(mouse);

  clearScreen();
}

void clearScreen() {
  glClear(GL_COLOR_BUFFER_BIT);
  for(auto i : Shapes::printQue)
    delete i;
  Shapes::printQue.clear();
  buildPalette();
  glutSwapBuffers();
}

void redraw() {
  for(auto i : Shapes::printQue)
    i->draw();
}

void reshapeWindow(const int w, const int h) {
  glMatrixMode(GL_PROJECTION);      // use an orthographic projection
  glLoadIdentity();                 // initialize transformation matrix
  gluOrtho2D( 0.0, w, 0.0, h );     // make OpenGL coordinates
  glViewport( 0, 0, w, h );         // the same as the screen coordinates
}

void drawDisplay() {
  glClear(GL_COLOR_BUFFER_BIT);

  redraw();
  buildPalette();

  glutSwapBuffers();
}
