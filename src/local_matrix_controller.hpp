#pragma once
#include "data/matrix.hpp"
namespace unitro
{
	class LocalMatrixController
	{
		private:
			unitro::data::Matrix& matrix_ref_;
		public:
			LocalMatrixController(unitro::data::Matrix& matrix_ref):matrix_ref_(matrix_ref){};
			~LocalMatrixController(){};
			void Setup(){};
			void Update(){};

			// void keyPressed(int key){};
			// void keyReleased(int key){};
			// void mouseMoved(int x, int y ){};
			// void mouseDragged(int x, int y, int button){};
			// void mousePressed(int x, int y, int button){};
			// void mouseReleased(int x, int y, int button){};
			// void windowResized(int w, int h){};
			// void dragEvent(ofDragInfo dragInfo){};
			// void gotMessage(ofMessage msg){};
			// void exit(){};
	};
}
