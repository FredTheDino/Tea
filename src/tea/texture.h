#pragma once 
#include <string>

#include "include.h"
#include "shader.h"

namespace Tea {

	class Texture {
	public:
		Texture(const std::string& path, unsigned int spritesX = 1, unsigned int spritesY = 1);
		~Texture();

		void bind(const std::string uniformName, char unit = 0);

		void bindSubSprite(unsigned int subSprite);

	private:
		
		unsigned int _sprites[2];

		unsigned int _dimension[2];

		float _spriteDimension[2];

		GLuint _texture;

	};
}