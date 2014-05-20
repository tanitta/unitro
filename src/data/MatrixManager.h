#pragma once
#include "boost/multi_array.hpp"
#include "Cell.h"
namespace unitro{
namespace data{
	// struct Matrix{
		
	// };
	
	class MatrixManager{
	private:
		MatrixManager();
		MatrixManager(const MatrixManager& r){};
		~MatrixManager();
		
		void initCellArray3(Cell ***matrix);
		void delCellArray3(Cell ***matrix);
	public:
		static MatrixManager* getInstance(){
			static MatrixManager inst;
			return &inst;
		}
		
		void initMatrix(int x, int y, int z);
		void delMatrix();
		int size_x;
		int size_y;
		int size_z;
		
		void ReadData();
		void WriteData();
		
		
		Cell*** GetCurrentMatrixHandle();
		Cell*** GetNextMatrixHandle();
		Cell* GetCellHandle(int x, int y, int z);
		
		Cell ***matrixCurrent;
		Cell ***matrixNext;
	};	
}
}