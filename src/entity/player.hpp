#pragma once
#include "ofMain.h"
#include "base_entity.hpp"
#include "../resources.hpp"
namespace unitro{
namespace entity{
	class Player: public unitro::entity::BaseEntity {
		private:
			double Round(double r){
				double z = r;
				if(r > 0){
					z = floor(r + 0.5);
				}else if(r < 0){
					z = ceil(r - 0.5);
				}

				return z;
			}

		public:
			ofEasyCam main_cam_;
			Player(){};
			virtual ~Player(){};
			void Draw(unitro::Resources& resources){
				ofPushMatrix();
				ofTranslate(kinetic_model_.pos_);
				resources["Player/test.x"]->draw(OF_MESH_FILL);
				ofPopMatrix();
			};

			void Update(){
				kinetic_model_.Update();
			};

			ofVec3f GetAdressInMatrix(){
				return ofVec3f(
						Round(kinetic_model_.pos_.x),
						Round(kinetic_model_.pos_.y),
						Round(kinetic_model_.pos_.z)
				);
			};

	};
}
}
