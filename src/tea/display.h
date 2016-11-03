#pragma once

#include "include.h"

#include <string>

namespace Tea {

  /*
    "Display" is a wrapper for the SDL_Window and SDL_Context
    wrapped in one. This is handled by the engine and shouldn't
    require tat much attention form the API user. 
  */

  // An enum to make compleatly wraap SDLx
	enum DisplayType {
		WINDOW = 0,
		FULLSCREEN = SDL_WINDOW_FULLSCREEN,
		BORDERLESS = SDL_WINDOW_FULLSCREEN_DESKTOP,
	};

  // Info
	struct DisplayInfo {
		unsigned char type = 0;

		std::string name = "Display";

		size_t width = 500;
		size_t height = 500;
	
		bool vsync = 0;
  };

	class Display {
	public:
    // Take an input depending on how you want the display
		Display();
		~Display();

    // (Re)creates the display, so changes take effect
    // if they haven't
		void reset();
    // Swaps the buffers and makes the window raedy for
    // the next cycle
		void update();

    // Check if there is an error and print the line supplied.
		void checkError(int line);

    // The title of the window
		std::string getWindowName() { return _info.name; }
		void setWindowName(std::string windowName) { _info.name = windowName; }

    // The width of the window
		size_t getWidth() { return _info.width; }
		void setWidth(size_t width) { _info.width = width; }

    // The height of the window
		size_t getHeight() { return _info.height; }
		void setHeight(size_t height) { _info.height = height; }

    // The display type of the display
		size_t getDisplayType() { return _info.type; }
		void setDisplayType(unsigned char displayType) { _info.type = displayType; }

    // id vertical sync is to be used or not
		bool getVSync() { return _info.vsync; }
		void setVSync(bool vsync) { _info.vsync = vsync; }

	private:
    // A pointer to the window created on the heap by SDL
		SDL_Window* _window;
    // The GL Context that is stored when the window
    // is re created
		SDL_GLContext _context;

    // Thse variables are used to make sure the new info is
    // actually working before it switches, to make wierd swaps 
    // The old info of the display
		DisplayInfo _oldInfo;
		DisplayInfo _info;



	};

}
