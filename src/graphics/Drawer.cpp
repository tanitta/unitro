#include "Drawer.h"

namespace unitro{
namespace graphics{
	Drawer::Drawer(){};
	Drawer::~Drawer(){};
	void Drawer::setup(){
		ofSetWindowTitle("unitro");
		viewport.x = 0;
		viewport.y = 0;
		viewport.width = 1024;
		viewport.height = 800;
	};
	void Drawer::update(){};
	void Drawer::draw(){
		ofPushView();
			
			ofViewport(viewport);
			ofSetupScreen();
			
			ofDrawGrid(100.0f,8.0f,true,true,true,true); 
		
		ofPopView();
	};
	
}
}