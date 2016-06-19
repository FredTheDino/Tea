#include "display.h"
#include <iostream>

//Avoid that circular include
#include "bag.h"

namespace Tea {

	Display::Display() {
		reset();
	}

	Display::~Display() {
		delete _window;
	}

	void Display::reset() {

		_window = SDL_CreateWindow(_info.name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _info.width, _info.height, _info.type | SDL_WINDOW_OPENGL);

		_context = SDL_GLContext(_window);

		//Make sure it's actually done what we want, otherwise revert.
		if (_window == NULL) {
			_window = SDL_CreateWindow(_oldInfo.name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _oldInfo.width, _oldInfo.height, _oldInfo.type | SDL_WINDOW_OPENGL);

			_context = SDL_GLContext(_window);
		} else {
			//Overwrite the backup
			_oldInfo = _info;
		}
	}

	void Display::update() {

		SDL_Event e;
		while(SDL_PollEvent(&e)) {
			std::cout << "Event triggerd" << std::endl;
			std::cout << "Event type: " << e.type << std::endl;
			if (e.type = SDL_WINDOWEVENT) {
				if (e.window.event == SDL_WINDOWEVENT_CLOSE) {
					Bag::stop();
				}
			}
			if (e.type == SDL_KEYDOWN) {
				Bag::stop();
			}
		}
	}

} /* Tea */
