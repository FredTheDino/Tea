#pragma once

#include "glm/glm.hpp"
#include "glm/gtx/transform.hpp"

namespace Tea {
  /*
    "Transform" is a data type that holds position, scale
    and rotation data. This transform implementation only
    holds 2 dimensional position, 2 dimensional scale
    and 1 dimensional rotation.
  */
  
 class Transform {
 public:


   // These are all very generic constructors, I think you can figure them out.
Transform(): _position(0.0f, 0.0f), _rotation(0), _scale(1.0f, 1.0f) {};
Transform(float x, float y): _position(x, y), _rotation(0), _scale(1.0f, 1.0f) {};
Transform(float x, float y, float rot): _position(x, y), _rotation(rot), _scale(1.0f, 1.0f) {};
Transform(glm::vec2 pos, float rot, glm::vec2 s): _position(pos), _scale(s), _rotation(rot) {};
   ~Transform() {};

   // Generates a transformation matrix that can be sent to OpenGL directly
    glm::mat4 generateTransformationMatrix() {
      glm::mat4 transformation;
      transformation = glm::translate(transformation, glm::vec3(_position, 0));
      transformation = glm::rotate(transformation, _rotation, glm::vec3(0, 0, 1.0f));
      transformation = glm::scale(transformation, glm::vec3(_scale.x, _scale.y, 1));
      return transformation;
    }

    // The position data
    glm::vec2 _position;
    // The scale data
    glm::vec2 _scale;
    // The rotation stored as radians
    float _rotation;
  };
}
