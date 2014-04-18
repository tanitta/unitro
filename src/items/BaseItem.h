#pragma once

#include "ofMain.h"
namespace unitro{
namespace items{
	class BaseItem
	{
	public:
		BaseItem();
		~BaseItem();
		
		virtual static void setup(){};
		virtual static void update(){};
		virtual static void draw(){};
		
		virtual string name;
		
	};
}
}