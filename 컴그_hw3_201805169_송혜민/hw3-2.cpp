#include <GL/glew.h>
#include <GL/freeglut.h>

void spoke() {
	
	glViewport(-100, 200, -100, 200);

	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_LINE_STRIP);
	glVertex2f(1, 1); 
	glVertex2f(5, 1);
	glVertex2f(8, 4);
	glVertex2f(9, 3.5);
	glVertex2f(7, 1);
	glVertex2f(10, 1);
	glVertex2f(13, 4);
	glVertex2f(14, 3.5);
	glVertex2f(12, 1);
	glVertex2f(15, 1);
	glVertex2f(16, 0.0);
	glEnd();

	glScalef(1.0, -1.0, 1.0);

	glBegin(GL_LINE_STRIP);
	glVertex2f(1, 1);
	glVertex2f(5, 1);
	glVertex2f(8, 4);
	glVertex2f(9, 3.5);
	glVertex2f(7, 1);
	glVertex2f(10, 1);
	glVertex2f(13, 4);
	glVertex2f(14, 3.5);
	glVertex2f(12, 1);
	glVertex2f(15, 1);
	glVertex2f(16, 0.0);


	glEnd();
	

}


void drawScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT);


	spoke();
	glRotatef(60.0, 0.0, 0.0, 1.0);

	spoke();
	glRotatef(120.0, 0.0, 0.0, 1.0);

	spoke();
	glRotatef(180.0, 0.0, 0.0, 1.0);

	spoke();
	glRotatef(240.0, 0.0, 0.0, 1.0);

	spoke();
	glRotatef(300.0, 0.0, 0.0, 1.0);

	spoke();
	glRotatef(360.0, 0.0, 0.0, 1.0);
	

	
	glFlush();
	
}
void myfun() {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-30, 50, -30, 50);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(300, 300);
	glutCreateWindow("hw3-2.cpp");
	glutDisplayFunc(drawScene);
	myfun();
	glutMainLoop();
}