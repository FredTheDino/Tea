#pragma once

namespace Tea {
	class GameObject;

	class Component {
	public:
		Component(GameObject* parent): _parent(parent) {}
		virtual ~Component() {}

		virtual void update(float delta) {}

		bool isActive() {
			return _isActive;
		}

		void disable() {
			_isActive = false;
		}

		void enable() {
			_isActive = true;
		}

		void toggle() {
			_isActive = !_isActive;
		}

	protected:

		bool _isActive = true;
		GameObject* _parent;

	};
}

#include "gameobject.h"