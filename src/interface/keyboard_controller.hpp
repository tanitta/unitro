#pragma once
#include "keyboard.hpp"
namespace unitro {
	namespace interface {
		class KeyboardController {
			private:
				unitro::interface::Keyboard& keyboard_ref_;
			public:
				KeyboardController(unitro::interface::Keyboard& keyboard):
					keyboard_ref_(keyboard){};

				virtual ~KeyboardController(){};

				void Update(){
					for (int i = 0; i < 128; i++) {
						keyboard_ref_.is_key_down_[i] = false;
						keyboard_ref_.is_key_up_[i] = false;
					}
				}

				void SetKeyPressed(int key){
					if(!keyboard_ref_.is_key_[key]){
						keyboard_ref_.is_key_down_[key] = true;
					};
					keyboard_ref_.is_key_[key] = true;
				};

				void SetKeyReleased(int key){
					if(keyboard_ref_.is_key_[key]){
						keyboard_ref_.is_key_up_[key] = true;
					};
					keyboard_ref_.is_key_[key] = false;
				};
		};
	} // namespace interfa
} // namespace unitro