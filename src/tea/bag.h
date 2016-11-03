#pragma once

#ifdef _DEBUG
#define IS_DEBUG 
#endif

#include <vector>

#include "include.h"
#include "display.h"

#include "inputmanager.h"
#include "graphicscomponent.h"
#include "loader.h"
#include "time.h"
#include "animation.h"
#include "animationmanager.h"

namespace Tea {
	class Bag {
	public:

    /*
      "Bag" is your primary controller for the Tea API. It
      handles the general things like starting and stopping. 
    */

    // Initalizes the bag setup things that can be setup.
		Bag();
    // Destroy everything that needs destroying.
		~Bag();

    // Initalize the API, nothing can be garanteed to work
    // before this is called, which is in the constructor. 
		static void init();

    // Start the loop and run the engine
		static void run();

    // Stop the engine
		static void stop();

    // Clean up the memory
		static void cleanUp();

    // Register a function to be called on update
		static void registerUpdateFunction(void(*function)(double));

	private:

    // Holder of functions to be called when updating
		static std::vector<void(*)(double)> _functions;

    // Is the API running?
		static bool _running;
    // A refference to the display
		static Display* _display;

	};
}
