//Q- Draw a hut in which circle changes color on mouse click.
#include <stdio.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <string.h>
#include <math.h>
float a=-0.687,b=0.2;//centre of left circle
float ar=0.687,br=0.2;//centre of right circle
float r=0.1;//radius 
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
void circle(float xc,float yc,float rc)
{
	float x,y;
	glBegin(GL_POLYGON);
	for(float t=0;t<=360;t++)
	{
		x=xc+(rc)*cos(t);
		y=yc+(rc)*sin(t);
		glVertex2f(x,y);
	}
	glEnd();
}
void figure()
{
//outer rectangle	
	glColor3f(1,0,0.3);	
	glBegin(GL_POLYGON);
	glVertex2d(-0.95,-0.85);
	glVertex2d(0.95,-0.85);
	glVertex2d(0.95,0.05);
	glVertex2d(-0.95,0.05);
	glEnd();
//inner-left rect	
	glColor3f(0,1,1);	
	glBegin(GL_POLYGON);
	glVertex2d(-0.95,-0.65);
	glVertex2d(-0.75,-0.65);
	glVertex2d(-0.75,-0.25);
	glVertex2d(-0.95,-0.25);
	glEnd();
//inner-right rect	
	glBegin(GL_POLYGON);
	glVertex2d(0.95,-0.65);
	glVertex2d(0.75,-0.65);
	glVertex2d(0.75,-0.25);
	glVertex2d(0.95,-0.25);
	glEnd();
//centre rectangle	
	glColor3f(1,0,1);	
	glBegin(GL_POLYGON);
	glVertex2d(-0.45,-0.35);
	glVertex2d(0.45,-0.35);
	glVertex2d(0.45,0.05);
	glVertex2d(-0.45,0.05);
	glEnd();
//inner rectangle	
	glColor3f(1,1,0);
	glBegin(GL_POLYGON);
	glVertex2d(-0.25,-0.25);
	glVertex2d(0.25,-0.25);
	glVertex2d(0.25,-0.05);
	glVertex2d(-0.25,-0.05);
	glEnd();
//Left triangle	
	glColor3f(1,1,0);
	glBegin(GL_POLYGON);
	glVertex2d(-0.95,0.05);
	glVertex2d(-0.45,0.05);
	glVertex2d(-0.689,0.45);
	glEnd();
//Right triangle	
	glColor3f(1,1,0);
	glBegin(GL_POLYGON);
	glVertex2d(0.95,0.05);
	glVertex2d(0.45,0.05);
	glVertex2d(0.689,0.45);
	glEnd();
//Centre triangle
	glColor3f(0,1,1);
	glBegin(GL_POLYGON);
	glVertex2d(-0.25,0.05);
	glVertex2d(0.25,0.05);
	glVertex2d(0.0,0.3);
	glEnd();	
}
void display()
{	glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	displayText(-0.95f,0.85f,1,1,1,"Srishti Jain");
	displayText(-0.95f,0.75f,1,1,1,"R134214070");
	displayText(-0.05f,-0.92f,1,1,1,"HUT");
//hut
	figure();
//left circle
	glColor3f(0,0.6,0);
	circle(a,b,r);
//right circle
	glColor3f(0.4,0,0.4);
	circle(ar,br,r);

	glFlush();
}



void mouse(int button,int state, int x, int y)
{
	float lx= ((float(x))/600)*2-1;
	float ly= ((float(y))/600)*2-1;
	ly=-ly;
	switch(button)
	{
		case GLUT_LEFT_BUTTON:
		{
		float d = (lx-a)*(lx-a)+(ly-b)*(ly-b)-(r*r);
		float dr = (lx-ar)*(lx-ar)+(ly-br)*(ly-br)-(r*r);	
			if(d<0 && state==GLUT_DOWN)
			{
		//clicked inside left circle
			glColor3f(0.4,0,0.4);
			circle(a,b,r);
			glFlush();
			}
			if(dr<0 && state==GLUT_DOWN)
			{
		//clicked inside right circle
			glColor3f(0,0.6,0);
			circle(ar,br,r);	
			glFlush();
			}
		}	
		break;
		case GLUT_RIGHT_BUTTON:
		{
		//reset to original figure.	
			glutPostRedisplay();
		}
		break;		
	}
}
int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(0,0);
  glutInitWindowSize(600,600);
  glutCreateWindow("hut");
  glutDisplayFunc(display);
  glutMouseFunc(mouse);
  glutMainLoop();
  return 0;
}
