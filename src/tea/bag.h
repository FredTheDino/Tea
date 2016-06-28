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

namespace Tea {
	class Bag {
	public:

		Bag();
		~Bag();

		static void init();

		static void run();

		static void stop();

		static void cleanUp();

		static void registerUpdateFunction(void(*function)(float));

	private:

		static std::vector<void(*)(float)> _functions;

		static bool _running;
		static Display* _display;

	};
}
