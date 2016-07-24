#pragma once

#include "include.h"

namespace Tea {
	class Time {
	public:

		static void update();

		static void setMaxFrameRate(unsigned char maxFPS = 60);
		static unsigned int getMaxFrameRate() { return _maxFPS; }
		static double getDelta() { return _delta; }
		static unsigned int getFPS() { return _fps; }

	private:

		static double _delta;

		static unsigned int _fps;

		static unsigned char _maxFPS;
		static double _inverseMaxFPS;

	};
}