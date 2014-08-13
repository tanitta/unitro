#pragma once
#include "ofMain.h"
#include "ofx3DModelLoader.h"
namespace unitro {
	class Resources {
		private:
			map <string, unique_ptr<ofx3DModelLoader> > resouces;
		public:
			Resources(){};
			virtual ~Resources(){};

// 			unique_ptr<ofx3DModelLoader> operator[](string fileName){
// 				resouces[fileName] = new unique_ptr<ofx3DModelLoader>
// 				if (resouces.find(fileName) == resouces.end()) {
// // 					// Not Find
// // 					resouces[fileName] =
// // 				}else{
// // 					// Find
// 				}
// 			}
	};
} // namespace unitro
