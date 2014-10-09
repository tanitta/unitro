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
	};
}
}
