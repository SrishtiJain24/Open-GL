#include <GL/glut.h>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <math.h>

float OrignalCube [8][4]={{-90,50,20,1},{90,50,20,1},{90,50,-20,1},{-90,50,-20,1},{-90,-50,20,1},{90,-50,20,1},{90,-50,-20,1},{-90,-50,-20,1}};
float tx=0, ty=0, tz=0;
float Sx = 0, Sy=0, Sz;
float qx,qy,qz;


void drawCube(float Cube[8][4])
{
  glClear(GL_COLOR_BUFFER_BIT);
  glClearColor(0.5,0.5,0.5,1);

  glBegin(GL_QUADS);//drawing the cube

  glColor3f(0,1,0);
  glVertex3f(Cube[3][0],Cube[3][1],Cube[3][2]);//back surface
  glVertex3f(Cube[2][0],Cube[2][1],Cube[2][2]);
  glVertex3f(Cube[6][0],Cube[6][1],Cube[6][2]);
  glVertex3f(Cube[7][0],Cube[7][1],Cube[7][2]);

  glColor3f(0,1,1);
  glVertex3f(Cube[4][0],Cube[4][1],Cube[4][2]);//bottom surface
  glVertex3f(Cube[5][0],Cube[5][1],Cube[5][2]);
  glVertex3f(Cube[6][0],Cube[6][1],Cube[6][2]);
  glVertex3f(Cube[7][0],Cube[7][1],Cube[7][2]);

  glColor3f(1,1,0);
  glVertex3f(Cube[0][0],Cube[0][1],Cube[0][2]);//left surface
  glVertex3f(Cube[4][0],Cube[4][1],Cube[4][2]);
  glVertex3f(Cube[7][0],Cube[7][1],Cube[7][2]);
  glVertex3f(Cube[3][0],Cube[3][1],Cube[3][2]);

  glColor3f(1,0,1);
  glVertex3f(Cube[0][0],Cube[0][1],Cube[0][2]);//front surface
  glVertex3f(Cube[1][0],Cube[1][1],Cube[1][2]);
  glVertex3f(Cube[5][0],Cube[5][1],Cube[5][2]);
  glVertex3f(Cube[4][0],Cube[4][1],Cube[4][2]);

  glColor3f(1,0,0);
  glVertex3f(Cube[0][0],Cube[0][1],Cube[0][2]);//top surface
  glVertex3f(Cube[1][0],Cube[1][1],Cube[1][2]);
  glVertex3f(Cube[2][0],Cube[2][1],Cube[2][2]);
  glVertex3f(Cube[3][0],Cube[3][1],Cube[3][2]);


  glColor3f(0,0,0);
  glVertex3f(Cube[1][0],Cube[1][1],Cube[1][2]);//right surface
  glVertex3f(Cube[5][0],Cube[5][1],Cube[5][2]);
  glVertex3f(Cube[6][0],Cube[6][1],Cube[6][2]);
  glVertex3f(Cube[2][0],Cube[2][1],Cube[2][2]);


  glEnd();
  glFlush();
}

void mul(float a[][4], float b[][4], float c[][4]){
	int i,j,k;
	float sum;
	for (i = 0; i <1; i++) {
      for (j = 0; j < 4; j++) {
         sum = 0;
         for (k = 0; k < 4; k++) {
            sum = sum + a[i][k] * b[k][j];
         }
         c[i][j] = sum;
      }
   }
}

void trans(){
	float mulmatrix[][4] = {{1,0,0,0},{0,1,0,0},{0,0,1,0},{tx,ty,tz,1}};
	float resmatrix[][4] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
	for(int i = 0; i< 8; i++)
		mul(OrignalCube+i,mulmatrix,resmatrix+i);
		drawCube(resmatrix);
		for(int i = 0; i< 8; i++){
		for(int j=0;j<4;j++){
			OrignalCube[i][j] = resmatrix[i][j];
		}
	}
}

