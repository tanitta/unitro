#pragma once
#include "ofMain.h"
#include "ofx3DModelLoader.h"
namespace unitro {
	class Resources {
		private:
			map <string, shared_ptr<ofx3DModelLoader> > resouces;
		public:
			Resources(){};
			virtual ~Resources(){};

			shared_ptr<ofx3DModelLoader> operator[](string fileName){
				if (resouces.find(fileName) == resouces.end()) {
// 					// Not Find
					resouces[fileName] = shared_ptr<ofx3DModelLoader>(new ofx3DModelLoader());
					resouces[fileName]->loadModel(fileName);
				}
				return resouces[fileName];
			}
	};
} // namespace unitro
