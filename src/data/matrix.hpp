#pragma once
#include "boost/multi_array.hpp"
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
	};
}
}
