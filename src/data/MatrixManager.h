#include "Cell.h"
namespace unitro{
namespace data{
	// struct Matrix{
		
	// };
	
	class MatrixManager{
	public:
		MatrixManager(int x, int y, int z);
		~MatrixManager();
		int size_x;
		int size_y;
		int size_z;
		
		void ReadData();
		void WriteData();
		
		Cell ***matrixNext;
		Cell ***matrixCurrent;
	private:
		void initCellArray3(Cell ***matrix);
		void delCellArray3(Cell ***matrix);
	};	
}
}