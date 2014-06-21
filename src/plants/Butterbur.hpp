#pragma once
#include "BasePlant.hpp"
#include "ofx3DModelLoader.h"
namespace unitro{
namespace plants{
	class Butterbur : public unitro::plants::BasePlant{
	public:
		static ofx3DModelLoader modelObj;
		double nutP;
		double nutMax;
		double size;
		Butterbur():nutP(0.0),nutMax(2.5){
			modelObj.loadModel("Butterbur/Body.3ds", 1 );
			size = ofRandom(0.5, 2);
		};
		~Butterbur(){};
		
		void setup(){
			if(nutP >= nutMax){
				
			}else{
				nutP = 0;
			}
		};
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