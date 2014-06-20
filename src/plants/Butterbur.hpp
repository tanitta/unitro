#pragma once
#include "BasePlant.hpp"
#include "ofx3DModelLoader.h"
namespace unitro{
namespace plants{
	class Butterbur : public unitro::plants::BasePlant{
	public:
		static ofx3DModelLoader modelObj;

		Butterbur(){
			modelObj.loadModel("Butterbur/Body.3ds", 1 );
		};
		~Butterbur(){};
		
		void setup(){};
		void update(){};
		void draw(){
			modelObj.setPosition(0,0.5,0);
			modelObj.setScale(1);
			modelObj.draw();
			
		};
	};	
}}