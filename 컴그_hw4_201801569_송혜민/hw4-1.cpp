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
	


	cout << "a�� ��>> " << a << endl;
	cout << "b�� ��>> " << b << endl;
}

int main() {
	double x1, x2, y1, y2;

	cout << "���� x��ǥ�� y��ǥ�� �Է��ϼ���>> ";
	cin >> x1 >> y1;


	cout << "�ٸ� ���� x��ǥ�� y��ǥ�� �Է��ϼ���>> ";
	cin >> x2 >> y2;

	double PQ = distance(x1, y1, x2, y2);

	cout << "�� �� ������ �Ÿ�>> " << PQ << endl;

	double Rx, Ry;;

	cout << "�� R�� x��ǥ�� y��ǥ�� �Է��ϼ���>> ";
	cin >> Rx >> Ry;

	double VQ = distance(Rx, Ry, x2, y2); // ���� VQ�� ����

	bary(PQ,VQ);

}