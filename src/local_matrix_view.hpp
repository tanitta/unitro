#pragma once
#include "data/matrix.hpp"
#include "data/cell.hpp"
#include "resources.hpp"
#include <boost/numeric/ublas/vector.hpp>
namespace unitro{
	class LocalMatrixView
	{
	private:
		unitro::data::Matrix& matrix_ref_;
		boost::numeric::ublas::vector<int> near_cell_;
		unitro::Resources& resources_ref_;
	public:
		LocalMatrixView(unitro::data::Matrix& m, unitro::Resources& r):
			matrix_ref_(m),
			near_cell_(3),
			resources_ref_(r)
		{}

		~LocalMatrixView(){};

		void setup(){
		};
		void update(){

		};
		void draw(){
			for (int i = 1; i < matrix_ref_.get_size()[0]-1; ++i){for (int j = 1; j < matrix_ref_.get_size()[1]-1; ++j){for (int k = 1; k < matrix_ref_.get_size()[2]-1; ++k){
				if(matrix_ref_[i][j][k].parameters["soil"]>0){
					near_cell_ = matrix_ref_.get_near_cells(i,j,k);
				}
				ofPushMatrix();
				ofTranslate(i,j,k);
				matrix_ref_[i][j][k].draw(near_cell_, resources_ref_);
				ofPopMatrix();
			}}};
		};
	};
}
