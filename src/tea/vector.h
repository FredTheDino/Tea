#pragma once

#include <vector>

namespace Tea {
	namespace Math {
		class Vec {
		public:
			Vec(int length, float data[]) {
				_length = length;
				_data.reserve(_length);
				for (size_t i = 0; i < length; i++) {
					_data[i] = data[i];
				}
			}

			~Vec();

			float operator[] (int i) {
				return _data[i];
			}

			Vec operator+ (Vec& b) {
				int shortest;

				if (b._length < shortest) {
					shortest = b._length;
				} else {
					shortest = this->_length;
				}
				
				Vec out(shortest, &b._data[0]);

				for (size_t i = 0; i < shortest; i++) {
					out[i] = this->_data[i] + b._data[i];
				}

				return out;
			}

		private:
			int _length;
			std::vector<float> _data;
		};
	}
}
