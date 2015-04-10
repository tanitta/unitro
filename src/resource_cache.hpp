#pragma once
#include "ofxAssimpModelLoader.h"
namespace unitro {
	class ResourceCache {
		private:
			map<string, shared_ptr<ofxAssimpModelLoader>> resources_;
		public:
			ResourceCache(){};
			virtual ~ResourceCache(){};

			void draw(const string& file_name){
				if (resources_.find(file_name) == resources_.end()) {
// 					// Not Find
					resources_[file_name] = shared_ptr<ofxAssimpModelLoader>(new ofxAssimpModelLoader());
					if (!resources_[file_name]->loadModel(file_name)) {
						cout<<"LoadError"<<endl;
						// Load a model for error
						resources_[file_name]->loadModel("NoData/Body.x");
					}
					resources_[file_name]->setScaleNomalization(false);
				}
				resources_[file_name]->draw(OF_MESH_FILL);
			}
	};
} // namespace unitro