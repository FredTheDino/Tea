#pragma once

#include <vector>
#include <math.h>

namespace Tea {

	enum AnimationType {
		DIGITAL,
		LINEAR,
		EASE
	};

	template<class T>
	class Animation {
	public:
		
		Animation(T* target);
		Animation(T* target ,std::vector<T> frames, 
						   double timePerFrame = 1.0, AnimationType type = DIGITAL, 
						   bool repeat = false);
		~Animation();

		void update(double delta);

		void setFrames(std::vector<T> frames);
		void setTimePerFrame(double timePerFrame);
		void setAnimationType(AnimationType type);
		void setRunning(bool running);
		
		size_t getFrame();
		double getTime();

	private:

		bool _running = true;
		bool _repeat;

		size_t _frame = 0;
		double _timePerFrame;
		AnimationType _type;

		T* _target;
		std::vector<T> _frames;
	};
}