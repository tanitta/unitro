#pragma once
#include "keyboard.hpp"
namespace unitro {
	namespace interface {
		class KeyboardController {
			private:
				unitro::interface::Keyboard& keyboard_;
			public:
				KeyboardController(unitro::interface::Keyboard& keyboard):
					keyboard_(keyboard){};

				virtual ~KeyboardController(){};

				void update(){
					for (int i = 0; i < 128; i++) {
						keyboard_.is_key_down_[i] = false;
						keyboard_.is_key_up_[i] = false;
					}
				}

				void SetKeyPressed(int key){
					if(!keyboard_.is_key_[key]){
						keyboard_.is_key_down_[key] = true;
					};
					keyboard_.is_key_[key] = true;
				};

				void SetKeyReleased(int key){
					if(keyboard_.is_key_[key]){
						keyboard_.is_key_up_[key] = true;
					};
					keyboard_.is_key_[key] = false;
				};
		};
	} // namespace interfa
} // namespace unitro
