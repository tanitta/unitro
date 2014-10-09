#pragma once
#include "ofMain.h"
namespace unitro {
	namespace interface {
		class Keyboard {
			public:
				static vector<bool> is_key_;
				static vector<bool> is_key_down_;
				static vector<bool> is_key_up_;

				Keyboard(){};
				virtual ~Keyboard(){};
		};
	} // namespace interfa
} // namespace unitro
