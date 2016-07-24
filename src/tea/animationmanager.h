#pragma once
#include "animation.h"

#include <vector>

namespace Tea {

	template<class T>
	class Animation;

	class AnimationManager {
	public:
		
		static void updateAll(double delta);

		static void addAnimation(Animation<int>* anim);
		static void addAnimation(Animation<float>* anim);
		static void addAnimation(Animation<double>* anim);

	private:
		static std::vector<Animation<int>*> _iAnims;
		static std::vector<Animation<float>*> _fAnims;
		static std::vector<Animation<double>*> _dAnims;

	};
}