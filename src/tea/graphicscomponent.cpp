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

	GraphicsComponent::GraphicsComponent(GameObject* parent): Component(parent) {
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
			
		_vertices.push_back(Vertex( 0.0f,  0.5f, 0.0));
		_vertices.push_back(Vertex(-0.5f, -0.5f, 0.0));
		_vertices.push_back(Vertex( 0.5f, -0.5f, 0.0));

		glGenVertexArrays(1, &_vertexArrayObject);
		glBindVertexArray(_vertexArrayObject);
		{
			glGenBuffers(1, &_vertexBufferObject);
			glBindBuffer(GL_ARRAY_BUFFER, _vertexBufferObject);
			glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * _vertices.size(), &_vertices[0], GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
		}
		glBindVertexArray(0);

	}

	void GraphicsComponent::drawEverything(float delta) {

		///*

		if (!_setUp) { init(); }

		glBindBuffer(GL_ARRAY_BUFFER, _vertexBufferObject);
		glUseProgram(_program);
		
		glVertexAttribPointer(glGetAttribLocation(_program, "position"), 3, GL_FLOAT, GL_FALSE, 0, 0);
		glEnableVertexAttribArray(glGetAttribLocation(_program, "position"));
		
		glBindVertexArray(_vertexArrayObject);

		GLenum error = glGetError();
		if (error != GL_NO_ERROR) {
			error += 0;
		}

		for (size_t i = 0; i < _componentList.size(); i++) {
			glDrawArrays(GL_TRIANGLES, 0, (GLsizei) _vertices.size());
		}

		glBindBuffer(GL_ARRAY_BUFFER, 0);

		//*/
		///*

		glBegin(GL_TRIANGLES);
		{
			//glColor3f(1.0, 0.0, 0.0);
			glVertex2f(0 - 0.25, .5 - 0.25);
			//glColor3f(0.0, 1.0, 0.0);
			glVertex2f(-.5 - 0.25, -.5 - 0.25);
			//glColor3f(0.0, 0.0, 1.0);
			glVertex2f(.5 - 0.25, -.5 - 0.25);
		}
		glEnd();
		//*/
	}

	void GraphicsComponent::destroy() {

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glDeleteBuffers(1, &_vertexBufferObject);
	}
}