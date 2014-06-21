#pragma once

#include "data/Cell.hpp"
#include "plants/Wheat.hpp"
#include "plants/Butterbur.hpp"
#include "boost/multi_array.hpp"
#include "ofMain.h"
#include "data/Matrix.hpp"
#include "Env.h"
namespace unitro{
	class Solver : public ofThread
	{
	public:
		int a;
		bool isSleep;
		
		ofVec3f &matrixSize;
		unitro::data::untMat3 &nMat;
		unitro::data::untMat3 &cMat;
		
		Solver():
			a(0),
			isSleep(false),
			nMat(unitro::data::nextLocalMatrix),
			cMat(unitro::data::currentLocalMatrix),
			matrixSize(unitro::env::General::matrixSize)
		{
				
		};
		~Solver(){};
		void setup(){
			nMat[5][5][5].soil = 1.0;
			nMat[4][5][5].soil = 0.5;
			nMat[5][5][4].soil = 0.6;
			nMat[4][5][4].soil = 1.0;

			nMat[5][4][5].soil = 0.2*0.5;
			nMat[4][4][5].soil = 0.5*0.5;
			nMat[5][4][4].soil = 0.6*0.5;
			nMat[4][4][4].soil = 1.0*0.5;
			
			nMat[6][5][5].soil = 0.2;
			nMat[5][5][6].soil = 0.1;

			nMat[5][5][5].plant = new unitro::plants::Butterbur;
		};
		
		void update(){
			cMat = nMat;
			for (int i = 0; i < matrixSize.x; ++i){for (int j = 0; j < matrixSize.y; ++j){for (int k = 0; k < matrixSize.z; ++k){
				
			}}};
		};
		
		void threadedFunction(){
				update();
				a += 1;
		}
		
		void draw(){
			cout<<"solver:"<<a<<endl;
		};
	};
}