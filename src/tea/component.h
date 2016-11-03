#pragma once

namespace Tea {
	class GameObject;

  /*
    "Component" is a pice of a "GameObject" with an
    update function that gets called every update.
    These "Component" are the bread and butter and
    what this engien is based on,
  */
  
	class Component {
	public:
		Component(GameObject* parent): _parent(parent) {}
		virtual ~Component() {}

    // Overwritale updatefunction
		virtual void update(float delta) {}

    // If the component is active
		bool isActive() {
			return _isActive;
		}

    // Disable the component
		void disable() {
			_isActive = false;
		}

    // Enable the component
		void enable() {
			_isActive = true;
		}

    // Toggle the component
		void toggle() {
			_isActive = !_isActive;
		}

	protected:

    // If this is on, the update function will be called
		bool _isActive = true;
    // A reffernce to the parent game object, if you ever need it
		GameObject* _parent;

	};
}

#include "gameobject.h"
