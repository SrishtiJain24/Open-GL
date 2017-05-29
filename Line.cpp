#include <stdio.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <string.h>
int flag=0;  
int z=-1;
int xi,yi,xf,yf; 
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
void Keypress(unsigned char key, int x, int y) {

	if (key == 32) //space
	{
	glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	displayText(-480,460,1,1,1,"Srishti Jain");
	displayText(-480,420,1,1,1,"R134214070");
	displayText(-480,-450,0,0,0,"Press D for DDA, B for Bresenham, and Space for clear");
	displayText(-50,-480,0,1.0,0,"(green)");
	displayText(-300,-480,0,0,1.0,"(blue)");
	glFlush();
	}	
	if (key == 'd') //for dda
		z=1;
	if(key=='b') //for dda algorithm
		z=0;
}
void draw(float x, float y) //plotting one point
{
		glPointSize(2.0f);
 		glBegin(GL_POINTS);
 		glVertex2d(x,y);
  		glEnd();
 		glFlush();
}
void dLine(int ax, int ay, int bx, int by)
{
	glColor3f(0.0, 0.0, 1.0);
	int dx=bx-ax, dy=by-ay,mi,k;
	float xp,yp,x=ax,y=ay; 
	if(abs(dx)>abs(dy))
	mi=abs(dx); //total moves
	else mi=abs(dy);
	xp = dx /(float)mi;
	yp = dy / (float)mi;
	draw(x,y);
	for(k=0;k<mi;k++)
 	{
 		x=x+xp;
 		y=y+yp;
 		draw(x,y);
 	}
 		
}
void bLine(int ax, int ay, int bx, int by)
{
	glColor3f(0.0, 1.0, 0.0);
	int dx=abs(bx-ax), dy=abs(by-ay);
	float x,y,xl,yl;
	if(dx >= dy) //if slope is less than equal to 1
	{
		float p=2*dy-dx;
		//setting initial and final co-ordinates according to x
		if(ax>bx)
		{
			x=bx;	y=by;	xl=ax;	yl=ay;
		}
		else
		{
			x=ax;	y=ay;	xl=bx;	yl=by;
		}
		draw(x,y);
		while(x<xl)
		{
			x++;
			if(p<0)
				p=p+2*dy;
			else
			{
				if (y < yl) //when initial point is smaller
				{  
            		y++;
					p=p + (2*dy - 2*dx);
				}
				else //when initial point is larger
				{
					y--;
					p=p + (2*dy - 2*dx);
				}
			}
			draw(x,y);
		}
	}
	else //if slope is greater than 1
	{
		float p=2*dx-dy;
		if (ay < by)
		{
			x=ax;	y=ay;	xl=bx;	yl=by;
		}
		else
		{
			x=bx;	y=by;	xl=ax;	yl=ay;
		}
		draw(x,y);
		while(y<yl)
		{
			y++;
			if(p<0)
				p=p+2*dx;
			else
			{
				if (x < xl)
				{  
            		x++;
					p=p + (2*dx - 2*dy);
				}
				else
				{
					x--;
					p=p + (2*dx - 2*dy);
				}
			}
			draw(x,y);
		}
	}
}
void mouse(int button,int state, int xx, int yy)
{
	int x= xx*2-500;
	int y= yy*2-500;
	y=-y;
	if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)  
    {   
    	switch(flag)  
           {  
           case 0:  
                xi=x;  
                yi=y;  
                flag=1;  
                break;  
           case 1:  
               xf=x;  
               yf=y; 
               if(z==1) 
               	dLine(xi,yi,xf,yf);  
               if(z==0)
               	bLine(xi,yi,xf,yf);
               flag=0;  
               break;  
           } 
	}
}
void display()
{	glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	displayText(-480,460,1,1,1,"Srishti Jain");
	displayText(-480,420,1,1,1,"R134214070");
	displayText(-480,-450,0,0,0,"Press D for DDA, B for Bresenham, and Space for clear");
	displayText(-50,-480,0,1.0,0,"(green)");
	displayText(-300,-480,0,0,1.0,"(blue)");
	glLineWidth(2.5);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex2f(-150, 0.0);
	glVertex2f(150, 0);
	glEnd();
	glFlush();
}
int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(100,100);
  glutInitWindowSize(500,500);
  glutCreateWindow("DDA");
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-500.0,500.0,-500.0,500.0);
  glutDisplayFunc(display);
  glutKeyboardFunc(Keypress);
  glutMouseFunc(mouse);
  glutMainLoop();
  return 0;
}