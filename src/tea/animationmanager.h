#pragma once
#include "animation.h"

#include <vector>

namespace Tea {

	/*
		The "AnimationManager" manages all the animations
		in one easy to use place. This class is static
		and calls the update method on all animation 
		objects. The animations handle the interaction 
		with this object by themselves, all you need to
		do is call "AnimationManager.updateAll(delta);" and
		all your animations will spring to life.
	*/


	template<class T>
	class Animation;
	
	template<class T>
	struct _LinkedAnimationList{
		Animation<T>* value = nullptr;
		_LinkedAnimationList<T>* next = nullptr;
	};



	class AnimationManager {
	public:
		
		// Updates all animations related to this object
		static void updateAll(double delta);

		// Add an animation pointer
		// "Animation" handles this by itself
		static void addAnimation(Animation<int>* anim);
		static void addAnimation(Animation<float>* anim);
		static void addAnimation(Animation<double>* anim);

		// Remove an animation pointer
		// "Animation" handles this by itself
		static void removeAnimation(Animation<int>* anim);
		static void removeAnimation(Animation<float>* anim);
		static void removeAnimation(Animation<double>* anim);

	private:
		// Lists of animation pointers
		static _LinkedAnimationList<int>* _linkedIntList;
		static _LinkedAnimationList<float>* _linkedFloatList;
		static _LinkedAnimationList<double>* _linkedDoubleList;

	};
}