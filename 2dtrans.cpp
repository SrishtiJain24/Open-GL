#include<GL/glut.h>
#include<GL/glu.h>
#include<GL/gl.h>
#include<math.h>
#include<string.h>
void display();

float  x1=-200, Y1=0, x2=200, y2=0, x3=0, y3=200;
int  r2=3, c2=3, r1=3, c1=3,i, j, k;
float r11, r22, r33, r12, r13, r21, r23, r31, r32;
float a[][3]={{x1, x2, x3},{Y1, y2, y3},{1,1,1}};
float c[3][3]={};
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
void Draw(float c[3][3]){
    glClearColor(0.5,0.5,0.5,1);

    glClear(GL_COLOR_BUFFER_BIT);
    displayText(-480,460,1,1,1,"Srishti Jain");
	displayText(-480,420,1,1,1,"R134214070");
displayText(-200,-480,1,1,1,"2D Transformation");
		displayText(-400,-420,1,1,1,"R: Rotation, +: Zoom in, -: Zoom out, A: Left Shift, D: Right Shift");
	displayText(-460,-380,1,1,1,"Press	X: Reflection in x-axix, Y: Reflection in y-axis, W: Move Up, S: Move Down ");
    glColor3f(0,0,1);  
    glBegin(GL_POLYGON);
    for (j=0; j< 3; ++j){
        glVertex2f(c[0][j], c[1][j]);
        }
    glEnd(); 
    glFlush();
    }
void trans( float a[3][3], float b[3][3], float c[3][3]){
    for(i = 0; i < r1; ++i)
        for(j = 0; j < c2; ++j)
        {
            c[i][j]=0;
        }
    for(i = 0; i < r1; ++i)
        for(j = 0; j < c2; ++j)
            for(k = 0; k < c1; ++k)
            {
                c[i][j] += b[i][k] * a[k][j];
            }
    for(int i = 0; i<3;i++){
        for(int j =0; j<3;j++){
        a[i][j]=c[i][j];
        }
    }
}
   
void Keypress(unsigned char key,int x, int y){
  
    if (key == 97){ 
        float b[3][3]= {{1, 0, -2},{0, 1, 0}, {0, 0, 1}};
trans( a, b, c );
Draw(c);
  }
    if (key == 100){ 
        float b[3][3]= {{1, 0, 2},{0, 1, 0}, {0, 0, 1}};
trans( a, b, c );
Draw(c);
    }
    if (key == 119){ 
float b[3][3]= {{1, 0, 0},{0, 1, 2}, {0, 0, 1}};
trans( a, b, c );
Draw(c);
    }
    if (key == 115){ 
float b[3][3]= {{1, 0, 0},{0, 1, -2}, {0, 0, 1}};
trans( a, b, c );
Draw(c);
    }
    if (key == 43){ //scaling
float b[3][3]= {{2, 0, 0},{0, 2, 0}, {0, 0, 1}};
trans( a, b, c );
Draw(c);
    }
    if (key == 45){ //scaling
float b[3][3]= {{0.5, 0, 0},{0, 0.5, 0}, {0, 0, 1}};
trans( a, b, c );
Draw(c);
    }
    if (key == 114){ //rotation
float b[3][3]= {{cos(3.14/6), sin(3.14/6), 0},{-sin(3.14/6), cos(3.14/6), 0}, {0, 0, 1}};
trans( a, b, c );
Draw(c);
    }
    if (key == 120){ //reflection about x axis
float b[3][3]= {{1, 0, 0},{0,-1, 0}, {0, 0, 1}};
trans( a, b, c );
Draw(c);
    }
if (key == 121){ //reflection about y axis
float b[3][3]= {{-1, 0, 0},{0,1, 0}, {0, 0, 1}};
trans( a, b, c );
Draw(c);
    }

}

 void display()
	{

		glClearColor(0.5,0.5,0.5,1);
		glClear(GL_COLOR_BUFFER_BIT);
        displayText(-480,460,1,1,1,"Srishti Jain");
	    displayText(-480,420,1,1,1,"R134214070");
	displayText(-200,-480,1,1,1,"2D Transformation");
		displayText(-400,-420,1,1,1,"R: Rotation, +: Zoom in, -: Zoom out, A: Left Shift, D: Right Shift");
	displayText(-460,-380,1,1,1,"Press	X: Reflection in x-axix, Y: Reflection in y-axis, W: Move Up, S: Move Down "); 

		glBegin(GL_POLYGON);
		glColor3f(0,0,1);  
		glVertex2f(x1,Y1); 
		glVertex2f(x2,y2);
		glVertex2f(x3,y3);	
		glEnd(); 
        glFlush();
        }

int main(int argc,char** argv)
	{
	
		glutInit(&argc,argv);
		glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
		glutInitWindowPosition(50,50);
		glutInitWindowSize(700,700);
		glutCreateWindow("transformation");	
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(-500,500,-500,500);		
		glutDisplayFunc(display);
        glutKeyboardFunc(Keypress);
		glutMainLoop();
		return 0;
	
	}
