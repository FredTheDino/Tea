#include "gameobject.h"

namespace Tea {

	// Unused constructor
	GameObject::GameObject() {}

	// Unused destructor
	GameObject::~GameObject() {}

	// A getter function for  components 
	template<typename T>
	bool GameObject::getComponent(T** component) {
		for (size_t i = 0; i < _components.size(); i++) {
			T* object = dynamic_cast<T*>(_components[i]);

			if (object != NULL) {
				// Yay we found it!
				*component = object;
				return true;
			}
		}
		return false;
	}
	
	// Add components
	template <typename T>
	bool GameObject::addComponent(T* component) {
		for (size_t i = 0; i < _components.size(); i++) {
			T* object = dynamic_cast<T*>(_components[i]);

			if (object != NULL) {
				//You can't add the same type of component twice to an object, you silly gose
				return false;
			}
		}
		_components.push_back(dynamic_cast<Component*>(component));
		return true;
	}

	// Delets a component
	template <typename T>
	bool GameObject::removeComponent() {
		for (size_t i = 0; i < _components.size(); i++) {
			T* object = dynamic_cast<T*>(_components[i]);

			if (object != NULL) {
				//We found the object, delete it and return true
				_components.erase(_components.begin() + i);
				return true;
			}
		}
		return false;
	}

	////////////////////////////////////////////////////
	// If a component is disabled the it will not call
	// its update function
	////////////////////////////////////////////////////
	
	// Disables all components
	void GameObject::disableAllComponents() {
		for (size_t i = 0; i < _components.size(); i++) {
			_components[i]->disable();
		}
	}

	// Enables all components
	void GameObject::enableAllComponents() {
		for (size_t i = 0; i < _components.size(); i++) {
			_components[i]->enable();
		}
	}

	// Disables a specified component
	template <typename T>
	bool GameObject::disableComponent() {
		for (size_t i = 0; i < _components.size(); i++) {
			T* object = dynamic_cast<T*>(_components[i]);

			if (object != NULL) {
				//We found the object, delete it and return true
				_components[i]->disable();
				return true;
			}
		}
		return false;
	}

	// Enables a specified component
	template <typename T>
	bool GameObject::enableComponent(Component* component) {
		for (size_t i = 0; i < _components.size(); i++) {
			T* object = dynamic_cast<T*>(_components[i]);

			if (object != NULL) {
				//We found the object, delete it and return true
				_components[i]->enable();
				return true;
			}
		}
		return false;
	}

	// Toggles a component
	template <typename T>
	bool GameObject::toggleComponent(Component* component) {
		for (size_t i = 0; i < _components.size(); i++) {
			T* object = dynamic_cast<T*>(_components[i]);

			if (object != NULL) {
				//We found the object, delete it and return true
				_components[i]->toggle();
				return true;
			}
		}
		return false;
	}
}
