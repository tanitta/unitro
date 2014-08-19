#pragma once
#include "ofMain.h"
#include "BaseEntity.hpp"
#include "BaseEntity.hpp"
#include "../Resources.hpp"
namespace unitro{
namespace entity{
	class Player: public unitro::entity::BaseEntity {
		public:
			ofEasyCam mainCam;
			Player(){};
			virtual ~Player(){};
			void draw(unitro::Resources& resources){
				resources["Player/text.x"]->setPosition(kineticModel.pos.x, kineticModel.pos.y, kineticModel.pos.z);
				resources["Player/test.x"]->draw(OF_MESH_FILL);
			};

			void update(){
				kineticModel.ResetForce();
			};

	};
}
}
