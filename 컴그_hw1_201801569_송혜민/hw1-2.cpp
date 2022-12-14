#include <GL/glew.h>
#include <GL/freeglut.h>
#include <math.h>
#define pi 3.141592

// Drawing routine.
void drawScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);

	glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);

	glBegin(GL_TRIANGLE_STRIP);
	
	glVertex3f(60.0, 80.0, 0.0); //v2
	glVertex3f(60.0, 90.0, 0.0); //v3
	glVertex3f(20.0, 80.0, 0.0); //v1
	glVertex3f(10.0, 90.0, 0.0); //v4
	glVertex3f(20.0, 20.0, 0.0); //v8
	glVertex3f(10.0, 10.0, 0.0); //v5
	glVertex3f(60.0, 10.0, 0.0); //v6
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(20.0, 20.0, 0.0); //v8
	glVertex3f(60.0, 10.0, 0.0); //v6
	glVertex3f(60.0, 20.0, 0.0); //v7
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(20.0, 45.0, 0.0); //v9
	glVertex3f(40.0, 45.0, 0.0); //v10
	glVertex3f(20.0, 55.0, 0.0); //v12
	glVertex3f(40.0, 55.0, 0.0); //v11
	glEnd();

	glFlush();

	


}
// Initialization routine.
void setup(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
}
// OpenGL window reshape routine.
void resize(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 100.0, 0.0, 100.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
// Keyboard input processing routine.
void keyInput(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27:
		exit(0);
		break;
	default:
		break;
	}
}
// Main routine.
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitContextVersion(4, 3);
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("hw1-2.cpp");
	glutDisplayFunc(drawScene);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyInput);
	glewExperimental = GL_TRUE;
	glewInit();
	setup();
	glutMainLoop();
}