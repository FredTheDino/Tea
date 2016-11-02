#include "animationmanager.h"
#include "animation.cpp"

namespace Tea {

	_LinkedAnimationList<int>* AnimationManager::_linkedIntList = nullptr;
	_LinkedAnimationList<float>* AnimationManager::_linkedFloatList = nullptr;
	_LinkedAnimationList<double>* AnimationManager::_linkedDoubleList = nullptr;

	void AnimationManager::updateAll(double delta) {
		
		// Basic linked list traversial, implemented C-style
		_LinkedAnimationList<int>* iLink = _linkedIntList;
		while (iLink != nullptr) {
			iLink->value->update(delta);
			iLink = iLink->next;
		}

		_LinkedAnimationList<float>* fLink = _linkedFloatList;
		while (fLink != nullptr) {
			fLink->value->update(delta);
			fLink = fLink->next;
		}

		_LinkedAnimationList<double>* dLink = _linkedDoubleList;
		while (dLink != nullptr) {
			dLink->value->update(delta);
			dLink = dLink->next;
		}
	}

	void AnimationManager::addAnimation(Animation<int>* anim) {
		_LinkedAnimationList<int>* link = new _LinkedAnimationList<int>;
		link->value = anim;
		link->next = _linkedIntList;
		_linkedIntList = link;
	}

	void AnimationManager::addAnimation(Animation<float>* anim) {
		_LinkedAnimationList<float>* link = new _LinkedAnimationList<float>;
		link->value = anim;
		link->next = _linkedFloatList;
		_linkedFloatList = link;
	}

	void AnimationManager::addAnimation(Animation<double>* anim) {
		_LinkedAnimationList<double>* link = new _LinkedAnimationList<double>;
		link->value = anim;
		link->next = _linkedDoubleList;
		_linkedDoubleList = link;
	}
	
	void AnimationManager::removeAnimation(Animation<int>* anim) {
		_LinkedAnimationList<int>** link = &_linkedIntList;
		while ((*link)->value != anim && (*link) != nullptr) {
			link = &(*link)->next;
		}

		if (*link == nullptr) {
			return;
		}

		_LinkedAnimationList<int>* deletedLink = (*link);
		(*link) = (*link)->next;
		delete deletedLink;
	}

	void AnimationManager::removeAnimation(Animation<float>* anim) {
		_LinkedAnimationList<float>** link = &_linkedFloatList;
		while ((*link)->value != anim && (*link) != nullptr) {
			link = &(*link)->next;
		}

		if (*link == nullptr) {
			return;
		}

		_LinkedAnimationList<float>* deletedLink = (*link);
		(*link) = (*link)->next;
		delete deletedLink;
	}

	void AnimationManager::removeAnimation(Animation<double>* anim) {
		_LinkedAnimationList<double>** link = &_linkedDoubleList;
		while ((*link)->value != anim && (*link) != nullptr) {
			link = &(*link)->next;
		}

		if (*link == nullptr) {
			return;
		}

		_LinkedAnimationList<double>* deletedLink = (*link);
		(*link) = (*link)->next;
		delete deletedLink;
	}

}