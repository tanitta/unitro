#pragma once
#include "ofxAssimpModelLoader.h"
namespace unitro {
	class Resources {
		private:
			map <string, shared_ptr<ofxAssimpModelLoader> > resources;
		public:
			Resources(){};
			virtual ~Resources(){};

			shared_ptr<ofxAssimpModelLoader> operator[](string fileName){
				if (resources.find(fileName) == resources.end()) {
// 					// Not Find
					resources[fileName] = shared_ptr<ofxAssimpModelLoader>(new ofxAssimpModelLoader());
					if (!resources[fileName]->loadModel(fileName)) {
						cout<<"LoadErrorDayo"<<endl;
						// Load a model for error
					}
				}
				return resources[fileName];
			}
	};
} // namespace unitro
