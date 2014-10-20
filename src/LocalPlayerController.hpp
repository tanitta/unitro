#pragma once
#include "entity/player.hpp"
#include "interface/keyboard.hpp"
namespace unitro {
	class LocalPlayerController {
		private:
			unitro::entity::Player& player_ref_;
			unitro::interface::Keyboard& keyboard_ref_;
		public:
			LocalPlayerController(unitro::interface::Keyboard& keyboard, unitro::entity::Player& p):
				keyboard_ref_(keyboard),
				player_ref_(p)
			{
				player_ref_.kinetic_model_.viscosity_ = 40;
			};
			virtual ~LocalPlayerController(){};

			void setup(){};

			void keyInput(){
				ofVec3f force = ofVec3f(
						(keyboard_ref_.is_key_['a']-keyboard_ref_.is_key_['d'])*100,
						(keyboard_ref_.is_key_down_[32])*5000,
						(keyboard_ref_.is_key_['w']-keyboard_ref_.is_key_['s'])*100
				);
				player_ref_.kinetic_model_.AddForce(force);
			};


			void Update(){
				if(player_ref_.kinetic_model_.pos_.y > 0){
					player_ref_.kinetic_model_.AddForce(ofVec3f(0,-100,0));
				};
				player_ref_.Update();
			};
	};
} // namespace unitro
