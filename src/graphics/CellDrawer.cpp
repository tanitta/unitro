#include "CellDrawer.h"
namespace unitro{
namespace graphics{
	CellDrawer::CellDrawer(){
		mM = data::MatrixManager::getInstance();
	};
	CellDrawer::~CellDrawer(){};
	
	void CellDrawer::setup(){
	};
	void CellDrawer::draw(){
		for (int i = 1; i < mM->size_x-1; ++i){
			for (int j = 1; j < mM->size_y-1; ++j){
				for (int k = 1; k < mM->size_z-1; ++k){
						
					if (mM->matrixNext[i][j][k].soil!=0){
							ofPushMatrix();
								ofTranslate(i,j,k);
								unitro::data::Cell::SetHandle(&mM->matrixNext[i][j][k]);
								// unitro::data::Cell* unitro::data::Cell::SetHandlemM::cell = mM->matrixNext[i][j][k];
								mM->matrixNext[i][j][k].draw(&mM->matrixNext[i][j][k]); //ofDrawBox(i,j,k,1);
							ofPopMatrix();
						if(!(mM->matrixNext[i-1][j][k].soil!=0&&
							mM->matrixNext[i+1][j][k].soil!=0&&
							mM->matrixNext[i][j-1][k].soil!=0&&
							mM->matrixNext[i][j+1][k].soil!=0&&
							mM->matrixNext[i][j][k-1].soil!=0&&
							mM->matrixNext[i][j][k+1].soil!=0)
						){
							
						}
					}
					if (mM->matrixNext[i][j][k].water!=0){
					}
				}	
			}	
		}
	};
}
}