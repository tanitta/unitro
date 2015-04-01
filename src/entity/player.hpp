#pragma once
#include "ofMain.h"
#include "base_entity.hpp"
#include "../resources.hpp"
namespace unitro{
namespace entity{
	class Player: public unitro::entity::BaseEntity {
		private:
			double round(double r){
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
			void draw(unitro::Resources& resources){
				ofPushMatrix();
				ofTranslate(kinetic_model_.pos_);
				resources["Player/test.x"]->draw(OF_MESH_FILL);
				ofPopMatrix();
			};

			void update(){
				kinetic_model_.update();
			};

			ofVec3f get_adress_in_matrix(){
				return ofVec3f(
						round(kinetic_model_.pos_.x),
						round(kinetic_model_.pos_.y),
						round(kinetic_model_.pos_.z)
				);
			};

	};
}
}
