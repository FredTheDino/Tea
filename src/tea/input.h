#pragma once

#include <string>
#include <sstream>

namespace Tea {

  /*
    These are all helper classes for the monolithic "InputManager",
    they hold data and  
  */


  // Says the state of an input
	enum InputState {
		KEY_RELEASED = -2,
		KEY_UP = 0,
		KEY_DOWN = 1,
		KEY_PRESSED = 2
	};

  // The different types of events
  // that an input can have
	enum class InputType {
		KEY_DOWN,
		KEY_UP,
		MOUSE_MOVE,
		MOUSE_CLICK,
		MOUSE_RELEASE,
		BUTTON_DOWN,
		BUTTON_UP,
		CONTROLLER_ADD,
		CONTROLLER_REMOVE
	};

  // An "Input" is a collection of 4 pices of data.
  // a device id, which says if it's a keyboard, mouse or
  // which controller it is. Which key or button is being
  // acted upon, if there is an axis, which of the possible ones is it
	struct Input {

    // COnstructors of code use, not recomended for other things than debugging
		Input(int dev, int b, int m): device(dev), button(b), axis(0), mods(m) {};
		Input(int dev, int b, int a, int m): device(dev), button(b), axis(a), mods(m) {};

    // A deserrialisation constructor that is used
    // when loading from a file. 
		Input(const std::string& data) {
			std::stringstream ss(data);
			std::string token;

			if (std::getline(ss, token, ':')) {
				device = atoi(token.c_str());
			} else {
				device = -1;
			}
			if (std::getline(ss, token, ':')) {
				axis = atoi(token.c_str());
			} else {
				axis = 0;
			}
			if (std::getline(ss, token, ':')) {
				button = atoi(token.c_str());
			} else {
				button = -1;
			}
			if (std::getline(ss, token, ':') && device == -1) {
				mods = atoi(token.c_str());
			} else {
				mods = 0;
			}
			if (std::getline(ss, token, ':')) {
				name = token;
			} else {
				name = "";
			}
		}

		int device;
		int button;
		int axis;
		int mods;
		std::string name;
	
		std::string serialize() {
			return getKey() + ":" + name;
		}

    // This function generates the key for this specific input
		std::string getKey() {
			return (std::to_string(device) + ":" + std::to_string(axis) + ":" + std::to_string(button) + ":" + std::to_string(mods));
		}
	};
}
