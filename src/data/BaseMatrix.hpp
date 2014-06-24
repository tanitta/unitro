#include "Cell.hpp"
namespace unitro{
namespace data{
	class BaseMatrix
	{
	public:
		std::vector< std::vector< std::vector<Cell> > > m;
		BaseMatrix(int x,int y, int z):m(x, std::vector<std::vector<Cell> >(y,std::vector<Cell>(z))){
			
			// for (int i = 0; i < 10; ++i) {
			// 	for (int j = 0; j < 10; ++j) {
			// 		for (int k = 0; k < 10; ++k) {
			// 		m[i][j][k] = i * j * k;
			// 		}
			// 	}
			// }
			
		};
		virtual ~BaseMatrix(){};
	
		std::vector<std::vector<Cell> > operator[](int i){
			return m[i];
		}
		
		// Matrix3D& operator=(const Matrix3D& A){
		// 	for(int i=0;i<ROW;i++){
		// 		for(int j=0;j<COL;j++){
		// 		 this->val[i][j]=A.val[i][j];
		// 		}
		// 	}
		// 	return *this;
		// }
	};
}
}


