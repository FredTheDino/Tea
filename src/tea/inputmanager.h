#pragma once

#include <unordered_map>
#include <map>
#include <string>
#include <vector>
#include <iostream>

#include "glm/glm.hpp"
#include "include.h"
#include "input.h"
//Included bellow
//#include "inputdata.h"
//Forward declaration

namespace Tea {

	class InputManager {
	public:

		static void update();
		//Returns true if it can read it, false otherwise.
		static bool readInputMap(const std::string& path = "input.map");
		static bool writeInputMap(const std::string& path = "");

		static glm::vec2 getMousePos() { return _mousePos; }
		static float getInput(const std::string& name) { return _inputData[name]; }
		static std::string getName(const std::string& key) { return _inputMap[key]; }

		static bool hasInputState(const std::string& name, InputState state) { return getInput(name) == state; }

		static void addInput(unsigned int device, unsigned int button, unsigned int mods, unsigned int axis, const std::string& name);
		static void addInput(Input data, const std::string& name = 0);

	private:
		static void keyEvent(InputType type, unsigned int key, unsigned int mods);
		static void mouseEvent(InputType type, unsigned int button);
		static void controllerEvent(InputType type, unsigned int which, unsigned int button = -1);
		static void mouseMove(float x, float y);
		static void axisEvent(unsigned int which, unsigned int axis, short value);

		static std::string _path;

		//A hashmap to hold all the inputs.
		//Each raw input has a translation into a input name.
		//<device:axis:button:mods> <name>
		static std::unordered_map<std::string, std::string> _inputMap;
		//Each input name is linked to a float. (To support axies on controllers via the same interface)
		//<name> <value>
		static std::unordered_map<std::string, float> _inputData;

		static glm::vec2 _mousePos;
		static std::vector<SDL_GameController*> _controllers;

		//A map that maps each controller to an ID, and reuses them.
		static std::vector<short> _controllerMap;
	};

}
