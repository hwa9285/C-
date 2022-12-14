#include <iostream>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include<glm/glm.hpp>
#include <cstdlib>
using namespace std;

void pickPixel(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

int round(float z)
{
    int y;
    y = z > 0.0 ? int(z + 0.5) : int(z - 0.5);
    return y;
}

void DDA(int i1, int j1, int i2, int j2) // Assume i2 > i1.
{


    float y = j1;
    float x = i1;
    float m = float(j2 - j1) / (i2 - i1); //���� ���.

    if (m < 1) {//���Ⱑ 1���� ���� ���
        for (x; x <= i2; x++)
        {
            pickPixel(x, round(y));
            y += m;
        }
    }
    else if (m > 1) {//���Ⱑ 1���� Ŭ ���
        for (float y = j1; y <= j2; y++) {
            pickPixel(round(x), y);
            x += 1/m;
        }
    }

}

void MidpointLine(int x1, int y1, int x2, int y2) {
    int dx, dy, incrE, incrNE, D, x, y;
    dx = x2 - x1; dy = y2 - y1;
    D = 2 * dy - dx; //�������� ���� �ʱ�ȭ
    incrE = 2 * dy; //���� ȭ�� ���ý� ������
    incrNE = 2 * dy - 2 * dx; //������ ȭ�� ���ý� ������

    x = x1; y = y1; //ù ȭ��
    DrawPixel(x, y) //ù ȭ�� �׸���
        while (x < x2) {
        if (D <= 0) { //���������� ����. ����ȭ�� ����
            D += incrE; //�������� ����
            x++; //���� ȭ�Ҵ� ����
        }
        else { //���������� ���. ������ ȭ�� ����
            D += incrNE; //�������� ����
            x++; y++; //���� ȭ�Ҵ� ������
        }
        DrawPixel(x, y); //ȭ�� �׸���
        
    }
}

void drawScene(void)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0, 0.0, 0.0);

    DDA(100, 100, 200, 300);

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("DDA.cpp");
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glutDisplayFunc(drawScene);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);
    glutMainLoop();

    return 0;
}