#pragma once
#include "data/BaseMatrix.hpp"
#include "Resources.hpp"
namespace unitro
{
	class LocalMatrixController
	{
	private:
		unitro::data::BaseMatrix& mat;
	public:
		LocalMatrixController(unitro::data::BaseMatrix& m):mat(m){};
		~LocalMatrixController(){};

		/* data */
	};
}
