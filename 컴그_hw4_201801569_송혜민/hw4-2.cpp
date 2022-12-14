#include <iostream>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include<glm/glm.hpp>
using namespace std;

double tarea(double a[],double b[],double c[]) {

	glm::vec3 V1 = glm::vec3(b[0]-a[0],b[1]-a[1],b[2]-a[2]); // º¤ÅÍAB
	glm::vec3 V2 = glm::vec3(c[0] - a[0], c[1] - a[1], c[2] - a[2]); //º¤ÅÍ AC

	glm::vec3 vCross = glm::cross(V1,V2); //º¤ÅÍÀÇ ¿ÜÀû °ª

	double V = sqrt(pow(vCross.x,2) + pow(vCross.y, 2)+ pow(vCross.z, 2)); //º¤ÅÍÀÇ Å©±â ¿¬»ê

	return V / 2; //»ï°¢ÇüÀÇ ³ÐÀÌ ¹ÝÈ¯
}

int main() {
	double a[3];
	double b[3];
	double c[3];

	cout << "Á¡AÀÇ ÁÂÇ¥¸¦ ÀÔ·ÂÇÏ¼¼¿ä>> ";
	cin >> a[0] >> a[1] >> a[2];

	cout << "Á¡BÀÇ ÁÂÇ¥¸¦ ÀÔ·ÂÇÏ¼¼¿ä>> ";
	cin >> b[0] >> b[1] >> b[2];

	cout << "Á¡CÀÇ ÁÂÇ¥¸¦ ÀÔ·ÂÇÏ¼¼¿ä>> ";
	cin >> c[0] >> c[1] >> c[2];

	cout << "»ï°¢ÇüÀÇ ³ÐÀÌ>> " << tarea(a, b, c);

}