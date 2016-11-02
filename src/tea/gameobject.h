#pragma once

#include "bag.h"

#include "transform.h"
#include "component.h"
#include "vector"

namespace Tea {

	class Component;

	class GameObject {
	public:
		// Unused constructor and destructor
		GameObject();
		~GameObject();

		// Every GameObject has a transform
		Transform transform;

		// Returns a component
		template <typename T>
		bool getComponent(T** component);

		// Adds a component to be associated with this game object
		template <typename T>
		bool addComponent(T* component);

		// Removes a component
		template <typename T>
		bool removeComponent();

		////////////////////////////////////////////
		// A disabled component will NOT be updated
		////////////////////////////////////////////

		// Disables all components
		void disableAllComponents();

		// Enables all components
		void enableAllComponents();

		// Disables a specified component
		template <typename T>
		bool disableComponent();

		// Enables a specified component
		template <typename T>
		bool enableComponent(Component* component);

		// TOggles a specified component
		template <typename T>
		bool toggleComponent(Component* component);

	private:
		// A holder for all the components of this GameObject 
		std::vector<Component*> _components;

	};
}
