#include "Drawer.h"

namespace unitro{
namespace graphics{
	Drawer::Drawer(){};
	Drawer::~Drawer(){};
	void Drawer::setup(){
		ofSetWindowTitle("unitro");
		ofEnableDepthTest();
		ofEnableAntiAliasing();
		
		viewport.x = 0;
		viewport.y = 0;
		viewport.width = 1024;
		viewport.height = 600;
		mainCam.setDistance(10);
		mainCam.setNearClip(0.01);
		ofBackground(127);
		
		light.enable();
		light.setSpotlight();
		light.setPosition(10.0, 10.0, 10.0);
		light.setAmbientColor(ofFloatColor(0.5,0.5,0.5,1.0));
		light.setDiffuseColor(ofFloatColor(0.5,0.5,0.5));
		light.setSpecularColor(ofFloatColor(1.0,1.0,1.0));
		
	};
	void Drawer::update(){};
	void Drawer::draw(){
		ofPushView();
			
			ofViewport(viewport);
			ofSetupScreen();
			
			mainCam.begin();
				// ofDrawBox(5,5,5,1);
				ofDrawGrid(10.0f,10.0f,true,true,true,true); 
				cellDrawer.draw();
			mainCam.end();
		ofPopView();
	};
	
}
}