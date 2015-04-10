#pragma once
#include "data/matrix.hpp"
#include "data/cell.hpp"
// #include "resources.hpp"
#include "resource_cache.hpp"
#include <boost/numeric/ublas/vector.hpp>
namespace unitro{
	class LocalMatrixView
	{
	private:
		unitro::data::Matrix& matrix_ref_;
		unitro::ResourceCache& resource_cache_ref_;
	public:
		LocalMatrixView(unitro::data::Matrix& m, unitro::ResourceCache& r):
			matrix_ref_(m),
			resource_cache_ref_(r)
		{}

		~LocalMatrixView(){};

		void setup(){
		};
		void update(){

		};
		void draw()const{
			boost::numeric::ublas::vector<int> near_cell(3);
			
			for (int i = 1; i < matrix_ref_.get_size()[0]-1; ++i){for (int j = 1; j < matrix_ref_.get_size()[1]-1; ++j){for (int k = 1; k < matrix_ref_.get_size()[2]-1; ++k){
				if(matrix_ref_[i][j][k].parameters["soil"]>0){
					near_cell = matrix_ref_.get_near_cells(i,j,k);
				}
				ofPushMatrix();
				ofTranslate(i,j,k);
				matrix_ref_[i][j][k].draw(near_cell, resource_cache_ref_);
				ofPopMatrix();
			}}};
		};
	};
}
