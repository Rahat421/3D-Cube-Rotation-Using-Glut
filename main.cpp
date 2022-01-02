#include<GL/gl.h>
#include<GL/glu.h>
#include <GL/glut.h>

void init()
{
    glClearColor(0.0,0.0,0.0,1.0);
    glEnable(GL_DEPTH_TEST); //  Enables Depth Testing
}

float angle = 0.0;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // These 2 Flags Clears the frame buffer and depth Buffer
    glLoadIdentity(); // Resets Previous Frame

    glTranslatef(0.0,0.0,-8.0); //Here origin -8.0 is far away from the camera so that we can see
    glRotatef(angle, 1.0, 1.0, 1.0); //glroratef(angle,x-coordinate,y,z)
    glRotatef(angle, 1.0, 0.0, 0.0);
    glRotatef(angle, 0.0, 1.0, 0.0);
    glRotatef(angle, 0.0, 0.0, 1.0);
    //draw
    glBegin(GL_QUADS); // Turns 4 consecutive Vertices into a single quadrilateral

    //Geometry of front square
    //Counter-Clockwise Order
    glColor3f(1.0,0.0,0.0);
    glVertex3f(-1.0,1.0,1.0);
    glVertex3f(-1.0,-1.0,1.0);
    glVertex3f(1.0,-1.0,1.0);
    glVertex3f(1.0,1.0,1.0);
    //Geometry of back square
    // Clockwise Order
    glColor3f(0.0,1.0,0.0);
    glVertex3f(1.0,1.0,-1.0);
    glVertex3f(1.0,-1.0,-1.0);
    glVertex3f(-1.0,-1.0,-1.0);
    glVertex3f(-1.0,1.0,-1.0);
    //Geometry of right square
    glColor3f(0.0,0.0,1.0);
    glVertex3f(1.0,1.0,1.0);
    glVertex3f(1.0,-1.0,1.0);
    glVertex3f(1.0,-1.0,-1.0);
    glVertex3f(1.0,1.0,-1.0);
    //Geometry of left square
    glColor3f(1.0,1.0,0.0);
    glVertex3f(-1.0,1.0,-1.0);
    glVertex3f(-1.0,-1.0,-1.0);
    glVertex3f(-1.0,-1.0,1.0);
    glVertex3f(-1.0,1.0,1.0);
    //Geometry of top square
    glColor3f(0.0,1.0,1.0);
    glVertex3f(-1.0,1.0,-1.0);
    glVertex3f(-1.0,1.0,1.0);
    glVertex3f(1.0,1.0,1.0);
    glVertex3f(1.0,1.0,-1.0);
    //Geometry of bottom square
    glColor3f(1.0,0.0,1.0);
    glVertex3f(-1.0,-1.0,-1.0);
    glVertex3f(-1.0,-1.0,1.0);
    glVertex3f(1.0,-1.0,1.0);
    glVertex3f(1.0,-1.0,-1.0);

    glEnd();

    glutSwapBuffers();
}

void reshape(int w, int h)
{
    //viewport
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60,1,2.0,50.0);
    glMatrixMode(GL_MODELVIEW);

}

void timer(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/60,timer,0);

    angle-=0.8; // control the speed of rotation
    if(angle>360.0)
        angle=angle-360.0; //For handling overflow
}

int main(int argc, char**argv)
{
    glutInit(&argc, argv); // Glut Initialization
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); //Display Mode Initialization

    glutInitWindowPosition(200,100); // Determines Window Position
    glutInitWindowSize(500,500); // Determines the Size of the Window
    glutCreateWindow("3D Cube Rotation"); // Creates Window Named 3D Cube Rotation

    glutDisplayFunc(display); // Visualizes anything drawn on the display function. Callback Function
    glutReshapeFunc(reshape);
    glutTimerFunc(0,timer,0);
    init();
    glutMainLoop(); // Keeps the program running

}

