#pragma once

#include "bag.h"

#include "transform.h"
#include "component.h"
#include "vector"

namespace Tea {

	class Component;

	class GameObject {
	public:
		GameObject();
		~GameObject();

		Transform transform;

		template <typename T>
		bool addComponent(T* component);

		template <typename T>
		bool removeComponent();

		void disableAllComponents();

		void enableAllComponents();

		template <typename T>
		void disableComponent();

		template <typename T>
		void enableComponent(Component* component);

		template <typename T>
		void toggleComponent(Component* component);

	private:
		std::vector<Component*> _components;

	};
}