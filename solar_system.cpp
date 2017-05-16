
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>



void idleFunc( );
void displayFunc( );
void reshapeFunc( GLsizei width, GLsizei height );
void keyboardFunc( unsigned char, int, int );
void mouseFunc( int button, int state, int x, int y );


void initialize( );
void cleanUp( );
void render( );

#define NUM_STARS 400
#define FAR_PLANE -40.0f
#define NEAR_PLANE 3.0f
#define GAP 0.0f
#define FIELD_WIDTH ( 30.0f )
#define FIELD_HEIGHT ( 25.0f )
#define RADIUS 1.0f
#define DEFAULT_SPEED .02f;

// width and height of the window
GLsizei g_width = 640;
GLsizei g_height = 480;


static float Xvalue = 0.0, Yvalue = 0.0, Angle = 0.0;


int MoveMerc = 0;
int MoveVen = 0;
int MoveEar = 0;
int MoveMars = 0;
int MoveJup = 0;
int MoveSat = 0;
int MoveUra = 0;
int MoveNept = 0;



// light position
GLfloat g_light_position[4] = { 0.0f, 0.0f, 3.0f, 1.0f };

// the location
float * g_xyz[NUM_STARS];
// the colors
float * g_colors[NUM_STARS];

// the alpha and red components of polygon to blend
float g_alpha = 0.3f;
float g_red = 0.0f;
float g_speed = DEFAULT_SPEED;
float g_speed_inc = 0.0f;




void myInit(void) {
 glClearColor (0.0, 0.0, 0.0, 0.0);
}

static float Merc[360][2];
static float Ven[360][2];
static float Ear[360][2];
static float Mars[360][2];
static float Jup[360][2];
static float Sat[360][2];
static float Ura[360][2];
static float Nept[360][2];
static float Moon[360][2];

