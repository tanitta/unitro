#pragma once

#include "../plants/BasePlant.h"
#include "../items/BaseItem.h"
namespace unitro{
namespace data{
	class Cell
	{
	public:
		Cell();
		~Cell();
		
		static void SetHandle(Cell* p);
		static void setup();
		static void update();
		static void draw(Cell* p);
		
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