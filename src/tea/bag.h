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

		Bag();
		~Bag();

		static void init();

		static void run();

		static void stop();

		static void cleanUp();

		static void registerUpdateFunction(void(*function)(double));

	private:

		static std::vector<void(*)(double)> _functions;

		static bool _running;
		static Display* _display;

	};
}
