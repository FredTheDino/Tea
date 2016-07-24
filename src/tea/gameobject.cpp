#include "gameobject.h"

namespace Tea {

	GameObject::GameObject() {}

	GameObject::~GameObject() {}

	template<typename T>
	bool GameObject::getComponent(T** component) {
		for (size_t i = 0; i < _components.size(); i++) {
			T* object = dynamic_cast<T*>(_components[i]);

			if (object != NULL) {
				*component = object;
				return true;
			}
		}
		return false;
	}

	template <typename T>
	bool GameObject::addComponent(T* component) {
		for (size_t i = 0; i < _components.size(); i++) {
			T* object = dynamic_cast<T*>(_components[i]);

			if (object != NULL) {
				//You can't add the same type of component twice to an object
				return false;
			}
		}
		_components.push_back(dynamic_cast<Component*>(component));
		return true;
	}

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

	void GameObject::disableAllComponents() {
		for (size_t i = 0; i < _components.size(); i++) {
			_components[i]->disable();
		}
	}

	void GameObject::enableAllComponents() {
		for (size_t i = 0; i < _components.size(); i++) {
			_components[i]->enable();
		}
	}

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
