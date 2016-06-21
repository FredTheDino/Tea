#pragma once

#include <string>
#include <unordered_map>

#include "include.h"
#include "input.h"

namespace Tea {

	class InputManager {
	public:
		
		static void loadInputFile(std::string filename="input.map");
		static void writeInputFile(std::string filename = "input.map");

		static void addInput(Input input, std::string name);

		static void update();

	private:

		//input to name
		static std::unordered_map<std::string, std::string> _nameMap;
		//name to state
		static std::unordered_map<std::string, InputState> _inputMap;
	};
}
