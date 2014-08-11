#pragma once
#include "ofMain.h"
namespace unitro{
namespace entity{
	class UserPlayer {
		public:
			ofEasyCam mainCam;
			UserPlayer(){};
			virtual ~UserPlayer(){};
			void draw(){};
			void update(){};

	};
}
}
