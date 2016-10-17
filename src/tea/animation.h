#pragma once

#include <vector>
#include <math.h>

namespace Tea {

	// Enum for the different animation types	
	enum AnimationType {
		DIGITAL,
		LINEAR,
		EASE
	};

	// Class declaration for the generic animation class
	template<class T>
	class Animation {
	public:
		

		Animation(T* target);
		Animation(T* target, std::vector<T> frames, 
						   double timePerFrame = 1.0, AnimationType type = DIGITAL, 
						   bool repeat = false);
		~Animation();

		// updates the Animation
		void update(double delta);

		// Setter for the values you want to interpolate between
		void setFrames(std::vector<T> frames);
		// Sets the time per frame of the animation
		void setTimePerFrame(double timePerFrame);
		// Sets the type of the animation
		void setAnimationType(AnimationType type);
		// Wether this animation should run
		void setRunning(bool running);
		
		// Returns the time for each frame
		size_t getFrame();
		// Returns the current time in the animation
		double getTime();

	private:
		// If the animation is running
		bool _running = true;
		// If the animation should repeat
		bool _repeat;

		// The current frame
		size_t _frame = 0;
		// The time for each frame
		double _timePerFrame;
		// The animations blend type
		AnimationType _type;

		// What we are animating
		T* _target;
		// The values to lerp between
		std::vector<T> _frames;
	};
}