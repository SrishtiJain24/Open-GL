# include <cstdlib>
# include <iostream>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <string.h>
using namespace std;

typedef GLfloat point2[2];
GLfloat sc;
void displayText( float x, float y, int r, int g, int b, const char *string )
{
  int j = strlen( string );
  glColor3f( r, g, b );
  glRasterPos2f( x, y );
  for( int i = 0; i<j; i++ ) 
    {
    glutBitmapCharacter( GLUT_BITMAP_HELVETICA_18 , string[i] );
    }
}

void display ( )
{
  int i;
  point2 p;
  int num = 900000;
  double mat[4] = { 0.85, 0.92, 0.97, 0.00 };
  double r;
  double x;
  double y;

  glClear ( GL_COLOR_BUFFER_BIT );
  displayText(-3.8,-0.25,1,1,1,"Srishti Jain");
  displayText(-3.8,-0.67,1,1,1,"R134214070");
  displayText(-3.8,10.0,1,1,1,"Fractal");
   p[0] = drand48 ( );
  p[1] = drand48 ( );

for ( i = 0; i < num; i++ )
{
r = drand48( );
if ( r < mat[0] ){
x =   0.85 * p[0] - 0.00 * p[1] + 0.0;
y = - 0.04 * p[0] + 0.85 * p[1] + 1.6;
}
else if ( r < mat[1] ){
x =   0.20 * p[0] - 0.26 * p[1] + 0.0;
y =   0.23 * p[0] + 0.22 * p[1] + 1.6;
}
else if ( r < mat[2] ){
x = - 0.15 * p[0] + 0.28 * p[1] + 0.0;
y =   0.26 * p[0] + 0.24 * p[1] + 0.44;
}
else {
x =   0.0 * p[0] + 0.00 * p[1] + 0.0;
y =   0.0 * p[0] + 0.26 * p[1] + 0.0;
glColor3f ( 0.0, 0.4, 0.12 );
}
p[0] = x;
p[1] = y;
glBegin ( GL_POINTS );
glVertex2fv ( p );
glEnd ( );
}
//  ;glColor3f(0.64f, 0.46, 0.16f); Light Brown
glColor3f(0.64f, 0.26, 0.16f) ; 
glBegin(GL_POLYGON);
glVertex2f(0.95,0.45);
glVertex2f(-0.95,0.45);
glVertex2f(-0.4,-0.95);
glVertex2f(0.4,-0.95);
glEnd();
glFlush ( );
return;
}
void Keypress(unsigned char key,int x, int y){
  if(key==43)
  {
  	sc=1.25;
  	glScalef(sc,sc,sc);
  	glutPostRedisplay();
  }
  if(key==45)
  {
  	sc=0.8;
  	glScalef(sc,sc,sc);
  	glutPostRedisplay();
  }

}

void myinit ( )
{
  glClearColor ( 0.5, 0.5, 0.5, 1.0 );
  //glColor3f(0.64f, 0.46, 0.16f);
  glMatrixMode ( GL_PROJECTION );
  glLoadIdentity ( );
  gluOrtho2D ( -4.0, 4.0, -1.0, 11.0 );
  glMatrixMode ( GL_MODELVIEW );

  return;
}

int main ( int argc, char *argv[] )
{
  glutInit ( &argc, argv );
  glutInitDisplayMode ( GLUT_SINGLE | GLUT_RGB );
  glutInitWindowSize ( 500, 600 );
  glutInitWindowPosition ( 500, 50 );
  glutCreateWindow ( "Fractal" );
  glutDisplayFunc ( display );
  myinit ( );
glutKeyboardFunc(Keypress);
  glutMainLoop ( );
  return 0;
}
