#include "bag.h"

namespace Tea {

	std::vector<void(*)(float)> Bag::_functions;
	bool Bag::_running = true;
	Display* Bag::_display = NULL;

	Bag::Bag() {
		init();
	}

	Bag::~Bag() {
		cleanUp();
	}

	void Bag::init() {
		SDL_Init(SDL_INIT_EVERYTHING);
		_display = new Display();
	}

	void Bag::run() {
		while(_running)
			_display->update();
	}

	void Bag::stop() {
		_running = false;
	}

	void Bag::cleanUp() {
		SDL_Quit();
	}

	void Bag::addUpdateCall(void(*function)(float))  {
		_functions;
		_functions.push_back(function);
	}

}
