#pragma once 
#include "shader.h"
#include "texture.h"

namespace Tea {

  /*
    "Material" is a collection of a "Shader" and a
    "Texture" which in turn can be bound to a "GraphicsComponent"
    and be renderd to the screen.

    A "Shader" and "Texture" can be used in multiple "Materials".
  */

  class Material {
	public:
		Material(Shader* shader, Texture* texture);
		~Material();

		void bind();
		void bindSubSprite(unsigned int subSprite);

	private:
		Shader* _shader;
		Texture* _texture;
	};
}
