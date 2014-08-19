#pragma once
#include "Keyboard.hpp"
namespace unitro {
	namespace interface {
		class KeyboardController {
			private:
				unitro::interface::Keyboard keyboard;
			public:
				KeyboardController():
					keyboard(){};

				virtual ~KeyboardController(){};

				void update(){
					for (int i = 0; i < 128; i++) {
						keyboard.isKeyDown[i] = false;
						keyboard.isKeyUp[i] = false;
					}
				}

				void SetKeyPressed(int key){
					keyboard.isKey[key] = true;
					keyboard.isKeyDown[key] = true;
				};

				void SetKeyReleased(int key){
					keyboard.isKey[key] = false;
					keyboard.isKeyUp[key] = true;
				};
		};
	} // namespace interfa
} // namespace unitro
