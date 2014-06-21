#pragma once
#include "ofMain.h"
namespace unitro{
namespace env{
	class General
	{
	private:
		General(void){};
	public:
		static double frameRate;
		static ofVec3f matrixSize;
	};
}
}