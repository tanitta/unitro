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
		virtual ~BasePlant(){};
		
		virtual void setup(){};
		virtual void update(){};
		virtual void draw(){};
	};
}
}