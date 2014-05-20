#pragma once

#include "ofMain.h"
#include "CellDrawer.hpp"
namespace unitro{
namespace graphics{
	class Drawer
	{
	public:
		Drawer(){};
		~Drawer(){};
		void setup(){
			ofSetWindowTitle("unitro ver.alpha 0.0.1");
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
		void update(){};
		void draw(){
			ofPushView();
			
			ofViewport(viewport);
			ofSetupScreen();
			
			mainCam.begin();
				// ofDrawBox(5,5,5,1);
				ofDrawGrid(10.0f,10.0f,true,true,true,true); 
				// cellDrawer.draw();
			mainCam.end();
			ofPopView();
		};
		
		ofLight light;
		
		ofRectangle viewport;	
		ofEasyCam mainCam;
		// CellDrawer cellDrawer;
	};
}
}