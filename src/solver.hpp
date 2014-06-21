#pragma once

#include "data/Cell.hpp"
#include "plants/Wheat.hpp"
#include "plants/Butterbur.hpp"
#include "boost/multi_array.hpp"
#include "ofMain.h"
namespace unitro{
int foo = 3;
	typedef boost::multi_array<data::Cell, 3> mat3;
	class Solver : public ofThread
	{
	public:
		ofVec3f matrixSize;
		mat3* cM;
		mat3* nM;
		int a;
		bool isSleep;
		Solver():a(0),isSleep(false){};
		~Solver(){};
		void setup(mat3& cMat, mat3& nMat){
			cout<<"!!!!"<<unitro::foo<<"!!!!"<<endl;
			cM = &cMat;
			nM = &nMat;
			
			matrixSize.x = cMat.size();
			matrixSize.y = cMat[0].size();
			matrixSize.z = cMat[0][0].size();
			
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
			
			
			// nMat[5][4][5].soil = 1*0.6;
			// nMat[4][4][5].soil = 0.5*0.6;
			// nMat[5][4][4].soil = 0.6*0.6;
			// nMat[4][4][4].soil = 0.2*0.6;
			
			// nMat[5][6][4].soil = 0.6*0.6;
			// nMat[5][7][4].soil = 0.6*0.6;

			nMat[5][5][5].plant = new unitro::plants::Butterbur;
		};
		
		void update(mat3& cMat, mat3& nMat){
			cMat = nMat;
			for (int i = 0; i < matrixSize.x; ++i){for (int j = 0; j < matrixSize.y; ++j){for (int k = 0; k < matrixSize.z; ++k){
				
			}}};
		};
		
		void threadedFunction(){
			mat3 &nMat = *nM;
			mat3 &cMat = *cM;
			// while(isThreadRunning()){
				update(cMat,nMat);
				a += 1;
			// }
		}
		
		void draw(mat3& cMat, mat3& nMat){
			cout<<"solver:"<<a<<endl;
		};
	};
}