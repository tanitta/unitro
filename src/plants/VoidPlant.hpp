#pragma once
#include "BasePlant.hpp"
namespace unitro{
namespace plants{
	class VoidPlant : public unitro::plants::BasePlant
		{
		public:
			VoidPlant(){};
			~VoidPlant(){};
			
			void setup(){};
			void update(){};
			void draw(){};
		};	
}}