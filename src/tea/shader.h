#pragma once
#include <string>
#include <vector>
#include <unordered_map>

#include "include.h"
#include "loader.h"

namespace Tea {


  /*
    "Shader" is a part of the rendering pipeline,
    and creates a material with a "Texture" that can be
    assigned to a "GraphicsComponent" that later can be
    renderd to the screen.

    The shader type is to allow the user to specify which
    types of shader they want in the shader.
    If they for example want a VertexShader a FragmentShader
    and TesselationShader, one would use this constructor:
        Shader("path/to/shader", ShaderTypes::VERTEX_SHADER &
                                 ShaderTypes::FRAGMENT_SHADER &
                                 ShaderTypes::TESSELATIOn_SHADER);
  */

  // An enum to make shader creation very readable
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

    // Returns the currently active shader
		static GLuint getCurrentProgram();

    // Makes this shader the active shader
		void bind();

	private:

    // The current shader
		static GLuint _currentShader;

    // All the pices of this shader, like the
    // FragmentShader and the VertexShader, which hold
    // seperate addressen on the GPU
		std::vector<GLuint> _shaders;
    // This specific shaders
		GLuint _program;
	};
}
