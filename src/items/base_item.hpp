#pragma once

#include "ofMain.h"
namespace unitro{
namespace items{
	class BaseItem
	{
	public:
		BaseItem(){};
		~BaseItem(){};
		
		virtual void setup(){};
		virtual void update(){};
		virtual void draw(){};		
	};
}
}