void generateCircle()
{
    int i = 0;
    for(i=0; i <= 360; i++)
    {
        Merc[i][0] = sin(i*3.1416/180)*1;
        Merc[i][1] = cos(i*3.1416/180)*1;
    }

    for(i=0; i <= 360; i++)
    {
        Ven[i][0] = sin(i*3.1416/180)*1.5;
        Ven[i][1] = cos(i*3.1416/180)*1.5;
    }
 
    for(i=0; i <= 360; i++)
    {
        Ear[i][0] = sin(i*3.1416/180)*2.0;
        Ear[i][1] = cos(i*3.1416/180)*2.0;
    }

    for(i=0; i <= 360; i++)
    {
        Moon[i][0] = sin(i*3.1416/180)*0.5;
        Moon[i][1] = cos(i*3.1416/180)*0.5;
    }

    for(i=0; i <= 360; i++)
    {
        Mars[i][0] = sin(i*3.1416/180)*2.5;
        Mars[i][1] = cos(i*3.1416/180)*2.5;
    }
    for(i=0; i <= 360; i++)
    {
        Jup[i][0] = sin(i*3.1416/180)*3.4;
        Jup[i][1] = cos(i*3.1416/180)*3.4;
    }
    for(i=0; i <= 360; i++)
    {
        Sat[i][0] = sin(i*3.1416/180)*4.3;
        Sat[i][1] = cos(i*3.1416/180)*4.3;
    }
    for(i=0; i <= 360; i++)
    {
        Ura[i][0] = sin(i*3.1416/180)*5.0;
        Ura[i][1] = cos(i*3.1416/180)*5.0;
    }
    for(i=0; i <= 360; i++)
    {
        Nept[i][0] = sin(i*3.1416/180)*5.8;
        Nept[i][1] = cos(i*3.1416/180)*5.8;
    }

}
void myDisplay(void) {
 
 glClear (GL_COLOR_BUFFER_BIT);
 glColor3f (1.0, 1.0, 1.0);
 //sun
 glPushMatrix();
 glColor3f(1.000, 1.000, 0.000); 
 gluLookAt (0.0, 10.0, 2.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
 glTranslatef(Xvalue, 0.0, Yvalue);
 glRotatef(Angle, 0.0, 0.0, 1.0);
 glutWireSphere (1, 20, 20);
 glPopMatrix();
 
 //Mercury
 glPushMatrix();
 glColor3f (0.55, 0.55, 0.55);
 gluLookAt (0.0, 10.0, 2.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
 if(MoveMerc==360)
  MoveMerc = 0;
 glTranslatef(Merc[MoveMerc][1], Merc[MoveMerc][0], 0.0);
 glRotatef(Angle, 0.0, 0.0, 1.0);
 glutWireSphere (0.3, 15, 15);
 glPopMatrix();

 //Venus
  glPushMatrix();
 glColor3f (0.604, 0.804, 0.196);
 gluLookAt (0.0, 10.0, 2.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
 if(MoveVen==360)
  MoveVen = 0;
 glTranslatef(Ven[MoveVen][1], Ven[MoveVen][0], 0.0);
 glRotatef(Angle, 0.0, 0.0, 1.0);
 glutWireSphere (0.3, 20, 20);
 glPopMatrix();

//Earth
  glPushMatrix();
 glColor3f (0.275, 0.510, 0.706);
 gluLookAt (0.0, 10.0, 2.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
 if(MoveEar==360)
  MoveEar = 0;
 glTranslatef(Ear[MoveEar][1], Ear[MoveEar][0], 0.0);
 glRotatef(Angle, 0.0, 0.0, 1.0);
 glutWireSphere (0.6, 20, 20);
 glColor3f (0.9, 0.9, 0.9);
 glTranslatef(Moon[MoveEar][0], Moon[MoveEar][1], 0.0);
 glutWireSphere (0.1, 20, 20);
 glPopMatrix();


//Mars
glPushMatrix();
 glColor3f (1.0, 0.0, 0.0);
 gluLookAt (0.0, 10.0, 2.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
 if(MoveMars==360)
  MoveMars = 0;
 glTranslatef(Mars[MoveMars][1], Mars[MoveMars][0], 0.0);
 glRotatef(Angle, 0.0, 0.0, 1.0);
 glutWireSphere (0.4, 20, 20);
 glPopMatrix();

//Jupiter
 glPushMatrix();
 glColor3f (1.000, 0.647, 0.000);
 gluLookAt (0.0, 10.0, 2.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
 if(MoveJup==360)
  MoveJup = 0;
 glTranslatef(Jup[MoveJup][1], Jup[MoveJup][0], 0.0);
 glRotatef(Angle, 0.0, 0.0, 1.0);
 glutWireSphere (0.7, 20, 20);
 glPopMatrix();

//Saturn
 glPushMatrix();
 glColor3f (1.000, 0.871, 0.678);
 gluLookAt (0.0, 10.0, 2.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
 if(MoveSat==360)
  MoveSat = 0;
 glTranslatef(Sat[MoveSat][1], Sat[MoveSat][0], 0.0);
 glRotatef(Angle, 0.0, 0.0, 1.0);
 glutWireSphere (0.5, 20, 20);
 int i = 0;
 glBegin(GL_QUAD_STRIP);
 for(i=0; i <= 360; i++)
 {
  glVertex3f(sin(i*3.1416/180)*0.5, cos(i*3.1416/180)*0.5, 0 );
  glVertex3f(sin(i*3.1416/180)*0.7, cos(i*3.1416/180)*0.7, 0 );
 }
 glEnd();
 glRotatef(Angle, 0.0, 0.0, 1.0);
 glPopMatrix();
 
//Uranus
 glPushMatrix();
 glColor3f (0.000, 0.000, 0.545);
 gluLookAt (0.0, 10.0, 2.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
 if(MoveUra==360)
  MoveUra = 0;
 glTranslatef(Ura[MoveUra][1], Ura[MoveUra][0], 0.0);
 glRotatef(Angle, 0.0, 0.0, 1.0);
 glutWireSphere (0.6, 20, 20);
 glPopMatrix();

//Neptune
  glPushMatrix();
 glColor3f (0.255, 0.412, 0.882);
 gluLookAt (0.0, 10.0, 2.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
 if(MoveNept==360)
  MoveNept = 0;
 glTranslatef(Nept[MoveNept][1], Nept[MoveNept][0], 0.0);
 glRotatef(Angle, 0.0, 0.0, 1.0);
 glutWireSphere (0.5, 20, 20);
 i = 0;
 glBegin(GL_QUAD_STRIP);
 for(i=0; i <= 360; i++)
 {
  glVertex3f(sin(i*3.1416/180)*0.5, cos(i*3.1416/180)*0.5, 0 );
  glVertex3f(sin(i*3.1416/180)*0.7, cos(i*3.1416/180)*0.7, 0 );
 }
 glEnd();
 glRotatef(Angle, 0.0, 0.0, 1.0);
 glPopMatrix();

 glFlush ();
}


void animation(int value)
{
    Angle += 15.0;
    glutPostRedisplay();
    MoveMerc +=1;
    MoveVen +=1*2;
    MoveEar +=1;
    MoveMars +=1;
    MoveJup +=1*2;
    MoveSat +=1;
    MoveUra +=1*3;
    MoveNept +=1*2;
    glutPostRedisplay();
    glutTimerFunc(100, animation, 0);
}




int main( int argc, char ** argv )
{
    // initialize GLUT


    glutInit(&argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
    glutInitWindowSize( 1000, 1000 );
    glutInitWindowPosition(100, 150);
    glutCreateWindow("Solar System");
    myInit();
    
    generateCircle();
    glutTimerFunc(400, animation, 0);
   

    // set the idle function - called when idle
    glutIdleFunc( idleFunc );
    // set the display function - called when redrawing
    glutDisplayFunc( displayFunc );
    // set the reshape function - called when client area changes
    glutReshapeFunc( reshapeFunc );
    // set the keyboard function - called on keyboard events
    glutKeyboardFunc( keyboardFunc );
    // mouse function - called on mouse events
    glutMouseFunc( mouseFunc );

    // do our own initialization
    initialize();

    // let GLUT handle the current thread from here
    glutMainLoop();

    return 0;
}



void initialize()
{
    // set the GL clear color - use when the color buffer is cleared
    glClearColor( 0, 0, 0, 0 );
    // set the shading model to 'smooth'
    glShadeModel( GL_SMOOTH );
    // set GL to render front of polygons
    glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
    // enable depth test
    glEnable( GL_DEPTH_TEST );
    // set the initial line width
    glLineWidth( 1.0f );

    // enable lighting
    glEnable( GL_LIGHTING );
    // enable lighting for front
    glLightModeli( GL_FRONT, GL_TRUE );
    // material have diffuse and ambient lighting 
    glColorMaterial( GL_FRONT, GL_AMBIENT_AND_DIFFUSE );
    // enable color
    glEnable( GL_COLOR_MATERIAL );
    // enable light 0
    glEnable( GL_LIGHT0 );

    // set light attenuation
    glLightf( GL_LIGHT0, GL_CONSTANT_ATTENUATION, 0.01f );
    glLightf( GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.2f );
    glLightf( GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.001f );

    // clear the color buffer once
    glClear( GL_COLOR_BUFFER_BIT );

    // randomly generate
    srand( time( NULL ) );
    for( int i = 0; i < NUM_STARS; i++ )
    {
        g_xyz[i] = new float[3];
        g_xyz[i][0] = ( (float) rand() / RAND_MAX - .5f ) * FIELD_WIDTH;
        g_xyz[i][1] = ( (float) rand() / RAND_MAX - .5f ) * FIELD_HEIGHT;
        g_xyz[i][2] = ( (float) rand() / RAND_MAX ) * 
                      ( NEAR_PLANE - FAR_PLANE + GAP ) + FAR_PLANE;

        g_colors[i] = new float[3];
        g_colors[i][0] = (float) rand() / RAND_MAX;
        g_colors[i][1] = (float) rand() / RAND_MAX;
        g_colors[i][2] = (float) rand() / RAND_MAX;
    }

}


void cleanUp( )
{
}

void idleFunc( )
{
    glutPostRedisplay( );
}


void displayFunc( )
{
    // clear the depth buffer
    glClear( GL_DEPTH_BUFFER_BIT );
    //glutDisplayFunc(myDisplay);
    // enable blending
    glEnable( GL_BLEND );
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

    // disable lighting
    glDisable( GL_LIGHTING );
    // disable depth test
    glDisable( GL_DEPTH_TEST );
    // blend in a polygon
    glColor4f( g_red, g_red, g_red, g_alpha );

    // reduce the red component
    g_red -= .02f;
    if( g_red < 0.0f )
        g_red = 0.0f;

    // draw the polyg
    glBegin( GL_QUADS );
        glVertex3f( -1.0f, -1.0f, 2.0f );
        glVertex3f( -1.0f, 1.0f, 2.0f );
        glVertex3f( 1.0f, 1.0f, 2.0f );
        glVertex3f( 1.0f, -1.0f, 2.0f );
    glEnd();

    // enable lighting
    glEnable( GL_LIGHTING );
    // enable depth test
    glEnable( GL_DEPTH_TEST );
    // disable blending
    glDisable( GL_BLEND );

    // save the current matrix state, so transformation will
    // not persist across displayFunc calls, since we
    // will do a glPopMatrix() at the end of this function
    glPushMatrix( );

    // render the scene
    render( );

    // restore the matrix state
    glPopMatrix( );

    // flush the buffer
    glFlush( );
    // swap the double buffer
    glutSwapBuffers( );
    myDisplay();
}



void render()
{
    static float inc = 0.0f;
    inc += 0.001f;
    glRotatef( 50 * cos( inc ), 0.0f, 0.0f, 1.0f );

    g_speed += g_speed_inc;
    for( int i = 0; i < NUM_STARS; i++ )
    {
        glPushMatrix();
            glTranslatef( g_xyz[i][0], g_xyz[i][1], g_xyz[i][2] );
            glColor3fv( g_colors[i] );
            glutSolidSphere( .1f, 5, 5 );
        glPopMatrix();

        // increment z
        g_xyz[i][2] += g_speed;

        // check to see if passed view
        if( g_xyz[i][2] > NEAR_PLANE + GAP )
        {
            float d;
            if( ( d = sqrt( g_xyz[i][0] * g_xyz[i][0] + 
                g_xyz[i][1] * g_xyz[i][1] ) ) < RADIUS )
            {
                g_red += ( RADIUS - d ) / RADIUS;
                if( g_red > 2.5f ) g_red = 2.5f;
            }

            g_xyz[i][0] = ( (float) rand() / RAND_MAX - .5f ) * FIELD_WIDTH;
            g_xyz[i][1] = ( (float) rand() / RAND_MAX - .5f ) * FIELD_HEIGHT;
            g_xyz[i][2] = FAR_PLANE;
        }
        else if( g_xyz[i][2] < FAR_PLANE )
        {
            g_xyz[i][0] = ( (float) rand() / RAND_MAX - .5f ) * FIELD_WIDTH;
            g_xyz[i][1] = ( (float) rand() / RAND_MAX - .5f ) * FIELD_HEIGHT;
            g_xyz[i][2] = NEAR_PLANE;
        }
    }
}




void reshapeFunc( GLsizei w, GLsizei h )
{
    // save the new width and height
    g_width = w; g_height = h;

    // map the view port to the entire client area
    glViewport(0, 0, w, h);

    // set the matrix mode to projection matrix
    glMatrixMode(GL_PROJECTION);
    // load the identity matrix
    glLoadIdentity();
    // set the perspective matrix
    gluPerspective( 64.0, (GLdouble) w / h, .1, 300.0 );

    // set the matrix mode to the modelview matrix
    glMatrixMode(GL_MODELVIEW);
    // load the identity matrix into the modelview matrix
    glLoadIdentity();
    // set the 'camera'
    gluLookAt( 0.0, 0.0, 3.0, 0.0, 0.0, 0.0, 0.0, 2.0, 3.0 );
    // set the position of the light
    glLightfv( GL_LIGHT0, GL_POSITION, g_light_position );
}



void keyboardFunc( unsigned char key, int x, int y )
{
    switch( key )
    {

    case 'Q':
    case 'q':
        cleanUp( );
        exit( 1 );
    break;
    };
}


void mouseFunc( int button, int state, int x, int y )
{
    if( button == GLUT_LEFT_BUTTON )
    {   
        // when left mouse button is down, go forward faster
        if( state == GLUT_DOWN )
        { g_speed_inc += .02f; }
        else if( state == GLUT_UP )
        { g_speed_inc -= .02f; }
    }
    else if ( button == GLUT_RIGHT_BUTTON )
    {
        // when right mouse button down, go backwards faster
        if( state == GLUT_DOWN )
        { g_speed_inc -= .02f; }
        else if( state == GLUT_UP )
        { g_speed_inc += .02f; }
    }
    else if( button == GLUT_MIDDLE_BUTTON )
    {
        if( state == GLUT_DOWN )
        { g_speed = DEFAULT_SPEED; g_speed_inc = 0; }
    }
}