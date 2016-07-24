#include "texture.h"

#include "loader.h"
#include <cassert>

namespace Tea {

	Texture::Texture(const std::string& path, unsigned int spritesX, unsigned int spritesY) {

		int width, height, numComponents;
		unsigned char* imageData = Loader::loadImage(path, &width, &height, &numComponents);

		if (imageData == NULL)
			std::cerr << "Error loading texture." << std::endl;


		glGenTextures(1, &_texture);
		glBindTexture(GL_TEXTURE_2D, _texture);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		GLenum format;
		switch (numComponents) {
			case 1:
				format = GL_R;
				break;
			case 2:
				format = GL_RG;
				break;
			case 3:
				format = GL_RGB;
				break;
			case 4:
				format = GL_RGBA;
				break;
			default:
				break;
		}

		_dimension[0] = width;
		_dimension[1] = height;

		_sprites[0] = spritesX;
		_sprites[1] = spritesY;

		for (size_t i = 0; i < 2; i++) {
			_spriteDimension[i] = ((float) 1.0f) / ((float) _sprites[i]);
		}

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, format, GL_UNSIGNED_BYTE, imageData);

		Loader::freeImage(imageData);
	}

	Texture::~Texture() {
		glDeleteTextures(1, &_texture);
	}

	void Texture::bind(const std::string uniformName, char unit) {
	
		//assert(!(0 <= unit && unit <= 31));

		glBindTexture(GL_TEXTURE_2D, _texture);
		glActiveTexture(GL_TEXTURE0 + unit);

		glUniform1i(glGetUniformLocation(Shader::getCurrentProgram(), uniformName.c_str()), unit);
	}

	void Texture::bindSubSprite(unsigned int subSprite) {
		glUniform1i(glGetUniformLocation(Shader::getCurrentProgram(), "subSprite"), subSprite);
		glUniform2f(glGetUniformLocation(Shader::getCurrentProgram(), "spriteDimensions"), _spriteDimension[0], _spriteDimension[1]);
	}
}