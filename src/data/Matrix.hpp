#pragma once
#include "boost/multi_array.hpp"
#include "Cell.hpp"
#include "../Env.h"
namespace unitro{
namespace data{
	typedef boost::multi_array<data::Cell, 3> untMat3;
	extern untMat3 currentLocalMatrix;
	extern untMat3 nextLocalMatrix;
	// currentLocalMatrix.resize(boost::extents[unitro::env::General::matrixSize.x][unitro::env::General::matrixSize.y][unitro::env::General::matrixSize.z]);
	// nextLocalMatrix.resize(boost::extents[unitro::env::General::matrixSize.x][unitro::env::General::matrixSize.y][unitro::env::General::matrixSize.z]);
}
}