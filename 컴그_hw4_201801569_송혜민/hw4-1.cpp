#include <iostream>
#include <GL/glut.h>
#include <GL/freeglut.h>
using namespace std;

double distance(double x1,double y1,double x2, double y2) { //1-(1)

	double x = x1 - x2;
	double y = y1 - y2;
	double dist;
	dist = pow(x, 2) + pow(y, 2);
	dist = sqrt(dist);

	return dist;
}

void bary(double PQ,double VQ) {
	double a = VQ/PQ;
	double b = 1 - a;
	


	cout << "a의 값>> " << a << endl;
	cout << "b의 값>> " << b << endl;
}

int main() {
	double x1, x2, y1, y2;

	cout << "점의 x좌표와 y좌표를 입력하세요>> ";
	cin >> x1 >> y1;


	cout << "다른 점의 x좌표와 y좌표를 입력하세요>> ";
	cin >> x2 >> y2;

	double PQ = distance(x1, y1, x2, y2);

	cout << "두 점 사이의 거리>> " << PQ << endl;

	double Rx, Ry;;

	cout << "점 R의 x좌표와 y좌표를 입력하세요>> ";
	cin >> Rx >> Ry;

	double VQ = distance(Rx, Ry, x2, y2); // 선분 VQ의 길이

	bary(PQ,VQ);

}