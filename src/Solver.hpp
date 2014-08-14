#pragma once

#include "data/Cell.hpp"
#include "data/Matrix.hpp"
#include "plants/Wheat.hpp"
#include "plants/Butterbur.hpp"
#include "ofMain.h"
#include "Env.h"
#include "data/BaseMatrix.hpp"

namespace unitro{
	class Solver : public ofThread
	{
	public:
		int a;
		bool isSleep;

		ofVec3f &matrixSize;
		unitro::data::BaseMatrix &mat;

		Solver(unitro::data::BaseMatrix &m):
			a(0),
			isSleep(false),
			mat(m),
			matrixSize(unitro::env::General::matrixSize)
		{};
		~Solver(){};

		void setup(){
			mat[5][5][5].soil = 1.0;
			mat[5][5][5].nutP = 10.0;
			mat[4][5][5].soil = 0.5;
			mat[5][5][4].soil = 0.6;
			mat[4][5][4].soil = 1.0;

			mat[5][4][5].soil = 0.2*0.5;
			mat[4][4][5].soil = 0.5*0.5;
			mat[5][4][4].soil = 0.6*0.5;
			mat[4][4][4].soil = 1.0*0.5;

			mat[6][5][5].soil = 0.2;
			mat[5][5][6].soil = 0.1;

			mat[4][5][4].plant = new unitro::plants::Butterbur;
		};

		void update(){
			for (int i = 0; i < matrixSize.x; ++i){for (int j = 0; j < matrixSize.y; ++j){for (int k = 0; k < matrixSize.z; ++k){
				mat[i][j][k].plant->update(ofVec3f(i,j,k));
			}}};
		};

		void threadedFunction(){
				update();
				a += 1;
		}

		void draw(){
		};
	};
}
