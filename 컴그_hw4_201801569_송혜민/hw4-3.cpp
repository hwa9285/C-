#include <iostream>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include<glm/glm.hpp>
#include <cstdlib>
using namespace std;


void MidpointLine(int x1, int y1, int x2, int y2) {
    int dx, dy, incrE, incrNE, D, x, y;
    dx = x2 - x1; dy = y2 - y1;
    D = 2 * dy - dx; //결정변수 값을 초기화
    incrE = 2 * dy; //동쪽 화소 선택시 증가분
    incrNE = 2 * dy - 2 * dx; //동북쪽 화소 선택시 증가분
    cout << "첫 번째 D의 값>> " << D <<endl;

    x = x1; y = y1; //첫 화소
    while (x < x2) {
        if (D <= 0) { //결정변수가 음수. 동쪽화소 선택
            D += incrE; //결정변수 증가
            x++; //다음 화소는 동쪽
        }
        else { //결정변수가 양수. 동북쪽 화소 선택
            D += incrNE; //결정변수 증가
            x++; y++; //다음 화소는 동북쪽
        }
        cout << "업데이트된 D의 값>> " << D << endl;
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
    float m = float(j2 - j1) / (i2 - i1); //기울기 계산.

    if (m < 1) {//기울기가 1보다 작을 경우
        for (x; x <= i2; x++)
        {
            pickPixel(x, round(y));
            y += m;
        }
    }
    else if (m > 1) {//기울기가 1보다 클 경우
        for (float y = j1; y <= j2; y++) {
            pickPixel(round(x), y);
            x += 1 / m;
        }
    }
}

int main() {
    MidpointLine(7, 1, 16, 6);
}