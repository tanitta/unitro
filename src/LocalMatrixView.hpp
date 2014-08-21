#pragma once
#include "data/BaseMatrix.hpp"
#include "Resources.hpp"
namespace unitro{
	class LocalMatrixView
	{
	private:
		unitro::data::BaseMatrix& mat;
		ofVec3f nearCell;
		unitro::Resources& resources;
	public:
		LocalMatrixView(unitro::data::BaseMatrix& m, unitro::Resources& r):
			mat(m),
			resources(r)
		{}

		~LocalMatrixView(){};

		void setup(){
		};
		void update(){

		};
		void draw(){
			for (int i = 1; i < mat.getSize().x-1; ++i){for (int j = 1; j < mat.getSize().y-1; ++j){for (int k = 1; k < mat.getSize().z-1; ++k){
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
