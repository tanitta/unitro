#include "Cell.h"
namespace unitro{
namespace data{
	// struct Matrix{
		
	// };
	
	class MatrixManager{
	public:
		MatrixManager();
		~MatrixManager();
		
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
		
	private:
		void initCellArray3(Cell ***matrix);
		void delCellArray3(Cell ***matrix);
	};	
}
}