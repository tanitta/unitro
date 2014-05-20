#pragma once

#include "../plants/BasePlant.hpp"
#include "../items/BaseItem.hpp"
namespace unitro{
namespace data{
	class Cell
	{
	public:
		Cell(){
			soil = 0.0;
			water = 0.0;
			temp =  0.0;
			air = 0.0;
			nutP = 0.0;
			nutN = 0.0;
			brightness = 0.0;
		};
		~Cell(){
			
		};
		
		static void SetHandle(Cell* p){};
		static void setup(){};
		static void update(){};
		static void draw(Cell* p){ofDrawBox(0,0,0,p->soil);};
		
		double soil;
		double water;
		double temp;
		double air;
		double nutP;
		double nutN;
		double brightness;
		
		unitro::plants::BasePlant plant;
		unitro::items::BaseItem item;
	private:
		static Cell* pCell;
	};
}	
}