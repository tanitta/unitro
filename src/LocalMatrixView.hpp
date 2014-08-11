#pragma once
#include "data/BaseMatrix.hpp"
namespace unitro{
	class LocalMatrixView
	{
	private:
		unitro::data::BaseMatrix& mat;
		ofVec3f nearCell;
		ofVec3f &matrixSize;
		
	public:
		LocalMatrixView(unitro::data::BaseMatrix& m):
			mat(m),
			matrixSize(unitro::env::General::matrixSize)
		{}
		
		~LocalMatrixView(){};

		void setup(){
		};
		void update(){
			
		};
		void draw(){
			for (int i = 1; i < matrixSize.x-1; ++i){for (int j = 1; j < matrixSize.y-1; ++j){for (int k = 1; k < matrixSize.z-1; ++k){
					if(mat[i][j][k].soil>0){
						nearCell.x = 0;
						nearCell.y = 0;
						nearCell.z = 0;
						if(mat[i-1][j][k].soil>0 && mat[i+1][j][k].soil>0){
							nearCell.x = 2;
						}else{
							if(mat[i-1][j][k].soil>0)nearCell.x -= 1;
							if(mat[i+1][j][k].soil>0)nearCell.x += 1;
						}
						
						if(mat[i][j-1][k].soil>0 && mat[i][j+1][k].soil>0){
							nearCell.y = 2;
						}else{
							if(mat[i][j-1][k].soil>0)nearCell.y -= 1;
							if(mat[i][j+1][k].soil>0)nearCell.y += 1;
						}
						
						if(mat[i][j][k-1].soil>0 && mat[i][j][k+1].soil>0){
							nearCell.z = 2;
						}else{
							if(mat[i][j][k-1].soil>0)nearCell.z -= 1;
							if(mat[i][j][k+1].soil>0)nearCell.z += 1;
						}
					}
					ofPushMatrix();
						ofTranslate(i,j,k);
						mat[i][j][k].draw(nearCell);
					ofPopMatrix();
				}}};
		};
	};
}
