#include "material.h"

namespace Tea {
	
	Material::Material(Shader* shader): _shader(shader) {}

	Material::~Material() {}

	void Material::bind() {
		_shader->bind();
	}

}