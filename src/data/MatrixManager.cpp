#include "MatrixManager.h"
namespace unitro{
namespace data{
	MatrixManager::MatrixManager(){
		
	};
	MatrixManager::~MatrixManager(){
		//matrix destruct
		// delCellArray3(matrixCurrent);
		// delCellArray3(matrixNext);
	};
	void MatrixManager::initMatrix(int x, int y, int z){
		size_x = x;
		size_y = y;
		size_z = z;
		
		//matrix construct
		// initCellArray3(matrixCurrent);
		// initCellArray3(matrixNext);
		matrixCurrent = new Cell**[size_x];
		for (int i = 0; i < size_x; ++i) {
		    matrixCurrent[i] = new Cell*[size_y];
		    for (int j = 0; j < size_y; ++j) {
		        matrixCurrent[i][j] = new Cell[size_z];
		    }
		}
		
		matrixNext = new Cell**[size_x];
		for (int i = 0; i < size_x; ++i) {
		    matrixNext[i] = new Cell*[size_y];
		    for (int j = 0; j < size_y; ++j) {
		        matrixNext[i][j] = new Cell[size_z];
		    }
		}
	};
	
	Cell*** MatrixManager::GetCurrentMatrixHandle(){
		return matrixCurrent;
	};
	
	Cell*** MatrixManager::GetNextMatrixHandle(){
		return matrixNext;
	};
	
	Cell* MatrixManager::GetCellHandle(int x, int y, int z){
		return &matrixNext[x][y][z];
	};
	
	void MatrixManager::initCellArray3(Cell ***matrix){
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
