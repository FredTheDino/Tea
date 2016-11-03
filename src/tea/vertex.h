#pragma once

#include "glm/glm.hpp"

namespace Tea {

  /*
    "Vertex" is just a simple abstract datatype for OpenGL
    buffers to transfer data to OpenGL.
  */
  
  struct Vertex {

    // Constructor for the vertex, simply assignes the position data.
   Vertex(float x, float y, float z): position(x, y, z) {}

    // The position data of the vertex
    glm::vec3 position;
  };
}
