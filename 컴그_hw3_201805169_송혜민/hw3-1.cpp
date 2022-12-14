#include <GL/glew.h>
#include <GL/freeglut.h>
#include <math.h>
#define pi 3.141592

void drdisc(float radius, float center_x, float center_y,float z) {
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(center_x, center_y, 0.0);

	for (int i = 0; i <= 360; i++) {
		float x, y;
		//x좌표와 y좌표를 구하기 위해 삼각함수 이용. 반지름*cos(각도), sin을 곱한 값에 원의 중심좌표를 더하면 찍을 점의 위치의 좌표가 나옴.
		//원을 그리기 위해 점들을 360개로 나누고 점들을 여러개의 삼각형으로 쪼갬

		x = radius * cos(i * pi / 180);
		y = radius * sin(i * pi / 180);
		glVertex3f(center_x + x, center_y + y, z);
	}
	glEnd();
	glFlush();

}


void drawScene(void)
{
	//glClear(GL_COLOR_BUFFER_BIT);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glPolygonMode(GL_FRONT, GL_FILL);
	glPolygonMode(GL_BACK, GL_LINE);


	//첫 번째 가장 큰 초록색 원
	glColor3f(0.0f, 1.0f, 0.0f);
	drdisc(5, 0, 0, -5);

	//두 번째 빨간색 원
	glColor3f(1.0f, 0.0f, 0.0f);
	drdisc(7, 0, 0, -10);

	//세 번쨰 파란색 원
	glColor3f(0.0f, 0.0f, 1.0f);
	drdisc(6, 0, 0, -15);

	//네 번째 노란색 원
	glColor3f(1.0f, 1.0f, 0.0f);
	drdisc(3, 0, 0, -20);

	//다섯 번째 보라색 원
	glColor3f(1.0f, 0.0f, 1.0f);
	drdisc(1, 0, 0, -25);


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
	//glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH); 
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("squareOfWalls.cpp");
	glutDisplayFunc(drawScene);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(100.0,100.0,100.0,100.0,5.0,100.0);
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glutMainLoop();
}