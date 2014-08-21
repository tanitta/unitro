#pragma once
#include "ofMain.h"
#include "BaseEntity.hpp"
#include "BaseEntity.hpp"
#include "../Resources.hpp"
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
			ofEasyCam mainCam;
			Player(){};
			virtual ~Player(){};
			void draw(unitro::Resources& resources){
				ofPushMatrix();
				ofTranslate(kineticModel.pos);
				resources["Player/test.x"]->draw(OF_MESH_FILL);
				ofPopMatrix();
			};

			void update(){
				kineticModel.update();
			};

			ofVec3f getAdressInMatrix(){
				return ofVec3f(
						round(kineticModel.pos.x),
						round(kineticModel.pos.y),
						round(kineticModel.pos.z)
				);
			};

	};
}
}
