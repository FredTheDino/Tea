#include <iostream>
#include <math.h>
#include "bag.h"
#include "animation.cpp"
#include "gameobject.cpp"

Tea::GameObject obj;

static double a = 0;

void update(double delta) {
	static unsigned int lastFPS = 0;
	unsigned int newFPS = Tea::Time::getFPS();
	if (lastFPS != newFPS) {
		//std::cout << "FPS: " << newFPS << std::endl;
		lastFPS = newFPS;
	}

	static double time = 0;

	time += delta;

	//std::cout << "A: " << a << std::endl;

	obj.transform._position.x = (float) sin(time) * 0.5;
	obj.transform._position.y = (float) cos(time) * 0.5;

}


int main(int argc, const char* argv[]) {

	Tea::Bag bag;

	bag.registerUpdateFunction(update);

	Tea::Time::setMaxFrameRate(0);

	Tea::InputManager::addInput(Tea::Input(-1, SDLK_ESCAPE, 0), "quit");
	
	Tea::Animation<double> anim(&a, {1.0, 2.0, 3.0, 4.0}, 5.0, Tea::LINEAR, false);

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
