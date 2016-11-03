#pragma once

#include "include.h"

namespace Tea {

  /*
    "Time" is the class in the engine that handles the updates
    as well as timing each cycle to match the specified frame
    rate. The time class delays using SDL_Delay, not the most
    glamoure but it gets the jobb done without too big
    innaccuracies.
  */
  
	class Time {
	public:

    // Tells "Time" it's time for a new cycle
		static void update();

    // Sets the framerate cap you specify
		static void setMaxFrameRate(unsigned char maxFPS = 60);
    // Returns the specified framerate
    static unsigned int getMaxFrameRate() { return _maxFPS; }
    // Get the current delta time
    static double getDelta() { return _delta; }
    // Get the actual framerate 
    static unsigned int getFPS() { return _fps; }

	private:
    // The current delta
		static double _delta;
    // The actual framerate
		static unsigned int _fps;
    // The desierd max FPS
		static unsigned char _maxFPS;
    // The the inverse of the framerate,
    // so it doesn't need to be calculated every frame
		static double _inverseMaxFPS;

	};
}
