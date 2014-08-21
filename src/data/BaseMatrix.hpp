#pragma once
#include "ofMain.h"
#include "Cell.hpp"
namespace unitro{
namespace data{
	class BaseMatrix
	{
		public:
			std::vector< std::vector< std::vector<Cell> > > m;

			BaseMatrix(int x,int y, int z):
				m(x, std::vector<std::vector<Cell> >(y,std::vector<Cell>(z)))
			{};
			virtual ~BaseMatrix(){};

			void SetSoil(int i, int j, int k, double m){
				// m[i][j][k].soil = m;
			}

			// 		void setup(){};
			ofVec3f getSize(){
				return ofVec3f(m.size(), m[0].size(), m[0][0].size());
			}

			std::vector<std::vector<Cell> >& operator[](int i){
				return m[i];
			}

			BaseMatrix& operator=(std::vector<std::vector<std::vector<Cell> > >& A){
				return *this;
			}

			ofVec3f getNearCells(int i, int j, int k){
				ofVec3f nearCell;
				nearCell.x = 0;
				nearCell.y = 0;
				nearCell.z = 0;
				if(m[i-1][j][k].soil>0 && m[i+1][j][k].soil>0){
					nearCell.x = 2;
				}else{
					if(m[i-1][j][k].soil>0)nearCell.x -= 1;
					if(m[i+1][j][k].soil>0)nearCell.x += 1;
				}

				if(m[i][j-1][k].soil>0 && m[i][j+1][k].soil>0){
					nearCell.y = 2;
				}else{
					if(m[i][j-1][k].soil>0)nearCell.y -= 1;
					if(m[i][j+1][k].soil>0)nearCell.y += 1;
				}

				if(m[i][j][k-1].soil>0 && m[i][j][k+1].soil>0){
					nearCell.z = 2;
				}else{
					if(m[i][j][k-1].soil>0)nearCell.z -= 1;
					if(m[i][j][k+1].soil>0)nearCell.z += 1;
				}
				return nearCell;
			}
	};
}
}


