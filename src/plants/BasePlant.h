#pragma once

#include "ofMain.h"
namespace unitro{
namespace plants{
	class BasePlant
	{
	public:
		BasePlant(){};
		~BasePlant(){};
		
		virtual static void setup(){};
		virtual static void update(){};
		virtual static void draw(){};
		
		virtual string name;
		
	};
}
}