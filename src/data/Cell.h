#include "../plants/BasePlant.h"
#include "../items/BaseItem.h"
namespace unitro{
namespace data{
	class Cell
	{
	public:
		Cell();
		~Cell();
		
		static void setup(){};
		static void update(){};
		static void draw(){};
		
		double soil;
		double water;
		double temp;
		double air;
		double nutP;
		double nutN;
		double brightness;
		
		unitro::plants::BasePlant plant;
		unitro::items::BaseItem item;
	};
}	
}