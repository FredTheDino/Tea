#include "shader.h"

#include <iostream>

namespace Tea {

	GLuint Shader::_currentShader = 0;

	static void checkError(GLuint& target, GLenum check, bool isProgram = false) {

		GLenum err = GL_NO_ERROR;
		while ((err = glGetError()) != GL_NO_ERROR) {
			std::cout << "GL error: " << err << std::endl;
		}

		GLint status = 1;
		if (isProgram)
			glGetProgramiv(target, check, &status);

		else
			glGetShaderiv(target, check, &status);

		if (status != GL_TRUE) {

			char buffer[512];
			if (isProgram)
				glGetProgramInfoLog(target, 512, NULL, buffer);

			else
				glGetShaderInfoLog(target, 512, NULL, buffer);

			if (buffer)
				std::cout << "A shader error occured: " << buffer << std::endl;
		}
	}

	static GLuint makeShader(const std::string& path, GLenum shaderType) {
		GLuint shader = glCreateShader(shaderType);

		std::string middleMan = Loader::readTextFile(path);
		const char* source = middleMan.c_str();

		glShaderSource(shader, 1, &source, NULL);
		glCompileShader(shader);

		checkError(shader, GL_COMPILE_STATUS);

		return shader;
	}

	Shader::Shader(const std::string& path, unsigned int shaderTypes) {

		_program = glCreateProgram();

		if (shaderTypes & ShaderTypes::VERTEX_SHADER) {
			_shaders.push_back(
				makeShader(path + ".vs", GL_VERTEX_SHADER)
				);
		}
		
		if (shaderTypes & ShaderTypes::FRAGMENT_SHADER) {
			_shaders.push_back(
				makeShader(path + ".fs", GL_FRAGMENT_SHADER)
				);
		}
		
		if (shaderTypes & ShaderTypes::TESSELATION_SHADER) {
			_shaders.push_back(
				makeShader(path + ".tes", GL_TESS_EVALUATION_SHADER)
				);
			_shaders.push_back(
				makeShader(path + ".tcs", GL_TESS_CONTROL_SHADER)
				);
		}

		if (shaderTypes & ShaderTypes::GEOMETRY_SHADER) {
			_shaders.push_back(
				makeShader(path + ".gs", GL_GEOMETRY_SHADER)
				);
		}

		for (size_t i = 0; i < _shaders.size(); i++) {
			glAttachShader(_program, _shaders[i]);
		}
		glLinkProgram(_program);
		checkError(_program, GL_LINK_STATUS, true);

		glValidateProgram(_program);

		checkError(_program, GL_VALIDATE_STATUS, true);
	}

	Shader::~Shader() {
		for (size_t i = 0; i < _shaders.size(); i++) {
			glDetachShader(_program, _shaders[i]);
			glDeleteShader(_shaders[i]);
		}

		glDeleteProgram(_program);
	}

	GLuint Shader::getCurrentProgram() {
		return _currentShader;
	}

	void Shader::bind() {
		_currentShader = _program;
		glUseProgram(_program);
	}
}