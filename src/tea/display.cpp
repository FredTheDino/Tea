#include "display.h"
#include <iostream>

//Avoid that circular include
#include "bag.h"

namespace Tea {

	Display::Display() {
		SDL_Init(SDL_INIT_EVERYTHING);
		checkError(__LINE__);

		reset();

		GLenum error = glewInit();
		if (error != GLEW_OK) {
			std::cout << "Glew failed to init" << std::endl;
			std::cerr << "Message: " << glewGetErrorString(error) << std::endl;
			Bag::stop();
		}

		printf("OpenGL info: %s\n", glGetString(GL_VERSION));

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glEnable(GL_TEXTURE_2D);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	}

	Display::~Display() {
		delete _window;
	}

	void Display::reset() {
		_window = SDL_CreateWindow(_info.name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, (int) _info.width, (int) _info.height, _info.type | SDL_WINDOW_OPENGL);
		checkError(__LINE__);

		_context = SDL_GL_CreateContext(_window);
		checkError(__LINE__);

		//Make sure it's actually done what we want, otherwise revert.
		if (_window == NULL) {
			_window = SDL_CreateWindow(_oldInfo.name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, (int)  _oldInfo.width, (int) _oldInfo.height, _oldInfo.type | SDL_WINDOW_OPENGL);

			_context = SDL_GLContext(_window);
		} else {
			//Overwrite the backup
			_oldInfo = _info;
		}

		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, true);
		SDL_GL_SetSwapInterval(_info.vsync);

		//checkError(__LINE__);
	}

	void Display::update() {
		//TODO:
		SDL_GL_SwapWindow(_window);
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		
	}

	void Display::checkError(int line) {
#ifdef IS_DEBUG
		const char* error = SDL_GetError();
		if (*error != '\0') {
			std::cout << "SDL Error: " << error << std::endl;
			std::cout << "Line: " << line << std::endl;
			SDL_ClearError();
		}
#endif
	}

} /* Tea */
