#pragma once
#include "BasePlant.hpp"
#include "ofx3DModelLoader.h"
#include "../data/Matrix.hpp"
namespace unitro{
namespace plants{
	class Butterbur : public unitro::plants::BasePlant{
	public:
		static ofx3DModelLoader modelObj;
		double nutP;
		double nutMax;
		double size;
		unitro::data::untMat3 &cMat;
		Butterbur():
			nutP(0.0),
			nutMax(2.5),
			cMat(unitro::data::currentLocalMatrix){
			modelObj.loadModel("Butterbur/Body.3ds", 1 );
			size = ofRandom(0.5, 2);
		};
		~Butterbur(){};
		
		void setup(){
		};
		void update(ofVec3f pos){
			if(nutP >= nutMax){
				
			}else{
				nutP = 0;
			}
		};
		void draw(){
			ofPushMatrix();
				ofRotate((size-0.5)*360.0, 0, 1, 0);
				modelObj.setScale(size,size,size);
				modelObj.draw();
			ofPopMatrix();
			
		};
	};	
}}