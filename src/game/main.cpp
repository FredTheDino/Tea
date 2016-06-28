#include <iostream>
#include "bag.h"
#include "gameobject.cpp"

int main(int argc, const char* argv[]) {

	Tea::Bag bag;

	Tea::InputManager::addInput(Tea::Input(-1, SDLK_ESCAPE, 0), "quit");

	
	Tea::GameObject obj;
	Tea::GraphicsComponent com(&obj);
	obj.addComponent<Tea::GraphicsComponent>(&com);
	

	bag.run();

	/*
#ifdef IS_DEBUG
		std::cout << "Enter any key to continue..." << std::endl;
		int tmp;
		std::cin >> tmp;
#endif
*/

	return 0;
}
