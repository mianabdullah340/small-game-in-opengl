/*
 * game.c
 *
 *  Created on: 16-Dec-2018
 *      Author: Mian Abdullah
 */




#include <windows.h>
#include <gl/glut.h>
#include<math.h>
#include <stdio.h>

#define PI 3.14159265f


GLfloat bladius=0.05f;
float blX=10.0f;
float blY=10.0f;
GLfloat blspeedX=0.02f;
GLfloat blspeedY=0.007f;
GLfloat blMinX ,blMaxX , blMinY ,blMaxY;

int interval=30;


double left , right , bottom , top;

void myinit() //set attributes
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); //  setting background color black
    gluOrtho2D(0,500,0,500);
}


void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	printf("%f------%f\n" , blX, blMaxX);
	glTranslatef(blX,blY,0.0f);
	glutSolidCube(bladius);
	glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f ,0.0f ,0.0f);

    int segments=100;
    GLfloat angle;
    for(int i=0 ; i<=segments; i++){
    angle=i*2.0f*PI / segments; // formula for filling vertex of circle
    glVertex2f(cos(angle)*bladius ,sin(angle)*bladius);

    }
        glEnd();
   		glutSwapBuffers();
   		glFlush();


   		if( blX>blMaxX ){

   			blX=blMaxX;
   			blspeedX=-blspeedX;

   		}

   		else if(blX<blMinX){
   			blX=blMinX;
   		    blspeedX=+blspeedX;
   		}

   		if( blY>blMaxY ){

   				blY=blMaxY;
   				blspeedY=-blspeedY;

   			}

   			else if(blY<blMinY){
   				blY=blMinY;
   			    blspeedY=-blspeedY;
   			}


}


void myTimer(int value) {

	blX=blX+blspeedX;
	   		blY=blY+blspeedY;


	glutPostRedisplay();
	glutTimerFunc(interval, myTimer, 0);

	}







int main(int argc, char ** argv) {
	glutInit(&argc, argv); // initialize GLUT
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); //setting display mode
	glutInitWindowSize(500, 500); // window size
	glutInitWindowPosition(0, 0);  // window position
	glutCreateWindow("house");

	glutDisplayFunc(display); // Register callback func
	glutTimerFunc(0, myTimer, 0);
	myinit(); // Set attribute
	glutMainLoop(); // enter event Loop
	return 0;
}

