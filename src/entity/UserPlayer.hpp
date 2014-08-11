#pragma once
#include "ofMain.h"
#include "BaseEntity.hpp"
#include "BaseEntity.hpp"
namespace unitro{
namespace entity{
	class UserPlayer: public unitro::entity::BaseEntity {
		public:
			ofEasyCam mainCam;
			UserPlayer(){};
			virtual ~UserPlayer(){};
			void draw(){};
			void update(){};

	};
}
}
