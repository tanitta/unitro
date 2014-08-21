#pragma once
#include "data/BaseMatrix.hpp"
#include "Resources.hpp"
namespace unitro{
	class LocalMatrixView
	{
	private:
		unitro::data::BaseMatrix& mat;
		ofVec3f nearCell;
		ofVec3f &matrixSize;
		unitro::Resources& resources;
	public:
		LocalMatrixView(unitro::data::BaseMatrix& m, unitro::Resources& r):
			mat(m),
			matrixSize(unitro::env::General::matrixSize),
			resources(r)
		{}

		~LocalMatrixView(){};

		void setup(){
		};
		void update(){

		};
		void draw(){
			for (int i = 1; i < matrixSize.x-1; ++i){for (int j = 1; j < matrixSize.y-1; ++j){for (int k = 1; k < matrixSize.z-1; ++k){
				if(mat[i][j][k].soil>0){
					nearCell = mat.getNearCells(i,j,k);
				}
				ofPushMatrix();
				ofTranslate(i,j,k);
				mat[i][j][k].draw(nearCell, resources);
				ofPopMatrix();
			}}};
		};
	};
}
