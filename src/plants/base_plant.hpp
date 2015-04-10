#pragma once

#include "ofMain.h"
#include "boost/array.hpp"
#include "../resource_cache.hpp"
namespace unitro{
namespace plants{
	class BasePlant{
	public:
		//index:locus
		// boost::array<int,10> gene;
		double nutP;
		BasePlant(){};
		virtual ~BasePlant(){};

		virtual void setup(){};
		virtual void update(ofVec3f pos){};
		virtual void draw(unitro::ResourceCache& resource_cache_ref){};
	};
}
}
