#include <GL/glew.h>
#include <GL/freeglut.h>
#include <math.h>
#define pi 3.141592

void drawScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);

	
	float t = tan(30 * pi / 180);

	glBegin(GL_POLYGON);
	glVertex3f(-20* t,10*t,-10 ); //
	glVertex3f(-20 * t, -10 * t, -10);
	glVertex3f(20 * t, 10 * t, -10);
	glVertex3f(20 * t, -10 * t, -10);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-200*t,100*t,-100);
	glVertex3f(-200 * t, -100 * t, -100);
	glVertex3f(200 * t, 100 * t, -100);
	glVertex3f(200 * t, -100 * t, -100);
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
	//gluOrtho2D(0.0, 100.0, 0.0, 100.0);
	gluPerspective(60.0, 2.0, 10.0, 100.0);
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
	glutCreateWindow("hw2-4.cpp");
	glutDisplayFunc(drawScene);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyInput);
	glewExperimental = GL_TRUE;
	glewInit();
	setup();
	glutMainLoop();
}