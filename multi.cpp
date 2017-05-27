//Q- Draw a triangle with different colors.
#include <stdio.h>
#include <GL/glut.h>
#include<GL/glu.h>
#include <GL/gl.h>
#include<string.h>
void displayText( float x, float y, int r, int g, int b, const char *string )
{
	int j = strlen( string );
	glColor3f( r, g, b );
	glRasterPos2f( x, y );
	for( int i = 0; i<j; i++ ) 
		{
		glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24, string[i] );
		}
}
void display()
{
	glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	displayText(-0.85f,0.85f,1,1,1,"Srishti Jain");
		displayText(-0.35f,- 0.9f,1,1,1,"Multicolored Triangle");
	glBegin(GL_POLYGON);
	glColor3f(0,1,0);
	glVertex2d(-0.5,-0.5);
	glColor3f(1,0,0);
	glVertex2d(0.5,-0.5);
	glColor3f(0,0,1);
	glVertex2d(0.0,0.2);
	glEnd();
	glFlush();
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(0,0);
  glutInitWindowSize(500,500);
  glutCreateWindow("Triangle");
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}
