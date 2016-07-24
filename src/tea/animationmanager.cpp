#include "animationmanager.h"
#include "animation.cpp"

namespace Tea {
	
	std::vector<Animation<int>*> AnimationManager::_iAnims;
	std::vector<Animation<float>*> AnimationManager::_fAnims;
	std::vector<Animation<double>*> AnimationManager::_dAnims;

	void AnimationManager::updateAll(double delta) {
		
		size_t i = 0;
		for (; i < _iAnims.size(); i++) {
			_iAnims[i]->update(delta);
		}
		
		i = 0;
		for (; i < _fAnims.size(); i++) {
			_fAnims[i]->update(delta);
		}

		i = 0;
		for (; i < _dAnims.size(); i++) {
			_dAnims[i]->update(delta);
		}
	}

	void AnimationManager::addAnimation(Animation<int>* anim) {
		_iAnims.push_back(anim);
	}

	void AnimationManager::addAnimation(Animation<float>* anim) {
		_fAnims.push_back(anim);
	}

	void AnimationManager::addAnimation(Animation<double>* anim) {
		_dAnims.push_back(anim);
	}
}