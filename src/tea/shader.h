#pragma once
#include <string>
#include <vector>
#include <unordered_map>

#include "include.h"
#include "loader.h"

namespace Tea {
	
	enum ShaderTypes {
		VERTEX_SHADER = 1,
		FRAGMENT_SHADER = 2,
		TESSELATION_SHADER = 4,
		GEOMETRY_SHADER = 8
	};
	
	class Shader {
	public:
		Shader(const std::string& path, unsigned int shaderTypes = 3);
		~Shader();

		static GLuint getCurrentProgram();

		void bind();

	private:

		static GLuint _currentShader;

		std::vector<GLuint> _shaders;
		GLuint _program;
	};
}