#include <GL/glew.h>
#include <GL/freeglut.h>
#include <math.h>
#define pi 3.141592
#include <fstream>

void drawPolyLineFile(const char* fileName) {

	std::ifstream inStream;
	inStream.open(fileName);	// open the file
	if (inStream.fail())
		return;
	//glClear(GL_COLOR_BUFFER_BIT);      // clear the screen 
	glColor3f(0.0, 0.0, 0.0);
	GLint numpolys, numLines, x, y;
	inStream >> numpolys;		           // read the number of polylines
	for (int j = 0; j < numpolys; j++)  // read each polyline
	{
		inStream >> numLines;
		glBegin(GL_LINE_STRIP);	     // draw the next polyline
		for (int i = 0; i < numLines; i++)
		{
			inStream >> x >> y;        // read the next x, y pair
			glVertex2i(x, y);
		}
		glEnd();
	}
	glFlush();
	inStream.close();
}

//--------------- setWindow ---------------------
void setWindow(float left, float right, int bottom, int top)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(left, right, bottom, top);

	glClearColor(1.0, 1.0, 1.0, 0.0);
}

void render() {

	glClear(GL_COLOR_BUFFER_BIT);

	//x좌표와 y좌표를 구해야함
	//화면 한 줄에는 공룡이 5개씩 출력되므로 640/5 = 128, 480/5 = 96 임을 이용

	int k = 1;
	for (int i = 0; i < 640; i+=128) { //x좌표
		for (int j = 0; j < 480; j += 96) {
			if (k % 2 == 0) {//짝수일 경우
				setWindow(0.0, 640.0, 0.0, 480.0);
			}
			else {//홀수일 경우
				setWindow(0.0, 640.0, 480.0, 0.0);
			}
			glViewport(i,j,128,96);
			drawPolyLineFile("dino.dat");
			k++;
		}
	}

	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("hw1-4");
	glutDisplayFunc(render);;
	glutMainLoop();
	return(0);

}