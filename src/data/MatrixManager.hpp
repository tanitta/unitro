#pragma once
#include "Cell.hpp"
namespace unitro{
namespace data{
	// struct Matrix{
		
	// };
	
	class MatrixManager{
	private:
		MatrixManager(){};
		MatrixManager(const MatrixManager& r){};
		~MatrixManager(){};
		
		// void initCellArray3(Cell ***matrix);
		// void delCellArray3(Cell ***matrix);
	public:
		static MatrixManager* getInstance(){
			static MatrixManager inst;
			return &inst;
		}
		
		void initMatrix(int x, int y, int z){
			// size_x = x;
			// size_y = y;
			// size_z = z;
			
			// matrixCurrent = new Cell**[size_x];
			// for (int i = 0; i < size_x; ++i) {
			//     matrixCurrent[i] = new Cell*[size_y];
			//     for (int j = 0; j < size_y; ++j) {
			//         matrixCurrent[i][j] = new Cell[size_z];
			//     }
			// }
			
			// matrixNext = new Cell**[size_x];
			// for (int i = 0; i < size_x; ++i) {
			//     matrixNext[i] = new Cell*[size_y];
			//     for (int j = 0; j < size_y; ++j) {
			//         matrixNext[i][j] = new Cell[size_z];
			//     }
			// }
		};
		// void delMatrix();
		// int size_x;
		// int size_y;
		// int size_z;
		
		// void ReadData();
		// void WriteData();
		
		
		// Cell*** GetCurrentMatrixHandle();
		// Cell*** GetNextMatrixHandle();
		// Cell* GetCellHandle(int x, int y, int z);
		
		Cell ***matrixCurrent;
		Cell ***matrixNext;
	};	
}
}