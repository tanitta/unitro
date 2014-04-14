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
		viewport.height = 600;
		mainCam.setDistance(10);
		mainCam.setNearClip(0.01);
		ofBackground(127);
	};
	void Drawer::update(){};
	void Drawer::draw(){
		ofPushView();
			
			ofViewport(viewport);
			ofSetupScreen();
			
			mainCam.begin();
				ofDrawBox(5,5,5,1);
				ofDrawGrid(10.0f,10.0f,true,true,true,true); 
			mainCam.end();
		ofPopView();
	};
	
}
}