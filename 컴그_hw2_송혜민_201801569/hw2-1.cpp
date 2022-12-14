#include<iostream>
#include<glm/glm.hpp>
#include <string>
using namespace::std;
void display_v3(string tag, glm::vec3 v3) {
	cout << tag
		<< "\n | "
		<< v3.x << '\t'
		<< v3.y << '\t'
		<< v3.z << '\t'
		<< "\n";
}
int main() {
	glm::vec3 vCross = glm::cross(
		glm::vec3(0.0f, 1.0f, 0.0f), //p1p2벡터
		glm::vec3(2.0f, -1.0f, 3.0f) //p1p3벡터
	);
	display_v3("cross( p1p2, p1p3 )", vCross);
}