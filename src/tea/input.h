#pragma once

#include <string>
#include <sstream>

namespace Tea {

	enum InputState {
		KEY_RELEASED = -2,
		KEY_UP = 0,
		KEY_DOWN = 1,
		KEY_PRESSED = 2
	};

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

	struct Input {

		Input(int dev, int b, int m): device(dev), button(b), axis(0), mods(m) {};
		Input(int dev, int b, int a, int m): device(dev), button(b), axis(a), mods(m) {};

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

		std::string getKey() {
			return (std::to_string(device) + ":" + std::to_string(axis) + ":" + std::to_string(button) + ":" + std::to_string(mods));
		}
	};
}
