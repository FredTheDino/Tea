#include "time.h"

namespace Tea {

	double Time::_delta = 0;
	unsigned int Time::_fps = 0;
	unsigned char Time::_maxFPS = 0;
	double Time::_inverseMaxFPS = 0;

	void Time::update() {
		static unsigned int currentLoop = 0;
		static unsigned int lastLoop = 0;
		static unsigned int frames = 0;
		static double timer = 0;

		currentLoop = SDL_GetTicks();

		_delta = (double) (currentLoop - lastLoop) / 1000.0;

		timer += _delta;
		if (1.0f <= timer) {
			_fps = frames;
			frames = 0;
			timer = 0;
		}

		if (_inverseMaxFPS != 0.0f && _delta < _inverseMaxFPS) {
			int t = (int) ((_inverseMaxFPS - _delta) * 1000.0f);
			SDL_Delay(t);
		}

		lastLoop = currentLoop;
		frames++;
	}

	void Time::setMaxFrameRate(unsigned char maxFPS) {
		_maxFPS = maxFPS;

		//Special case for unlimited, also avoids divide by 0
		if (_maxFPS == 0) {
			_inverseMaxFPS = 0;
		} else {
			_maxFPS++;
			_inverseMaxFPS = 1.0 / _maxFPS;
		}
		
		return;
	}
}