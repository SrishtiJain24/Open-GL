#include <stdio.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <string.h>
#include <math.h>
float a,b,r;
int flag=0;
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
void draw(float x, float y) //plotting one point
{
		glPointSize(2.0f);
 		glBegin(GL_POINTS);
 		glVertex2d(x,y);
  	glEnd();
 		glFlush();
}
void parametric(float xc,float yc,float a, float b)
{
	float x,y;
	glColor3f(0,0,1);
	for(float t=0;t<=360;t++)
	{
		x=xc+a*cos(t);
		y=yc+b*sin(t);
		draw(x,y);
	}
}
void midcircle(float xc,float yc,float r)
{
  int x=0,y=r;
  int p = 5/4 - r;    
  glColor3f( 1,0,0); 
  while(x<=y)
  {
    draw(xc+x,yc+y);
    draw(xc+y,yc+x);  
    draw(xc-x,yc+y);
    draw(xc+y,yc-x);
    draw(xc-x,yc-y);
    draw(xc-y,yc-x);
    draw(xc+x,yc-y);
    draw(xc-y,yc+x);

    if (p<0)
      p=p+(2*x)+3;
    else
    {
    p=p+(2*(x-y))+5;
    y--;
    }
    x++;
  }
}
void midellipse(float xc,float yc,float a,float b)
{
    float x = 0, y = b, p;
    float px = 0, py = a*a*y;
  	glColor3f( 1,0,0);  
  	draw(xc+x,yc+y);   
    draw(xc+x,yc-y);
    draw(xc-x,yc-y);
    draw(xc-x,yc+y);
    p = b*b - (a*a*b) + (a*a/4);
    while (px < py)
    {
        x++;
        px = px + b*b;
        if (p < 0)
           	p = p + b*b + 2*px;
        else
        {
            y--;
            py = py - a*a;
            p = p + b*b + 2*px - 2*py;
        }
        draw(xc+x,yc+y);
        draw(xc+x,yc-y);
        draw(xc-x,yc-y);
        draw(xc-x,yc+y);
    }
    p = b*b*(x+0.5)*(x+0.5) + a*a*(y-1)*(y-1) - a*a*b*b;
    while (y > 0)
    {
        y--;
        py = py - a*a;
        if (p > 0)
            p = p + a*a - 2*py;
        else
        {
            x++;
            px = px + b*b;
            p = p + a*a - 2*py + 2*px;
        }
       	draw(xc+x,yc+y);
       	draw(xc+x,yc-y);
        draw(xc-x,yc-y);
        draw(xc-x,yc+y);
    }
}
/*void mouse(int button,int state, int xx, int yy)
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
}*/
void getdata()
{
  //printf("Drawing circle and ellipse using parametric and mid point method\n");
	//printf("Enter the value of a and b and r\n");
	//scanf("%f",&a);
	//scanf("%f",&b);
	//scanf("%f",&r);
  a=300;
  b=100;
  r=200;

}
/*void Reshape(GLsizei nWidth, GLsizei nHeight)
{
  int ww = glutGet(GLUT_WINDOW_WIDTH);
  int wh = glutGet(GLUT_WINDOW_HEIGHT);
  GLfloat aspect=ww/wh;
  GLfloat new_aspect = (float)nWidth / float(nHeight);
  if (aspect < new_aspect) 
     glViewport(0, 0, nHeight*aspect, nHeight);
  else if (aspect > new_aspect)
     glViewport(0, 0, nWidth, nWidth / aspect);
  else 
     glViewport(0, 0, nWidth, nHeight);
  //glMatrixMode(GL_PROJECTION);
  //glLoadIdentity();
  gluPerspective(60, (GLfloat)nWidth / (GLfloat)nHeight, 1.0, 100.0);
  glutPostRedisplay();
} 
void changeSize(int w, int h) 
{
	if(h <10)
		h = 10;
	
	glViewport(0, 0, (GLsizei)w, (GLsizei)h); 
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, (GLfloat)w / (GLfloat)h, 1.0, 100.0);
	glMatrixMode(GL_MODELVIEW);
}*/
void displayTL()
{	glClearColor(0.7f, 0.7f, 0.7f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	displayText(-480,440,1,1,1,"Srishti Jain");
	displayText(-480,360,1,1,1,"R134214070");
	displayText(-250,-450,1,1,1,"Circle: Parametric");
  
  parametric(0,0,r,r);
	glFlush();
}
void displayTR()
{ glClearColor(0.4f, 0.4f, 0.4f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
  displayText(-250,-450,1,1,1,"Ellipse: Parametric");
  parametric(0,0,a,b);
  glFlush();
}
void displayBL()
{ 
  glClearColor(0.4f, 0.4f, 0.4f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
  displayText(-250,-450,1,1,1,"Ellipse: Mid Point");
  midellipse(0,0,a,b);
  glFlush();
}
void displayBR()
{ glClearColor(0.7f, 0.7f, 0.7f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
  displayText(-250,-450,1,1,1,"Circle: Mid Point");
  midcircle(0,0,r); 
  glFlush();
}
int main(int argc, char **argv)
{
  getdata();
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(800,150);
  glutInitWindowSize(500,500);
  int mw=glutCreateWindow("Curves");

  int sub1=glutCreateSubWindow(mw,0,0,250,250 );
  gluOrtho2D(-500.0,500.0,-500.0,500.0);
  glutDisplayFunc(displayTL);
  
  int sub2=glutCreateSubWindow(mw,250,0,250,250 );
  gluOrtho2D(-500.0,500.0,-500.0,500.0);
  glutDisplayFunc(displayTR); 

  int sub3=glutCreateSubWindow(mw,0,250,250,250 );
  gluOrtho2D(-500.0,500.0,-500.0,500.0);
  glutDisplayFunc(displayBL);

  int sub4=glutCreateSubWindow(mw,250,250,250,250 );
  gluOrtho2D(-500.0,500.0,-500.0,500.0);
  glutDisplayFunc(displayBR);
  //glutReshapeFunc(Reshape);
  glutMainLoop();
  return 0;
}