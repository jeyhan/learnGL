#include "Utils.h"


using namespace std;
namespace Utils {

	void printShaderLog(GLuint shader) {
		int len = 0;
		int chWrittn = 0;
		char* log;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &len);
		if (len > 0) {
			log = (char*)malloc(len);
			glGetShaderInfoLog(shader, len, &chWrittn, log);
			cout << "Shader Info Log:" << log << endl;
			free(log);
		}
	}



	void printProgramLog(GLuint prog) {
		int len = 0;
		int chWrittn = 0;
		char* log;
		glGetProgramiv(prog, GL_INFO_LOG_LENGTH, &len);
		if (len > 0) {
			log = (char*)malloc(len);
			glGetProgramInfoLog(prog, len, &chWrittn, log);
			cout << "Shader Info Log:" << log << endl;
			free(log);
		}
	}

	bool checkOpenGLError() {
		bool foundError = false;
		int glErr = glGetError();
		while (glErr != GL_NO_ERROR) {
			cout << "glError: " << glErr << endl;
			foundError = true;
			glErr = glGetError();
		}
		return foundError;
	}

	string readShaderSource(const char* filePath) {
		string content;
		ifstream fileStream(filePath, ios::in);
		string line = "";

		while (!fileStream.eof()) {
			getline(fileStream, line);
			content.append(line + "\n");
		}
		fileStream.close();
		return content;
	}

	GLuint createShaderProgram(const char* vp, const char* fp) {
		string vshaderSource = readShaderSource(vp);
		string fshaderSource = readShaderSource(fp);

		const char* vShaderSrc = vshaderSource.c_str();
		const char* fShaderSrc = fshaderSource.c_str();

		GLuint vShader = glCreateShader(GL_VERTEX_SHADER);
		GLuint fShader = glCreateShader(GL_FRAGMENT_SHADER);

		glShaderSource(vShader, 1, &vShaderSrc, NULL);
		glShaderSource(fShader, 1, &fShaderSrc, NULL);

		// vertex
		glCompileShader(vShader);
		checkOpenGLError();
		GLint vertCompiled;
		glGetShaderiv(vShader, GL_COMPILE_STATUS, &vertCompiled);
		if (vertCompiled != 1) {
			cout << "vertex compilation failed." << endl;
			printShaderLog(vShader);
		}

		glCompileShader(fShader);
		checkOpenGLError();
		GLint fragCompiled;
		glGetShaderiv(fShader, GL_COMPILE_STATUS, &fragCompiled);
		if (fragCompiled != 1) {
			cout << "fragment compilation failed." << endl;
			printShaderLog(fShader);
		}

		GLuint vfProgram = glCreateProgram();
		glAttachShader(vfProgram, vShader);
		glAttachShader(vfProgram, fShader);
		glLinkProgram(vfProgram);
		checkOpenGLError();
		GLint linked;
		glGetProgramiv(vfProgram, GL_LINK_STATUS, &linked);
		if (linked != 1) {
			cout << "linked failed" << endl;
			printProgramLog(vfProgram);
		}

		return vfProgram;
	}
	GLuint createShaderProgram(const char* vp, const char* gp, const char* fp);
	GLuint createShaderProgram(const char* vp, const char* tCS, const char* tES, const char* fp);
	GLuint createShaderProgram(const char* vp, const char* tCS, const char* tES, const char* gp, const char* fp);
}