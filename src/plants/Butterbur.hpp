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
		
		Butterbur():
			nutP(0.1),
			nutMax(2.5)
		{
			modelObj.loadModel("Butterbur/Body.3ds", 1 );
			size = ofRandom(0.5, 2);
		};
		~Butterbur(){};
		
		void setup(){
		};
		
		void grow(ofVec3f pos){
			unitro::data::untMat3 &cMat = unitro::data::currentLocalMatrix;
			unitro::data::untMat3 &nMat = unitro::data::nextLocalMatrix;
			
			if(cMat[pos.x][pos.y][pos.z].soil>0.0){
				nMat[pos.x][pos.y][pos.z].nutP = cMat[pos.x][pos.y][pos.z].nutP - 0.1;
				nMat[pos.x][pos.y][pos.z].plant->nutP = cMat[pos.x][pos.y][pos.z].plant->nutP + 0.1;
			}
		};
		
		void update(ofVec3f pos){
			// unitro::data::untMat3 &cMat = unitro::data::currentLocalMatrix;
			// unitro::data::untMat3 &nMat = unitro::data::nextLocalMatrix;
			// if(cMat[pos.x][pos.y][pos.z].plant->nutP >= cMat[pos.x][pos.y][pos.z].plant->nutMax){
			// }else{
			// 	grow(pos);
			// }
			cout<<"this is butterbur"<<endl;
		};
		void draw(){
			ofPushMatrix();
				// cout<<"nutP-Plan : "<<nutP<<endl;
				ofRotate((size-0.5)*360.0, 0, 1, 0);
				modelObj.setScale(nutP,nutP,nutP);
				modelObj.draw();
			ofPopMatrix();
			
		};
	};	
}}