#pragma once 
#include "shader.h"

namespace Tea {
	class Material {
	public:
		Material(Shader* shader);
		~Material();

		void bind();

	private:
		Shader* _shader;
		//Texture* _texture;
	};
}