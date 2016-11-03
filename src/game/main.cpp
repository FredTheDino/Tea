#include <iostream>
#include <stdio.h>
#include <math.h>
#include "bag.h"
#include "animation.cpp"
#include "gameobject.cpp"

Tea::GameObject obj;

static double a = 0;
static int frame = 0;

void update(double delta) {
  static unsigned int lastFPS = 0;
  unsigned int newFPS = Tea::Time::getFPS();
  if (lastFPS != newFPS) {
    //std::cout << "FPS: " << newFPS << std::endl;
    lastFPS = newFPS;
  }
  //printf("A: %f\n", a);
  obj.transform._position.x = a;
  Tea::GraphicsComponent* gc;
  obj.getComponent<Tea::GraphicsComponent>(&gc);
  gc->setSubSprite(frame);
  //std::cout << frame << std::endl;
}


int main(int argc, const char* argv[]) {

	Tea::Bag bag;
        
	bag.registerUpdateFunction(update);

	Tea::Time::setMaxFrameRate(0);

	Tea::InputManager::addInput(Tea::Input(-1, SDLK_ESCAPE, 0), "quit");
	
	Tea::Animation<double> anim(&a, {0.1, 0.2, 0.3, 0.4, -0.5}, 0.5, Tea::EASE, true);
	Tea::Animation<int> color(&frame, {0, 1, 2, 3}, 0.5, Tea::DIGITAL, true);
	Tea::Animation<int>* colordelete = new Tea::Animation<int>(&frame, {0, 1, 2, 3}, 0.1, Tea::DIGITAL, true);
	delete colordelete;

	Tea::Shader sh("shader");
	Tea::Texture tex("texture.jpg", 2, 2);
	Tea::Material mat(&sh, &tex);
	
	GLenum err = GL_NO_ERROR;
	while ((err = glGetError()) != GL_NO_ERROR) {
		std::cout << "GL error: " << err << std::endl;
	}

	Tea::GraphicsComponent com(&obj, &mat);
	obj.addComponent<Tea::GraphicsComponent>(&com);

	Tea::GraphicsComponent* c = nullptr;
	obj.getComponent<Tea::GraphicsComponent>(&c);
	c->setSubSprite(2);

	bag.run();

	return 0;
}
