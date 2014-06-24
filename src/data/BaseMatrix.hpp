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
			m[2][2][2].soil = 2.0;
			
		};
		virtual ~BaseMatrix(){};
	
		void SetSoil(int i, int j, int k, double m){
			// m[i][j][k].soil = m;
		}
	
		std::vector<std::vector<Cell> >& operator[](int i){
			return m[i];
		}
		
		BaseMatrix& operator=(std::vector<std::vector<std::vector<Cell> > >& A){
			return *this;
		}
	};
}
}


