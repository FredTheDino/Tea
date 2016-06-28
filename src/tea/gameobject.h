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
		bool disableComponent();

		template <typename T>
		bool enableComponent(Component* component);

		template <typename T>
		bool toggleComponent(Component* component);

	private:
		std::vector<Component*> _components;

	};
}
