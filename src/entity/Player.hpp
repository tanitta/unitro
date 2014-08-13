#pragma once
#include "ofMain.h"
#include "BaseEntity.hpp"
#include "BaseEntity.hpp"
namespace unitro{
namespace entity{
	class Player: public unitro::entity::BaseEntity {
		public:
			ofEasyCam mainCam;
			Player(){};
			virtual ~Player(){};
			void draw(){};
			void update(){};

	};
}
}
