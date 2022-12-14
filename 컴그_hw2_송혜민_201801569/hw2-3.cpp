#include<iostream>
#include<glm/glm.hpp>
#include <string>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <cmath>
#include <cstdlib>



using namespace std;

// function to display 4x4 matrix
void display_4x4(string tag, glm::mat4 m4)
{
    cout << tag << '\n';
    for (int col = 0; col < 4; ++col) {
        cout << "| ";
        for (int row = 0; row < 4; ++row) {
            cout << m4[row][col] << '\t';
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
        << "\n| "
        << v3.x << '\t'
        << v3.y << '\t'
        << v3.z << '\t'
        << "\n"
        ;
}


// function to display 4-component vector
void display_v4(string tag, glm::vec4 v4)
{
    cout
        << tag
        << "\n| "
        << v4.x << '\t'
        << v4.y << '\t'
        << v4.z << '\t'
        << v4.w
        << "\n"
        ;
}

// various examples using GLM functions:
int main()
{
    //첫 번째 변환
    glm::mat4 trans = glm::mat4(1.0f);
    trans = glm::rotate(trans, glm::radians(45.0f), glm::vec3(0.0f, 1.0f, 0.0f)); //y축 방향으로 ccw로 45도 회전

    glm::vec4 p1 = trans * glm::vec4(1.0f, 2.0f, 3.0f, 1.0f);//곱하는 순서는 변환*점 임에 유의
    printf("%f, %f, %f\n", p1.x, p1.y, p1.z); //p1출력

    //두 번째 변환
    glm::mat4 translate = glm::translate(glm::mat4(), glm::vec3(-2.0f, 3.0f, 1.0f)); //x축 방향으로 -2, y축 방향으로 +3,z축 방향으로 +1만큼 translate
    glm::vec4 p2 = translate * p1; //곱하는 순서는 변환*점 임에 유의
    printf("%f, %f, %f\n", p2.x, p2.y, p2.z); //p2출력

    //세 번째 변환
    glm::mat4 s = glm::scale(glm::mat4(), glm::vec3(1.5f, -2.0f, 1.0f));
    glm::vec4 p3 = s * p2;//곱하는 순서는 변환*점 임에 유의
    printf("%f, %f, %f\n", p3.x, p3.y, p3.z); //p3출력

    system("pause");
    return 0;

}