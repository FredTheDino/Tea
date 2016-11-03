#pragma once

#include "component.h"
#include "vertex.h"
#include "material.h"

#include <vector>

namespace Tea {

  /*
    "GraphicsComponent" is a specilization of a "Component"
    that handles rendering. It has a material that it binds when rendering
    and relevent data to change the rendering
  */

  class GraphicsComponent : public Component {
	public:
    // A simple constructor
		GraphicsComponent(GameObject* parent, Material* material);
		~GraphicsComponent();

    // Initalizes all graphics component dependencies.
    // This sets up VBOs and VAOs
		static void init();

    // This simply draws EVERYTHING (That is active, ofcourse)
		static void drawEverything(double delta);

    // Sets the current subsprite that should be renderd
		void setSubSprite(unsigned int subSprite) { _subSprite = subSprite; }
    // GEts the active subsprite
    unsigned int getSubSprite() { return _subSprite; }

    // HULK SMASH! This handles deinitalization
		static void destroy();

	private:
    // The material
		Material* _material;

    // The current subsprite
		unsigned int _subSprite;

    // If the setup is compleated
		static bool _setUp;
    // The VBO address on the GPU, I recomend reading up on
    // OpenGL if you are confused
		static GLuint _vertexBufferObject;
    // The VAO address on the GPU, see previouse comment
    static GLuint _vertexArrayObject;
    // The vertices of the mesh, this is a quad for this object
		static std::vector<Vertex> _vertices;
    // A list of all the graphics compoentns
		static std::vector<GraphicsComponent*> _componentList;
	};
}
