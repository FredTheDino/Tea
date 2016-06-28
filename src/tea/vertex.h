#pragma once

#include "glm/glm.hpp"

namespace Tea {

	struct Vertex {

		Vertex(float x, float y, float z): position(x, y, z) {}

		glm::vec3 position;
	};
}
