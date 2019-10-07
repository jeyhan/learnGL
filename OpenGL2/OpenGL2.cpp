#include <math.h>       /* sin */
#include "Utils.h"

#pragma comment(lib,"OpenGL32.lib")

using namespace std;

#define numVAOs 1
GLuint renderingProgram;
GLuint vao[numVAOs];

void init(GLFWwindow* window) {
	renderingProgram = Utils::createShaderProgram("vertTriangleShader.glsl", "fragShader.glsl");
	glGenVertexArrays(numVAOs, vao);
	glBindVertexArray(vao[0]);
}

GLfloat size_p = 0.0f;
GLfloat inc = 1.0f;

void display(GLFWwindow* window, double currentTime) {
	glClear(GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glUseProgram(renderingProgram);

	size_p += inc;
	if (size_p > 50.0f) inc = -1.0f;
	if (size_p < 0.0f) inc = 1.0f;
//	GLuint offsetLoc = glGetUniformLocation(renderingProgram, "offset");
//	glProgramUniform1f(renderingProgram, offsetLoc, x);
//	cout << size_p << endl;
	glPointSize(size_p);

	glDrawArrays(GL_POINTS, 0, 1);
}


int main()
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

