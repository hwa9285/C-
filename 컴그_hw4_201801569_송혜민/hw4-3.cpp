#include <iostream>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include<glm/glm.hpp>
#include <cstdlib>
using namespace std;


void MidpointLine(int x1, int y1, int x2, int y2) {
    int dx, dy, incrE, incrNE, D, x, y;
    dx = x2 - x1; dy = y2 - y1;
    D = 2 * dy - dx; //�������� ���� �ʱ�ȭ
    incrE = 2 * dy; //���� ȭ�� ���ý� ������
    incrNE = 2 * dy - 2 * dx; //������ ȭ�� ���ý� ������
    cout << "ù ��° D�� ��>> " << D <<endl;

    x = x1; y = y1; //ù ȭ��
    while (x < x2) {
        if (D <= 0) { //���������� ����. ����ȭ�� ����
            D += incrE; //�������� ����
            x++; //���� ȭ�Ҵ� ����
        }
        else { //���������� ���. ������ ȭ�� ����
            D += incrNE; //�������� ����
            x++; y++; //���� ȭ�Ҵ� ������
        }
        cout << "������Ʈ�� D�� ��>> " << D << endl;
    }
}

void pickPixel(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
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
            x += 1 / m;
        }
    }
}

int main() {
    MidpointLine(7, 1, 16, 6);
}