#include <iostream>
#include <GL/glut.h> 
#include<math.h>
using namespace std;

class Point {
public:
    float x, y;
    void setxy(float x2, float y2)
    {
        x = x2; y = y2;
    }
    //operator overloading for '=' sign
    const Point& operator=(const Point& rPoint)
    {
        x = rPoint.x;
        y = rPoint.y;
        return *this;
    }

};

void drawDot(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    glFlush();
}

void drawLine(Point p1, Point p2) {
    glBegin(GL_LINES);
    glVertex2f(p1.x, p1.y);
    glVertex2f(p2.x, p2.y);
    glEnd();
    glFlush();
}

int factorial(int n)
{
    if (n <= 1)
        return(1);
    else
        n = n * factorial(n - 1);
    return n;
}

float binomial_coff(float n, float k)
{
    float ans;
    ans = factorial(n) / (factorial(k) * factorial(n - k));
    return ans;
}

int SCREEN_HEIGHT = 500;
int clicks = 4;

Point drawBezier(Point PT[], double t) {
    Point P;
    P.x = pow((1 - t), 3) * PT[0].x + 3 * t * pow((1 - t), 2) * PT[1].x + 3 * (1 - t) * pow(t, 2) * PT[2].x + pow(t, 3) * PT[3].x;
    P.y = pow((1 - t), 3) * PT[0].y + 3 * t * pow((1 - t), 2) * PT[1].y + 3 * (1 - t) * pow(t, 2) * PT[2].y + pow(t, 3) * PT[3].y;

    return P;
}


//Calculate the bezier point [generalized]


Point drawBezierGeneralized(Point PT[], double t) {
    Point P;
    P.x = 0; P.y = 0;
    for (int i = 0; i < clicks; i++)
    {
        P.x = P.x + binomial_coff((float)(clicks - 1), (float)i) * pow(t, (double)i) * pow((1 - t), (clicks - 1 - i)) * PT[i].x;
        P.y = P.y + binomial_coff((float)(clicks - 1), (float)i) * pow(t, (double)i) * pow((1 - t), (clicks - 1 - i)) * PT[i].y;
    }
    //cout<<P.x<<endl<<P.y;
    //cout<<endl<<endl;
    return P;
}


float controlPoints1[4][3] = { {0.0,15.0}, {5.0,17.0},{16.0,16.0},{17.0,5.0} };
float controlPoints2[4][3] = { {17.0,5.0}, { 16.0, -5.0 }, { 6.0, -10.0 }, { -3.0,0.0 } };

void Bezier_Cureve(float ControlPoints[][3]) {
    Point abc[20];
    int points = 0;

    for (int i = 0; i < 4; i++) {
        int j = 0;
        abc[points].setxy(ControlPoints[i][j], ControlPoints[i][j+1]);
        drawDot(abc[points].x, abc[points].y);
        points++; //루프문이 종료되면 포인트는 4가됨
    }
    glColor3f(0.2, 1.0, 0.0);
    for (int j = 0; j < 3; j++) {//4개를 각각 선형보간하는 부분
        drawLine(abc[j], abc[j + 1]);
    }

    Point P0 = abc[0];


    glColor3f(0.0, 0.0, 0.0);
    for (float t = 0.0; t <= 1.0; t += 0.02) {
        Point P1 = drawBezierGeneralized(abc, t);
        cout << P0.x << "  ,  " << P0.y << endl;
        cout << P1.x << "  ,  " << P1.y << endl;
        cout << endl;
        drawLine(P0, P1);
        P0 = P1;
    }

}


void Draw()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_LINE_STRIP); //5의 윗부분 직선구간
	glVertex3f(0.0, 15.0, 0.0);
	glVertex3f(5.0, 30.0, 0.0);
	glVertex3f(17.5, 30.0, 0.0);
	glEnd();

    Bezier_Cureve(controlPoints1);
    glEnd();


    Bezier_Cureve(controlPoints2);
    
	glEnd();
	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("HW5-3");
	glutDisplayFunc(Draw);
	gluOrtho2D(-25, 50, -25, 50);
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glutMainLoop();

	return 0;
}