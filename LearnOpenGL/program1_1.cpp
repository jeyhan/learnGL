#include "common.h"

using namespace std;

void init(GLFWwindow* window) {}

void display(GLFWwindow* window, double currentTime) {
	double red = sin(currentTime - currentTime / 3.1415926) / 2 + 0.5;
	double green = sin(currentTime - currentTime / 3.1415926 + 3.1415926 * 2 / 3) / 2 + 0.5;
	double blue = sin(currentTime - currentTime / 3.1415926 + 3.1415926 * 4 / 3) / 2 + 0.5;
	glClearColor(red, green, blue, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
}


int main1()
{
	if (!glfwInit()) {
		exit(EXIT_FAILURE);
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	GLFWwindow* window = glfwCreateWindow(600, 600, "Jinwei's First OpenGL Application", NULL, NULL);
	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK) exit(EXIT_FAILURE);

	glfwSwapInterval(1);
	init(window);

	while (!glfwWindowShouldClose(window)) {
		display(window, glfwGetTime());
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
}