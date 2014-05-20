#pragma once
#include "BasePlant.h"
namespace unitro{
namespace plants{
	class Wheat :BasePlant
		{
		public:
			Wheat(){};
			~Wheat(){};
			
			static void setup(){};
			static void update(){};
			static void draw(){};
		};	
}}