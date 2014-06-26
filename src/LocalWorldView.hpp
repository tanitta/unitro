#pragma once
#include "data/BaseMatrix.hpp"
#include "avatar/UserPlayer.hpp"
#include "LocalMatrixView.hpp"
namespace unitro{
	class LocalWorldView
	{
	private:
		unitro::data::BaseMatrix& mat;
		unitro::avatar::UserPlayer& player;
		
		unitro::LocalMatrixView localMatrixView;
		
		ofLight light;		
		ofRectangle viewport;	
		ofEasyCam mainCam;
		
		
	public:
		LocalWorldView(unitro::data::BaseMatrix& m, unitro::avatar::UserPlayer& p):
			mat(m),
			localMatrixView(m),
			player(p)
		{};
		
		~LocalWorldView(){};

		void setup(){
			ofEnableDepthTest();
			ofEnableAntiAliasing();
			
			//Rectangle
			viewport.x = 0;
			viewport.y = 0;
			viewport.width = 1024;
			viewport.height = 600;
			
			//Camera
			mainCam.setDistance(10);
			mainCam.setNearClip(0.01);
			ofBackground(127);
			
			//Light
			light.enable();
			light.setSpotlight();
			light.setPosition(10.0, 10.0, 10.0);
			light.setAmbientColor(ofFloatColor(0.5,0.5,0.5,1.0));
			light.setDiffuseColor(ofFloatColor(0.5,0.5,0.5));
			light.setSpecularColor(ofFloatColor(1.0,1.0,1.0));
		};
		void update(){
			
		};
		void draw(){
			ofViewport(viewport);
			ofSetupScreen();
			mainCam.begin();
				ofDrawGrid(10.0f,10.0f,true,true,true,true); 
				localMatrixView.draw();
				player.draw();
			mainCam.end();
		};
	};
}