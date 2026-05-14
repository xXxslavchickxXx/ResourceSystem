#include <iostream>

#include <exampleResource.h>

#include <GLFW/glfw3.h>

int main() {
	system("chcp 65001 < nul");

    glfwInit();
    GLFWwindow* window = glfwCreateWindow(800, 600, "title", nullptr, nullptr);
    glfwMakeContextCurrent(window);

    glewInit();

    glClearColor(0.3, 0.3, 0.8, 1.f);

	resources::ShaderProgram program;
	program.load("assets/shaders/testV.glsl", "assets/shaders/testF.glsl");

    while (true) {
        glClear(GL_COLOR_BUFFER_BIT);



        glfwPollEvents();
        glfwSwapBuffers(window);
    }
}