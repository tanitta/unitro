#pragma once
#include "BasePlant.hpp"
#include "ofx3DModelLoader.h"
namespace unitro{
namespace plants{
	class Butterbur : public unitro::plants::BasePlant{
	public:
		static ofx3DModelLoader modelObj;

		Butterbur(){
			modelObj.loadModel("modelSample.3ds", 1 );
		};
		~Butterbur(){};
		
		void setup(){};
		void update(){};
		void draw(){};
	};	
}}