#pragma once 
#include "shader.h"
#include "texture.h"

namespace Tea {
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