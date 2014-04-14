#include "MatrixManager.h"
namespace unitro{
namespace data{
	MatrixManager::MatrixManager(int x, int y, int z){
		size_x = x;
		size_y = y;
		size_z = z;
		
		//matrix construct
		initCellArray3(matrixCurrent);
		initCellArray3(matrixNext);
	};
	MatrixManager::~MatrixManager(){
		//matrix destruct
		delCellArray3(matrixCurrent);
		delCellArray3(matrixNext);
	};
	
	void MatrixManager::initCellArray3(Cell ***matrix){
		matrix = new Cell**[size_x];
		for (int i = 0; i < size_x; ++i) {
		    matrix[i] = new Cell*[size_y];
		    for (int j = 0; j < size_y; ++j) {
		        matrix[i][j] = new Cell[size_z];
		    }
		}
	};
	
	void MatrixManager::delCellArray3(Cell ***matrix){
		for (int i = 0; i < size_x; ++i) {
		    for (int j = 0; j < size_y; ++j) {
		        delete[] matrix[i][j];
		    }
		    delete[] matrix[i];
		}
		delete[] matrix;
	};
}
}
