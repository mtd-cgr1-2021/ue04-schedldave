/**
 * 
 * PLEASE FILL IN YOUR NAME AND ID!
 * @name _Firstname Lastname_
 * @student_id _Sxxxxxxxxxx@fhooe.at_
 */

#include <stdlib.h>
#include <GL/glut.h>

void drawQuad(float r, float g, float b)
{
	glColor3f(r, g, b);
	glBegin(GL_POLYGON);
		glVertex3f(-0.5, -0.5, 0.0);
		glVertex3f(-0.5, 0.5, 0.0);
		glVertex3f(0.5, 0.5, 0.0);
		glVertex3f(0.5, -0.5, 0.0);
	glEnd();
}


//render method (callback-function)
void display()
{
	//clear all pixels
	glClear(GL_COLOR_BUFFER_BIT);
	
	glLoadIdentity();

	drawQuad(1,1,1); // draw a white quad

	glPushMatrix();	// push to matrix stack
	glPopMatrix(); // pop from matrix stack

	//don't wait! process buffered OpenGL routines
	glFlush();	
}

//initialization of the application. only started once.
void init() 
{
	//select clearing color (color that is used as 'background')
	glClearColor(0.0, 0.0, 0.0, 0.0);

	//initialize view
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0); 

	//set matrix-mode back to model-view for rendering
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);

	//initialize display mode (single buffer and RGBA)
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	//initialize window size and position. open window
	glutInitWindowSize(250, 250); 
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Open GL - CGR1 - UE04");

	//call initialization routine
	init();
	
	//register callback function to display graphics
	glutDisplayFunc(display); 
	
	//enter main loop and process events
	glutMainLoop();

	return 0;
}