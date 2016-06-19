#pragma once

#include <vector>

#include "include.h"
#include "display.h"

namespace Tea {
	class Bag {
	public:

		Bag();
		~Bag();

		static void init();

		static void run();

		static void stop();

		static void cleanUp();

		static void addUpdateCall(void(*function)(float));

	private:

		static std::vector<void(*)(float)> _functions;

		static bool _running;
		static Display* _display;

	};
}