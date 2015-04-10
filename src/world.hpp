#pragma once
#include "data/matrix.hpp"
#include "Eigen/Dense"<`0`>
namespace unitro {
	namespace data {
		class World {
			private:
				//entities

			public:
				unitro::data::Matrix matrix_;
				
				World(const int& x, const int& y, const int& z):
					matrix_(10,10,10){};
				virtual ~World(){};
		};
	} // namespace data
} // namespace unitro
