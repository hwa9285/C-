#include <iostream>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include<glm/glm.hpp>
using namespace std;

double tarea(double a[],double b[],double c[]) {

	glm::vec3 V1 = glm::vec3(b[0]-a[0],b[1]-a[1],b[2]-a[2]); // ����AB
	glm::vec3 V2 = glm::vec3(c[0] - a[0], c[1] - a[1], c[2] - a[2]); //���� AC

	glm::vec3 vCross = glm::cross(V1,V2); //������ ���� ��

	double V = sqrt(pow(vCross.x,2) + pow(vCross.y, 2)+ pow(vCross.z, 2)); //������ ũ�� ����

	return V / 2; //�ﰢ���� ���� ��ȯ
}

int main() {
	double a[3];
	double b[3];
	double c[3];

	cout << "��A�� ��ǥ�� �Է��ϼ���>> ";
	cin >> a[0] >> a[1] >> a[2];

	cout << "��B�� ��ǥ�� �Է��ϼ���>> ";
	cin >> b[0] >> b[1] >> b[2];

	cout << "��C�� ��ǥ�� �Է��ϼ���>> ";
	cin >> c[0] >> c[1] >> c[2];

	cout << "�ﰢ���� ����>> " << tarea(a, b, c);

}