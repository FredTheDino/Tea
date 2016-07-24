#include "material.h"

namespace Tea {
	
	Material::Material(Shader* shader, Texture* texture): _shader(shader), _texture(texture) {}

	Material::~Material() {}

	void Material::bind() {
		_shader->bind();
		_texture->bind("texture", 0);
	}

	void Material::bindSubSprite(unsigned int subSprite) {
		_texture->bindSubSprite(subSprite);
	}

}