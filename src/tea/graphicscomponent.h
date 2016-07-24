#pragma once

#include "component.h"
#include "vertex.h"
#include "material.h"

#include <vector>

namespace Tea {
	class GraphicsComponent : public Component {
	public:
		GraphicsComponent(GameObject* parent, Material* material);
		~GraphicsComponent();

		static void init();

		static void drawEverything(double delta);

		void setSubSprite(unsigned int subSprite) { _subSprite = subSprite; }
		unsigned int getSubSprite() { return _subSprite; }

		static void destroy();

	private:
		Material* _material;

		unsigned int _subSprite;

		static bool _setUp;
		static GLuint _vertexBufferObject;
		static GLuint _vertexArrayObject;
		static std::vector<Vertex> _vertices;
		static std::vector<GraphicsComponent*> _componentList;
	};
}