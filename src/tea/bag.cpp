#include "bag.h"

namespace Tea {

	std::vector<void(*)(double)> Bag::_functions;
	bool Bag::_running = true;
	Display* Bag::_display = NULL;

	Bag::Bag() {
		init();

		InputManager::readInputMap();

		GraphicsComponent::init();

		registerUpdateFunction(GraphicsComponent::drawEverything);
		registerUpdateFunction(AnimationManager::updateAll);
	}

	Bag::~Bag() {
		cleanUp();
		InputManager::writeInputMap();

		GraphicsComponent::destroy();
	}

	void Bag::init() {
		_display = new Display();
		Time::setMaxFrameRate();
	}

	void Bag::run() {
		while (_running) {
			_display->update();
			Time::update();
			InputManager::update();

			for (size_t i = _functions.size(); 0 < i; i--)
				_functions[i - 1](Time::getDelta());

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

	void Bag::registerUpdateFunction(void(*function)(double))  {
		_functions;
		_functions.push_back(function);
	}
}
