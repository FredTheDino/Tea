#pragma once 
#include <string>

#include "include.h"
#include "shader.h"

namespace Tea {

  /*
    "Texture" works with "Shader" to create a material that
    can be bound to a "GraphicsComponent" and later renderd on
    screen.
    If the texture has subsprites, they are expected to fill the
    entire sheet by width and hight.
    (Note: the texture allways has sub sprites, there just happens
    to be 1 when we humans say there are none)
  */
  
	class Texture {
	public:
    // Constructor
		Texture(const std::string& path, unsigned int spritesX = 1, unsigned int spritesY = 1);
		~Texture();

    // Binds the texture, the material should take care of this. 
		void bind(const std::string uniformName, char unit = 0);

    // Set the current subsprite
		void bindSubSprite(unsigned int subSprite);

	private:

    // The number of sprites sotred as #X #Y
		unsigned int _sprites[2];

    // The dimensions of the texture
		unsigned int _dimension[2];

    // The dimensions of a single sprite
		float _spriteDimension[2];

    // The OpenGL texture coordinate
		GLuint _texture;
	};
}
