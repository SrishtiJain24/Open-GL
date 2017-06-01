#include <GL/glut.h>
#include <string.h>
#include <stdio.h>
#include <GL/glu.h>
#include <GL/gl.h>
int count=0, x1=0, y1=0, y2=0, x2=0;
bool flag=true;
double xmin=300,ymin=300,xmax=500,ymax=500;
double xvmin=300,yvmin=300,xvmax=500,yvmax=500;
int xo2,yo2,x3,y3;

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

int test(float p,float q,float *t1,float *t2)
{
    float t=q/p;
    if(p<0.0)
    {
        if(t> *t1) *t1=t;
        if(t> *t2) return(false);
    }
    else if(p>0.0)
    {
        if(t< *t2) *t2=t;
        if(t< *t1) return(false);
    }
    else if(p==0.0)
    {
        if(q<0.0) return(false);
    }
    return(true);
}

void LiangBarsky(float x0,float y0,float x1,float y1)
{
  glBegin(GL_LINES);//Drawing orignal Line:RED
  glColor3f(0.8,0.2,0.2);
  glVertex2f(xo2,yo2);
  glVertex2f(x3,y3);
  glEnd();
  glFinish();
  float dx=x3-xo2,dy=y3-yo2,te=0.0,tl=1.0;
  if(test(-dx,xo2-xmin,&te,&tl))
    if(test(dx,xmax-xo2,&te,&tl))
    if(test(-dy,yo2-ymin,&te,&tl))
    if(test(dy,ymax-yo2,&te,&tl))
    {
        if(tl<1.0){x3=xo2+tl*dx;y3=yo2+tl*dy;}
        if(te>0.0){xo2=xo2+te*dx;yo2=yo2+te*dy;}
        float sx=(xvmax-xvmin)/(xmax-xmin);
        float sy=(yvmax-yvmin)/(ymax-ymin);
        float vx0=xvmin+(xo2-xmin)*sx;
        float vy0=yvmin+(yo2-ymin)*sy;
        float vx1=xvmin+(x3-xmin)*sx;
        float vy1=yvmin+(y3-ymin)*sy;
        glBegin(GL_LINES);
        glColor3f(1.0,1.0,1.0);
        glVertex2d(vx0,vy0);
        glVertex2d(vx1,vy1);
        glEnd();
        glFinish();
     }
}
void clipLine (float x1, float y1, float x2, float y2)
{
  float m = (y2-y1)/(x2-x1);
  glBegin(GL_LINES);//Drawing orignal Line:RED
  glColor3f(0.8,0.2,0.2);
  glVertex2f(x1,y1);
  glVertex2f(x2,y2);
  glEnd();
  glFinish();
  if(x1<10)
  {
    x1=10;
    y1=y2-(m*(x2-x1));
  }
  if(x2<10)
  {
    x2=10;
    y2=(m*(x2-x1))+y1;
  }
  if(y1<10)
  {
    y1=10;
    x1=x2-((1/m)*(y2-y1));
  }
  if(y2<10)
  {
    y2=10;
    x2=((1/m)*(y2-y1))+x1;
  }
  if(x1>250)
  {
    x1=250;
    y1=y2-(m*(x2-x1));
  }
  if(x2>250)
  {
    x2=250;
    y2=(m*(x2-x1))+y1;
  }
  if(y1>250)
  {
    y1=250;
    x1=x2-((1/m)*(y2-y1));
  }
  if(y2>250)
  {
    y2=250;
    x2=((1/m)*(y2-y1))+x1;
  }
  glBegin(GL_LINES);//Drawing clipped Line
  glColor3f(0.2,0.2,0.8);
  glVertex2f(x1,y1);
  glVertex2f(x2,y2);
  glEnd();
  glFinish();
}
void mymouse(int button, int state, int x, int y)
{
  if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
  {
    if (flag==true)//Setting Values for First click
    {
      x1=x;
      xo2=x;
      y1=y;
      yo2=y;
      flag=false;
      count++;
    }
    else//Setting Values for Second click
    {
      x2=x;
      x3=x;
      y2=y;
      y3=y;
      flag =true;
      count++;
    }
    if(count==2)// Making Sure that it is clicked twice
    {
      printf("Inside count of click\n");

      LiangBarsky(xo2,yo2,x3,y3);// Passing the coordinates to draw lines
      clipLine(x1,y1,x2,y2);
      count=0;
    }

  }
}

void display()
{
  //clearing Screen
glClearColor(0.5, 0.5, 0.5, 1);
glClear(GL_COLOR_BUFFER_BIT);  
displayText(50,460,1,1,1,"Srishti Jain");
	displayText(50,480,1,1,1,"R134214070");
displayText(50,500,1,1,1,"Line Clipping");
glBegin(GL_LINE_LOOP);//making a square
  glColor3f(0.2,0.8,0.2);//Nearly green colour
  glVertex2f(10,10);
  glVertex2f(250,10);
  glVertex2f(250,250);
  glVertex2f(10,250);
  glEnd();
  glColor3f(1.0,0.0,0.0);
  glBegin(GL_LINE_LOOP);
  glVertex2f(xvmin,yvmin);
  glVertex2f(xvmax,yvmin);
  glVertex2f(xvmax,yvmax);
  glVertex2f(xvmin,yvmax);
  glEnd();
  glFlush();
}

int main(int argc, char** argv)
{
glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(80, 80);
  glutInitWindowSize(600, 600);
  glutCreateWindow("Multiple Clipping");
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0,600,600,0);
  glutDisplayFunc(display);
  glutMouseFunc(mymouse);
  glutMainLoop();
}
