#pragma once

#include "ofMain.h"
#include "../plants/BasePlant.hpp"
#include "../items/BaseItem.hpp"


namespace unitro{
namespace data{
	class Cell
	{
	public:
		double soil;
		double water;
		double temp;
		double air;
		double nutP;
		double nutN;
		double brightness;
		unitro::plants::BasePlant plant;
		unitro::items::BaseItem item;
		
		Cell():
			soil(0.0),
			water(0.0),
			temp( 0.0),
			air(0.0),
			nutP(0.0),
			nutN(0.0),
			brightness(0.0)
		{};
		
		~Cell(){};
		static void SetNearCell(){};
		
		static void setup(){};
		
		static void update(){};
		
		static void draw(Cell& c, ofVec3f& nearCell){
			ofDrawBox(0,0,0,c.soil);
		};
		
		
	};
}	
}