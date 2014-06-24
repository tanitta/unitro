#pragma once

#include "data/Cell.hpp"
#include "data/Matrix.hpp"
#include "plants/Wheat.hpp"
#include "plants/Butterbur.hpp"
#include "boost/multi_array.hpp"
#include "ofMain.h"
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
			nMat[5][5][5].nutP = 10.0;
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
			// nMat[5][5][5].plant->nutP = 5.0;
			// cMat[5][5][5].plant = new unitro::plants::Butterbur;
		};
		
		void update(){
			cMat = nMat;
			for (int i = 0; i < matrixSize.x; ++i){for (int j = 0; j < matrixSize.y; ++j){for (int k = 0; k < matrixSize.z; ++k){
				cMat[i][j][k].plant->update(ofVec3f(i,j,k));
			}}};
		};
		
		void threadedFunction(){
				update();
				a += 1;
		}
		
		void draw(){
			// cout<<"solver:"<<a<<endl;
			
			// cout<<"nutP-Plan : "<<nMat[5][5][5].plant->nutP<<endl;
			// cout<< typeid (nMat[5][5][5].plant).name() << endl;
			// cout<<nMat[5][5][5].plant->nutP<<endl;
			// cout<<cMat[5][5][5].plant->nutP<<endl;
		};
	};
}