#pragma once
#include "ofxAssimpModelLoader.h"
namespace unitro {
	class Resources {
		private:
			map <string, shared_ptr<ofxAssimpModelLoader> > resouces;
		public:
			Resources(){};
			virtual ~Resources(){};

			shared_ptr<ofxAssimpModelLoader> operator[](string fileName){
				cout<<"Resources is Loading"<<endl;
				if (resouces.find(fileName) == resouces.end()) {
// 					// Not Find
					resouces[fileName] = shared_ptr<ofxAssimpModelLoader>(new ofxAssimpModelLoader());
					if (!resouces[fileName]->loadModel(fileName)) {
						cout<<"LoadErrorDayo"<<endl;
					}
				}
				return resouces[fileName];
			}
	};
} // namespace unitro
