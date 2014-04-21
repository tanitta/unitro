#include "Cell.h"
namespace unitro{
namespace data{
	Cell::Cell(){
		soil = 0.0;
		water = 0.0;
		temp =  0.0;
		air = 0.0;
		nutP = 0.0;
		nutN = 0.0;
		brightness = 0.0;
	};
	Cell::~Cell(){};
	
	void Cell::setup(){};
	void Cell::update(){};
	void Cell::draw(){};
}
}