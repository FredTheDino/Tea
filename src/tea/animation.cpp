#include "animation.h"
#include "animationmanager.h"

#include <iostream>
#include <stdio.h>

namespace Tea {

	template<class T>
	Animation<T>::Animation(T* target) {
		_target = target;
		_timePerFrame = 1.0;
		_type = DIGITAL;
		AnimationManager::addAnimation(this);
	}

	template<class T>
	Animation<T>::Animation(T* target,
							std::vector<T> frames, double timePerFrame,
							AnimationType type, bool repeat):
		_frames(frames), _target(target), _timePerFrame(timePerFrame),
		_type(type), _repeat(repeat) {
		AnimationManager::addAnimation(this);
	}

	template<class T>
	Animation<T>::~Animation() {}

	template<class T>
	void Animation<T>::update(double delta) {
		static double t;
		static double lerp;

		if (!_running) return;

		t += delta;

		lerp = t / _timePerFrame;

		//cout.precision(17);

		//std::cout << std::fixed << lerp << std::endl;

		if (_timePerFrame < t) {
			t -= _timePerFrame;
			_frame++;
		}

		
		switch (_type) {
			case Tea::DIGITAL:

				if (_frames.size() == _frame) {
					if (_repeat) {
						_frame %= _frames.size();
					} else {
						_frame--;
						_running = false;
					}
				}
				(*_target) = _frames[_frame];

				break;
			case Tea::LINEAR:

				if ((_frame != _frames.size() - 1) || _repeat) {
					if (_repeat) {
						_frame %= _frames.size();
					}
					(*_target) = _frames[_frame] + (_frames[(_frame + 1) % _frames.size()] - _frames[_frame]) * lerp;

				} else {
					(*_target) = _frames[_frames.size() - 1];
					_running = false;
				}

				break;
			case Tea::EASE:

				if (_frame != _frames.size() || _repeat) {
					if (_repeat) {
						_frame %= _frames.size();
					}
					(*_target) = _frames[_frame] + (_frames[(_frame + 1) % _frames.size()] - _frames[_frame]) * -(lerp - 2) * lerp * lerp; //(lerp * lerp * (3 - 2 * lerp));
				} else {
					(*_target) = _frames[_frames.size() - 1];
					_running = false;
				}

				break;
			default:
				break;
		}
	}

	template<class T>
	void Animation<T>::setFrames(std::vector<T> frames) {
		_frames = frames;
		(*_target) = _frames[_frame];
	}

	template<class T>
	void Animation<T>::setTimePerFrame(double timePerFrame) {
		_timePerFrame = timePerFrame;
	}

	template<class T>
	void Animation<T>::setAnimationType(AnimationType type) {
		_type = type;
	}

	template<class T>
	void Animation<T>::setRunning(bool running) {
		_running = running;
	}

	template<class T>
	size_t Animation<T>::getFrame() {
		return _frame;
	}
	template<class T>
	double Animation<T>::getTime() {
		return _frame * _timePerFrame;
	}
}