void scale(){
	float mulmatrix[][4] = {{Sx,0,0,0},{0,Sy,0,0},{0,0,Sz,0},{0,0,0,1}};
	float resmatrix[][4] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
	for(int i = 0; i< 8; i++)
		mul(OrignalCube+i,mulmatrix,resmatrix+i);
		drawCube(resmatrix);
		for(int i = 0; i< 8; i++){
		for(int j=0;j<4;j++){
			OrignalCube[i][j] = resmatrix[i][j];
		}
	}
}

void rotx(){
	float mulmatrix[][4] = {{1,0,0,0},{0,cos(qx),-sin(qx),0},{0,sin(qx),cos(qx),0},{0,0,0,1}};
	float resmatrix[][4] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
	for(int i = 0; i< 8; i++)
		mul(OrignalCube+i,mulmatrix,resmatrix+i);
		drawCube(resmatrix);
		for(int i = 0; i< 8; i++){
		for(int j=0;j<4;j++){
			OrignalCube[i][j] = resmatrix[i][j];
		}
	}
}

void roty(){
	float mulmatrix[][4] = {{cos(qy),0,sin(qy),0},{0,1,0,0},{-sin(qy),0,cos(qy),0},{0,0,0,1}};
	float resmatrix[][4] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
	for(int i = 0; i< 8; i++)
		mul(OrignalCube+i,mulmatrix,resmatrix+i);
		drawCube(resmatrix);
		for(int i = 0; i< 8; i++){
		for(int j=0;j<4;j++){
			OrignalCube[i][j] = resmatrix[i][j];
		}
	}
}

void rotz(){
	float mulmatrix[][4] = {{cos(qz),-sin(qz),0,0},{sin(qz),cos(qz),0,0},{0,0,1,0},{0,0,0,1}};
	float resmatrix[][4] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
	for(int i = 0; i< 8; i++)
		mul(OrignalCube+i,mulmatrix,resmatrix+i);
	drawCube(resmatrix);
	for(int i = 0; i< 8; i++){
	for(int j=0;j<4;j++){
		OrignalCube[i][j] = resmatrix[i][j];
		}
	}
}

void myKey(unsigned char key, int x, int y)
{
	if(key == 119) // key is W for Up Translation
    {	
    	ty = ty + 10;
    	trans();
    	ty = 0;
    }
    if (key==97)//move left with 'a'
    {
    	tx = tx - 10;
    	trans();
    	tx = 0;

    }
    else if (key==100)//move right with 'd'
  	{
  		tx = tx+10;
  		trans();
		tx = 0;
  	}
  	else if (key==115)//move down with 's'
  	{
  		ty = ty-10;
  		trans();
  		ty = 0;
  	}

  	  	else if (key==101)//move left z with 'q'
  	{
  		tz = tz-10;
  		trans();
  		tz = 0;
  	}

  	  	else if (key==113)//move right z with 'q'
  	{
  		tz = tz+10;
  		trans();
  		tz = 0;
  	}

    if(key == 'x'){
    	qx = 30*3.14/180;
    	rotx();
    	qx =0;
    }

    if(key == 'y'){
    	qy = 30*3.14/180;
    	roty();
    	qy=0;
    }

    if(key == 'z'){
    	qz = 30*3.14/180;
    	rotz();
    	qz=0;
    }
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
			if(state==GLUT_DOWN) //scale down
			{
				Sx = 0.5; Sy = 0.5; Sz = 0.5;
    			scale();
    			Sx = 0; Sy = 0; Sz = 0;
			}
		}	
		break;
		case GLUT_RIGHT_BUTTON:
		{
			if(state==GLUT_DOWN)
			{
				Sx = 2; Sy = 2;  Sz = 2;
    			scale();
    			Sx = 0; Sy = 0; Sz = 0;
			}
		}
		break;		
	}
}

void display()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glClearColor(0.5, 0.5, 0.5, 1);
  drawCube(OrignalCube);
}

int main(int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(80, 80);
  glutInitWindowSize(600, 600);
  glutCreateWindow("3D");
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-300,300,-300,300,300,-300);
  gluLookAt(3.0, 4.0, 5.0,0.0, 0.0, 0.0,0.0, 1.0, 0.);
  glutDisplayFunc(display);
  glutMouseFunc(mouse);
  glutKeyboardFunc(myKey);
  glutMainLoop();
}
