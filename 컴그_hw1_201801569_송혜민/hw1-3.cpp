#include <GL/glew.h>
#include <GL/freeglut.h>
#include <math.h>
#define pi 3.141592

void drdisc(float radius, float center_x, float center_y) {
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(center_x, center_y, 0.0);

	for (int i = 0; i <= 360; i++) {
		float x, y;
		//x��ǥ�� y��ǥ�� ���ϱ� ���� �ﰢ�Լ� �̿�. ������*cos(����), sin�� ���� ���� ���� �߽���ǥ�� ���ϸ� ���� ���� ��ġ�� ��ǥ�� ����.
		//���� �׸��� ���� ������ 360���� ������ ������ �������� �ﰢ������ �ɰ�

		x = radius * cos(i * pi / 180);
		y = radius * sin(i * pi / 180);
		glVertex3f(center_x + x, center_y + y, 0.0);
	}
	glEnd();
	glFlush();

}


void drawScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	//���� ū ���� Ÿ��
	glColor3f(0.0, 0.0, 0.0);
	glOrtho(-1.0, 1.0, -1, 1, 1, -1);
	drdisc(30.0, 50.0, 50.0);
	
	//���� ū ��� ��
	glColor3f(1.0, 1.0, 1.0);
	glOrtho(-1.5, 1.5, -1, 1, 1, -1);
	drdisc(30.0, 75.0, 50.0);

	//���� ���� Ÿ��
	glColor3f(0.0, 0.0, 0.0);
	glOrtho(-1.0, 1.0, -2, 2, 1, -1);
	drdisc(30.0, 75.0, 100.0);

	//���� ��� ��
	glColor3f(1.0, 1.0, 1.0);
	glOrtho(-2, 2, -1, 1, 1, -1);
	drdisc(30.0, 150.0, 100.0);
	

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	glBegin(GL_TRIANGLE_STRIP);


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
	glutInitWindowSize(450, 300);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("hw1-3.cpp");
	glutDisplayFunc(drawScene);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyInput);
	glewExperimental = GL_TRUE;
	glewInit();
	setup();
	glutMainLoop();
}