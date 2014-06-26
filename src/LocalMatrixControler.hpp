#pragma once
#include "data/BaseMatrix.hpp"
namespace unitro
{
	class LocalMatrixControler
	{
	private:
		unitro::data::BaseMatrix& mat;
	public:
		LocalMatrixControler(unitro::data::BaseMatrix& m):mat(m){};
		~LocalMatrixControler(){};
	
		/* data */
	};
}