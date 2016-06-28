#include "graphicscomponent.h"


namespace Tea {

	static GLuint _program;
	static GLuint _fragmentShader;
	static GLuint _vertexShader;

	GLuint GraphicsComponent::_vertexBufferObject = -1;
	GLuint GraphicsComponent::_vertexArrayObject = -1;
	bool GraphicsComponent::_setUp = false;
	std::vector<Vertex> GraphicsComponent::_vertices;
	std::vector<GraphicsComponent*> GraphicsComponent::_componentList;

	GraphicsComponent::GraphicsComponent(GameObject* parent, Material* material): Component(parent), _material(material) {
		_componentList.push_back(this);

		init();
	}

	GraphicsComponent::~GraphicsComponent() {
		for (size_t i = 0; i < _componentList.size(); i++) {
			if (this == _componentList[i]) {
				_componentList.erase(_componentList.begin() + i);
				break;
			}
		}
	}

	void GraphicsComponent::init() {
		if (_setUp) { return; }
		_setUp = true;
			
		_vertices.push_back(Vertex(-0.5f,  0.5f, 0.0));
		_vertices.push_back(Vertex(-0.5f, -0.5f, 0.0));
		_vertices.push_back(Vertex( 0.5f, -0.5f, 0.0));

		_vertices.push_back(Vertex( 0.5f,  0.5f, 0.0));
		_vertices.push_back(Vertex( 0.5f, -0.5f, 0.0));
		_vertices.push_back(Vertex(-0.5f,  0.5f, 0.0));

		glGenVertexArrays(1, &_vertexArrayObject);
		glBindVertexArray(_vertexArrayObject);
		{
			glGenBuffers(1, &_vertexBufferObject);
			glBindBuffer(GL_ARRAY_BUFFER, _vertexBufferObject);
			glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * _vertices.size(), &_vertices[0], GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
		}
		/*
		DEBUG PART
		THIS NEEDS TO GO SOME TIME IN THE FUTURE!
		*/
		/*
		std::string vertexShaderSource = "#version 150 \n in vec3 position; void main() { gl_Position = vec4(position, 0.5); }";
		std::string fragmentShaderSource = "#version 150 \n out vec4 outColor; void main() { outColor = vec4(1.0, 0.0, 1.0, 1.0); }";

		auto vSource = vertexShaderSource.c_str();
		auto fSource = fragmentShaderSource.c_str();

		_vertexShader = glCreateShader(GL_VERTEX_SHADER);
		_fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

		glShaderSource(_vertexShader, 1, &vSource, NULL);
		glShaderSource(_fragmentShader, 1, &fSource, NULL);

		glCompileShader(_vertexShader);
		{
			GLint status;
			glGetShaderiv(_vertexShader, GL_COMPILE_STATUS, &status);
			if (status != GL_TRUE) {
				char buffer[521];
				glGetShaderInfoLog(_vertexShader, 512, NULL, buffer);
				std::cout << buffer << std::endl;
			}
		}

		glCompileShader(_fragmentShader);
		{
			GLint status;
			glGetShaderiv(_fragmentShader, GL_COMPILE_STATUS, &status);
			if (status != GL_TRUE) {
				char buffer[521];
				glGetShaderInfoLog(_fragmentShader, 512, NULL, buffer);
				std::cout << buffer << std::endl;
			}
		}

		_program = glCreateProgram();
		glAttachShader(_program, _vertexShader);
		glAttachShader(_program, _fragmentShader);

		glLinkProgram(_program);
		{
			GLint status;
			glGetProgramiv(_program, GL_LINK_STATUS, &status);
			if (status != GL_TRUE) {
				char buffer[521];
				glGetProgramInfoLog(_program, 512, NULL, buffer);
				std::cout << buffer << std::endl;
			}
		}

		glValidateProgram(_program);
		{
			GLint status;
			glGetProgramiv(_program, GL_VALIDATE_STATUS, &status);
			if (status != GL_TRUE) {
				char buffer[521];
				glGetProgramInfoLog(_program, 512, NULL, buffer);
				std::cout << buffer << std::endl;
			}
		}

		glUseProgram(_program);
		//*/
		glBindVertexArray(0);
	}

	void GraphicsComponent::drawEverything(float delta) {

		if (!_setUp) { init(); }		
		
		glBindVertexArray(_vertexArrayObject);

		for (size_t i = 0; i < _componentList.size(); i++) {
			_componentList[i]->_material->bind();
			glDrawArrays(GL_TRIANGLES, 0, (GLsizei) _vertices.size());
		}

		glBindVertexArray(0);
	}

	void GraphicsComponent::destroy() {
		glBindVertexArray(_vertexArrayObject);
		glDeleteBuffers(1, &_vertexBufferObject);
		glBindVertexArray(0);
		glDeleteVertexArrays(1, &_vertexArrayObject);
	}
}