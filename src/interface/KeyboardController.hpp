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
					if(!keyboard.isKey[key]){
						keyboard.isKeyDown[key] = true;
					};
					keyboard.isKey[key] = true;
				};

				void SetKeyReleased(int key){
					if(keyboard.isKey[key]){
						keyboard.isKeyUp[key] = true;
					};
					keyboard.isKey[key] = false;
				};
		};
	} // namespace interfa
} // namespace unitro
