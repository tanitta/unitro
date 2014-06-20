#pragma once
#include "BasePlant.hpp"
#include "ofx3DModelLoader.h"
namespace unitro{
namespace plants{
	class Wheat : public unitro::plants::BasePlant{
	public:
		static ofx3DModelLoader modelObj;
		// modelObj.loadModel("modelSample.3ds", 1 );

		Wheat(){
			modelObj.loadModel("modelSample.3ds", 1 );
		};
		~Wheat(){};
		
		void setup(){};
		void update(){};
		void draw(){};
	};	
}}