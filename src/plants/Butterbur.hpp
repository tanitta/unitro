#pragma once
#include "BasePlant.hpp"
#include "ofx3DModelLoader.h"
namespace unitro{
namespace plants{
	class Butterbur : public unitro::plants::BasePlant{
	public:
		static ofx3DModelLoader modelObj;

		double size;
		Butterbur(){
			modelObj.loadModel("Butterbur/Body.3ds", 1 );
			size = ofRandom(0.5, 2);
		};
		~Butterbur(){};
		
		void setup(){};
		void update(){};
		void draw(){
			ofPushMatrix();
				ofRotate((size-0.5)*360.0, 0, 1, 0);
				modelObj.setScale(size,size,size);
				modelObj.draw();
			ofPopMatrix();
			
		};
	};	
}}