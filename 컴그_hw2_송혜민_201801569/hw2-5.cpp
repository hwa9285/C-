#include<iostream>
#include<glm/glm.hpp>
#include <string>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <cmath>
#include <cstdlib>
using namespace std;


int main() {
	glm::vec3 camera = glm::vec3(4.0f,4.0f,4.0f); //카메라 위치

	glm::vec3 cameraTarget = glm::vec3(0.0f, 1.0f, 0.0f); //카메라가 보는 위치
	glm::vec3 z = glm::vec3(camera - cameraTarget);//z축

	glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::vec3 cameraRight = glm::vec3(glm::cross(up, z)); //+x축 벡터

	glm::vec3 cameraUp = glm::cross(z, cameraRight);//+y축 벡터

	printf("%f,%f,%f\n", z.x, z.y, z.z);
	printf("%f,%f,%f\n", cameraRight.x, cameraRight.y, cameraRight.z);
	printf("%f,%f,%f\n", cameraUp.x, cameraUp.y, cameraUp.z);

	system("pause");
	return 0;

}