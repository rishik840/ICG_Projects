// CS6610Project.cpp : Defines the entry point for the console application.
// Author:	Rishabh Kaushik
// Uid:		u1008988
// Email:	rhul840@gmail.com

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <GL/glew.h>
#include <GL/freeglut.h>

using namespace std;

const int REFRESH_RATE = 900;// in millisecs

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glutSwapBuffers();
}

void userInput(unsigned char key, int xmouse, int ymouse)
{
	if (key == 27)// for escape key
	{
		glutLeaveMainLoop();
	}
}

void idle()
{
	glClearColor((float)rand() / (float)RAND_MAX, (float)rand() / (float)RAND_MAX, (float)rand() / (float)RAND_MAX, 1.0f);
	//glutPostRedisplay();
}

void timer(int val)
{
	glutPostRedisplay();
	glutTimerFunc(REFRESH_RATE, timer, 0);
}

void initGL()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

int main(int argc, char* argv[])
{

	glutInit(&argc, argv);
	// Set parameters for OpenGL window and nature of buffer
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Rishabh's Assignment 1 (CS6610)");
	glutDisplayFunc(display);

	glutTimerFunc(0, timer, 0); //call timer immediately here
	glutKeyboardFunc(userInput);
	initGL();
	glutIdleFunc(idle);
	glutMainLoop();
	return 0;
}

