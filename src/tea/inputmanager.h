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

		/*
		  "InputManager" handles all input events and changes
      them to bools stored in a special kind of input.
      These can be accessed via getInput() which returns
      the appropriate data.

      Each input has a name and that name is used to
      get relevent information about it. Multiple keys
      can have the same name and will have shared data.
      But a single key CANNOT have multiple names.
		*/

    // Updates the input, this progresses inputs from
    // pressed to down and sutch
		static void update();
		// Returns true if it can read it, false otherwise
		static bool readInputMap(const std::string& path = "input.map");
    // Saves the input map to disk as the specified file
    static bool writeInputMap(const std::string& path = "");

    // Returns the mouse position
		static glm::vec2 getMousePos() { return _mousePos; }
    // Returns information associated to a input name
    static float getInput(const std::string& name) { return _inputData[name]; }
    // Gets the name for the specified key
    // (Note: Internally the engine keeps track of they
    // keys, which are determined by they keys.
    // It is not recomented to use this for user input.)
    static std::string getName(const std::string& key) { return _inputMap[key]; }

    // Checks if a named input has the specified state, it's
    // a replacement for writing it in an if statement. 
		static bool hasInputState(const std::string& name, InputState state) { return getInput(name) == state; }

    // Adds a named input which the specified information
		static void addInput(unsigned int device, unsigned int button,
                         unsigned int mods, unsigned int axis,
                         const std::string& name);
    // A wrapper for the other function which takes "Input"
    // instead of constructing it
    static void addInput(Input data, const std::string& name = 0);

	private:
    // All these functions are to make the code more readable
    // they are all part of handleing events but split up
    // to move things out of the switch statement that is
    // allready to big to be easily read
		static void keyEvent(InputType type, unsigned int key, unsigned int mods);
		static void mouseEvent(InputType type, unsigned int button);
		static void controllerEvent(InputType type, unsigned int which, unsigned int button = -1);
		static void mouseMove(float x, float y);
		static void axisEvent(unsigned int which, unsigned int axis, short value);

    // The path that the input.map was read from.
		static std::string _path;

		// A hashmap to hold all the inputs.
		// Each raw input has a translation into a input name.
		// <device:axis:button:mods> <name>
		static std::unordered_map<std::string, std::string> _inputMap;
		// Each input name is linked to a float. (To support axies on controllers via the same interface)
		// <name> <value>
		static std::unordered_map<std::string, float> _inputData;

    // Mouse position, I know, who would have figured?
		static glm::vec2 _mousePos;
    // If there are any controllers connnected, they are handled here
    // The engine does some interesting things with slotting controllers
    // in in this list where they fit
		static std::vector<SDL_GameController*> _controllers;

		// A map that maps each controller to an ID, and reuses them.
		static std::vector<short> _controllerMap;
	};

}
