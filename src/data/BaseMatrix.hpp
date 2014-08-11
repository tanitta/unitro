#pragma once
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

			std::vector<std::vector<Cell> >& operator[](int i){
				return m[i];
			}

			BaseMatrix& operator=(std::vector<std::vector<std::vector<Cell> > >& A){
				return *this;
			}
	};
}
}


