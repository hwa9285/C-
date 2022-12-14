#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
using namespace std;
// function to display 4x4 matrix
void display_4x4(string tag, glm::mat4 m4)
{
	cout << tag << '\n';
	for (int row = 0; row < 4; ++row) {
		cout << "| ";
		for (int col = 0; col < 4; ++col) {
			cout << m4[col][row] << '\t';
		}
		cout << '\n';
	}
	cout << '\n';
}


// function to display 3-component vector
void display_v3(string tag, glm::vec3 v3)
{
	cout
		<< tag
		<< "\n| " << v3.x << '\t'
		<< "\n| " << v3.y << '\t'
		<< "\n| " << v3.z << '\t'
		<< "\n"
		;
}


// function to display 4-component vector
void display_v4(string tag, glm::vec4 v4)
{
	cout
		<< tag
		<< "\n| " << v4.x
		<< "\n| " << v4.y
		<< "\n| " << v4.z
		<< "\n| " << v4.w
		<< "\n"
		;
}

int main()
{
	//5-(a)
	glm::mat4 M{ 1, 0, 0, 0, 
				 0, 1, 0, 0,
				 0, 0, 1, 0,
				 0, 0, -10, 1};

	display_4x4("วเทฤ M", M);

	glm::vec4 v{ 1,2,3,1 };

	display_v4("บคลอ v", v);

	display_v4("บคลอ Mv", M * v);

	//5-(b)
	glm::mat4 I{1,0,0,0,
			0,1,0,0,
			0,0,1,0,
			0,0,0,1};
	display_4x4("วเทฤ I", I);

	display_v4("บคลอ v", v);

	display_v4("บคลอ Iv", I * v);

	return 0;
}