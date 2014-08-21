#pragma once
#include "ofMain.h"
namespace unitro{
namespace env{
	class General {
		public:
			General(){};
			virtual ~General(){};
		double frameRate;
		ofVec3f matrixSize;
	};
}
}
