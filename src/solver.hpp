#pragma once

#include "data/MatrixManager.hpp"
#include "data/Cell.hpp"
#include "boost/multi_array.hpp"
#include "ofMain.h"

namespace unitro{
	typedef boost::multi_array<data::Cell, 3> mat3;
	class Solver
	{
	public:
		ofVec3f matrixSize;
		
		Solver(){};
		~Solver(){};
		
		void SetSize(ofVec3f mSize){
			matrixSize = mSize;
		}
		void setup(mat3& cMat, mat3& nMat){
			nMat[5][5][5].soil = 10;
			nMat[4][5][5].soil = 10;
			nMat[5][5][4].soil = 10;
			nMat[4][5][4].soil = 10;
		};
		
		void update(mat3& cMat, mat3& nMat){
			cMat = nMat;
			for (int i = 0; i < matrixSize.x; ++i){for (int j = 0; j < matrixSize.y; ++j){for (int k = 0; k < matrixSize.z; ++k){
				
			}}};
		};
		
		void draw(mat3& cMat, mat3& nMat){
			cout<<cMat[5][5][5].soil<<"\n";
		};
	};
}