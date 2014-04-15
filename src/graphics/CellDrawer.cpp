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
		for (int i = 0; i < mM->size_x; ++i)
		{
			for (int j = 0; j < mM->size_y; ++j)
			{
				for (int k = 0; k < mM->size_z; ++k)
				{
					ofDrawBox(i,j,k,1);
				}	
			}	
		}
	};
}
}