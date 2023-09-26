/* ND4 */
#include <stdio.h>
#include <stdlib.h>
#include "PCX.h"
#include <glut.h>

#define FRAME_H 1000
#define FRAME_W 2000

byte Frame[FRAME_H][FRAME_W][3];
int Zoom = 1;

void PutPixel( int x, int y, int r, int g, int b )
{
  if (x < 0 || y < 0 || x >= FRAME_W || y >= FRAME_H)
    return;
  Frame[y][x][0] = b;
  Frame[y][x][1] = g;
  Frame[y][x][2] = r;
}

void Keyboard( unsigned char Key, int X, int Y )
{
  if (Key == 27)
    exit(0);
  else if (Key == '-')
    Zoom--;
  else if (Key == '+')
    Zoom++;
  else if (Key == '1')
    DrawPCX("m.PCX", X / Zoom, Y / Zoom);
  else if (Key == '2')
    DrawPCX("LOGO30.PCX", X / Zoom, Y / Zoom);
  else if (Key == '3')
    DrawPCX("ROSE.PCX", X /  Zoom, Y / Zoom);
  else if (Key == '4')
    DrawPCX("A3.PCX", X /  Zoom, Y / Zoom);
  else if (Key == ' ')
    PutPixel(X / Zoom, Y / Zoom, 225, 229, 180);
} 

void Display( void )
{
  glClearColor(0.3, 0.5, 0.7, 1);
  glClear(GL_COLOR_BUFFER_BIT);

  glRasterPos2d(-1, 1);
  glPixelZoom(Zoom, -Zoom);
  glDrawPixels(FRAME_W, FRAME_H, GL_BGR_EXT, GL_UNSIGNED_BYTE, Frame);

  glFinish();

  glutSwapBuffers();
  glutPostRedisplay();
}

void main ( int ArgC, char *Argv[] )
{

  glutInit(&ArgC, Argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

  glutInitWindowPosition(0, 0);
  glutInitWindowSize(1920, 1080);
  glutCreateWindow("ND4 T19PCX");
  glutFullScreen();

  glutDisplayFunc(Display);
  glutKeyboardFunc(Keyboard);

  glClearColor(0.3, 0.5, 0.7, 1);
  glutMainLoop();
} 
   /*
void main( void )
{
  char fname[100];

  printf("What fle do u wanna open? ");
  GetStr(fname, 100);

  DrawPCX("ROSE.PCX");
  getchar();
} */