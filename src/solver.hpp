#pragma once

#include "data/Cell.hpp"
#include "plants/Wheat.hpp"
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
		
		void setup(mat3& cMat, mat3& nMat){
			matrixSize.x = cMat.size();
			matrixSize.y = cMat[0].size();
			matrixSize.z = cMat[0][0].size();
			
			nMat[5][5][5].soil = 1;
			
			nMat[5][5][5].plant = new unitro::plants::Wheat;
			
			nMat[4][5][5].soil = 1;
			nMat[5][5][4].soil = 1;
			nMat[4][5][4].soil = 1;
			
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