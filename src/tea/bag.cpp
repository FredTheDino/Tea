#include "bag.h"

namespace Tea {

	std::vector<void(*)(float)> Bag::_functions;
	bool Bag::_running = true;
	Display* Bag::_display = NULL;

	Bag::Bag() {
		init();

		InputManager::readInputMap();

		GraphicsComponent::init();

		registerUpdateFunction(GraphicsComponent::drawEverything);
	}

	Bag::~Bag() {
		cleanUp();
		InputManager::writeInputMap();

		GraphicsComponent::destroy();
	}

	void Bag::init() {
		_display = new Display();
	}

	void Bag::run() {
		while (_running) {
			_display->update();
			InputManager::update();

			for (size_t i = _functions.size(); 0 < i; i--)
				_functions[i - 1](0.0f);

			if (InputManager::hasInputState("quit", InputState::KEY_RELEASED))
				stop();
		}
	}

	void Bag::stop() {
		_running = false;
	}

	void Bag::cleanUp() {
		SDL_Quit();
	}

	void Bag::registerUpdateFunction(void(*function)(float))  {
		_functions;
		_functions.push_back(function);
	}
}
