#pragma once
#include "boost/multi_array.hpp"
#include <boost/numeric/ublas/vector.hpp>
#include "cell.hpp"
// #include "../Env.h"
namespace unitro{
namespace data{
	class Matrix {
		private:
			std::vector< std::vector<std::vector<unitro::data::Cell>>> matrix_;

			int CountCellsByAxialDirection(int axis, int i, int j, int k){
				int cells = 0;

				int x = ((axis == 0)? 1:0);
				int y = ((axis == 1)? 1:0);
				int z = ((axis == 2)? 1:0);

				if (matrix_[i-x][j-y][k-z].soil_>0 && matrix_[i+x][j+y][k+z].soil_>0) {
					cells = 2;
				}else{
					if(matrix_[i-x][j-y][k-z].soil_>0) cells -= 1;
					if(matrix_[i+x][j+y][k+z].soil_>0) cells += 1;
				}
				return cells;
			}

		public:
			Matrix(int x, int y, int z):
				matrix_(x,std::vector<std::vector<Cell>>(y,std::vector<Cell>(z))){};
			virtual ~Matrix(){};

			boost::numeric::ublas::vector<int> GetSize(){
				boost::numeric::ublas::vector<int> sizes(3);
				sizes[0] = matrix_.size();
				sizes[1] = matrix_[0].size();
				sizes[2] = matrix_[0][0].size();
				return sizes;
			}

			std::vector<std::vector<Cell>>& operator[](int i){
				return matrix_[i];
			}

			Matrix& operator=(std::vector<std::vector<std::vector<Cell>>>& a){
				return *this;
			}

			unitro::data::Cell& operator()(boost::numeric::ublas::vector<int> v){
				return matrix_[v[0]][v[1]][v[2]];
			}


			boost::numeric::ublas::vector<int> GetNearCells(int i, int j, int k){
				boost::numeric::ublas::vector<int> near_cell(3);
				near_cell[0] = CountCellsByAxialDirection(0,i,j,k);
				near_cell[1] = CountCellsByAxialDirection(1,i,j,k);
				near_cell[2] = CountCellsByAxialDirection(2,i,j,k);

				return near_cell;
			}

	};
}
}
