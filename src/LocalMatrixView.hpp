#pragma once
#include "data/BaseMatrix.hpp"
namespace unitro{
	class LocalMatrixView
	{
	private:	
		unitro::data::BaseMatrix& mat;
	public:
		LocalMatrixView(unitro::data::BaseMatrix& m):mat(m){};
		~LocalMatrixView(){};
	
		void setup(){};
		void update(){};
		void draw(){};
	};
}