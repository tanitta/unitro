#pragma once

#include "data/Cell.hpp"
#include "data/Matrix.hpp"
#include "plants/Wheat.hpp"
#include "plants/Butterbur.hpp"
#include "ofMain.h"
#include "Env.h"
#include "data/BaseMatrix.hpp"

namespace unitro{
	class Solver
	{
	public:
		int a_;
		bool isSleep_;

		ofVec3f matrix_size_;
		unitro::data::BaseMatrix &mat_;

		Solver(unitro::data::BaseMatrix &m):
			a_(0),
			isSleep(false),
			mat(m)
		{
		};
		~Solver(){};

		void setup(){
			matrixSize = mat.getSize();
			mat_[5][5][5].soil = 1.0;
			mat_[5][5][5].nutP = 10.0;
			mat_[4][5][5].soil = 0.5;
			mat_[5][5][4].soil = 0.6;
			mat_[4][5][4].soil = 1.0;

			mat_[5][4][5].soil = 0.2*0.5;
			mat_[4][4][5].soil = 0.5*0.5;
			mat_[5][4][4].soil = 0.6*0.5;
			mat_[4][4][4].soil = 1.0*0.5;

			mat_[6][5][5].soil = 0.2;
			mat_[5][5][6].soil = 0.1;

			mat_[4][5][4].plant = new unitro::plants::Butterbur;
		};

		void update(){
			for (int i = 0; i < matrixSize.x; ++i){for (int j = 0; j < matrixSize.y; ++j){for (int k = 0; k < matrixSize.z; ++k){
				mat_[i][j][k].plant->update(ofVec3f(i,j,k));
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
