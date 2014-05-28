#pragma once

#include "ofMain.h"
#include "boost/array.hpp"

namespace unitro{
namespace plants{
	class BasePlant
	{
	public:
		//index:locus
		// boost::array<int,10> gene;
		
		BasePlant(){};
		~BasePlant(){};
		
		// static void setup(){};
		// static void update(){};
		// static void draw(){};
	};
}
}