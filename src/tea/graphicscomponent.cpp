#include "graphicscomponent.h"


namespace Tea {

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
		glBindVertexArray(0);
	}

	void GraphicsComponent::drawEverything(double delta) {

		if (!_setUp) { init(); }		
		
		glBindVertexArray(_vertexArrayObject);
		for (size_t i = 0; i < _componentList.size(); i++) {
			_componentList[i]->_material->bind();
			_componentList[i]->_material->bindSubSprite(_componentList[i]->_subSprite);

			glm::mat4 matrix = _componentList[i]->_parent->transform.generateTransformationMatrix();
			glUniformMatrix4fv(glGetUniformLocation(Shader::getCurrentProgram(), "translationMatrix"), 1, GL_FALSE, &matrix[0][0]);

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