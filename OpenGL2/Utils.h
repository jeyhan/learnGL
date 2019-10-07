#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <string>
#include <iostream>
#include <fstream>

namespace Utils {
	GLuint createShaderProgram(const char* vp, const char* fp);
	GLuint createShaderProgram(const char* vp, const char* gp, const char* fp);
	GLuint createShaderProgram(const char* vp, const char* tCS, const char* tES, const char* fp);
	GLuint createShaderProgram(const char* vp, const char* tCS, const char* tES, const char* gp, const char* fp);
}