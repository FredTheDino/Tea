#pragma once

#include "include.h"

#include <string>

namespace Tea {

	enum DisplayType {
		WINDOW = 0,
		FULLSCREEN = SDL_WINDOW_FULLSCREEN,
		BORDERLESS = SDL_WINDOW_FULLSCREEN_DESKTOP,
	};

	struct DisplayInfo {
		unsigned char type = 0;

		std::string name = "Display";

		size_t width = 400;
		size_t height = 500;
	};

	class Display {
	public:
		Display();
		~Display();

		void reset();
		void update();

		std::string getWindowName() { return _info.name; }
		void setWindowName(std::string windowName) { _info.name = windowName; }

		size_t getWidth() { return _info.width; }
		void setWidth(size_t width) { _info.width = width; }

		size_t getHeight() { return _info.height; }
		void setHeight(size_t height) { _info.height = height; }

		size_t getDisplayType() { return _info.type; }
		void setDisplayType(unsigned char displayType) { _info.type = displayType; }

	private:
		SDL_Window* _window;
		SDL_GLContext _context;

		DisplayInfo _oldInfo;
		DisplayInfo _info;



	};

}
