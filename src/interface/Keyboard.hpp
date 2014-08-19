#pragma once
#include "ofMain.h"
namespace unitro {
	namespace interface {
		class Keyboard {
			public:
				static vector<bool> isKey;
				static vector<bool> isKeyDown;
				static vector<bool> isKeyUp;

				Keyboard(){};
				virtual ~Keyboard(){};
		};
	} // namespace interfa
} // namespace unitro
