#pragma once

#include "ofMain.h"
namespace unitro{
namespace plants{
	class BasePlant
	{
	public:
		BasePlant(){};
		~BasePlant(){};
		
		virtual void setup(){};
		virtual void update(){};
		virtual void draw(){};
	};
}
}