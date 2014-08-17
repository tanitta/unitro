#pragma once
#include "data/BaseMatrix.hpp"
#include "entity/Player.hpp"
#include "LocalMatrixView.hpp"
#include "Resources.hpp"

namespace unitro{
	class LocalWorldView
	{
	private:
		unitro::data::BaseMatrix& mat;
		unitro::entity::Player& player;
		unitro::Resources& resources;

		unitro::LocalMatrixView localMatrixView;

		ofLight light;
		ofRectangle viewport;
		// ofEasyCam mainCam;


	public:
		LocalWorldView(unitro::data::BaseMatrix& m, unitro::entity::Player& p, unitro::Resources& r):
			mat(m),
			localMatrixView(m,r),
			player(p),
			resources(r)
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
			player.mainCam.begin();
				// ofDrawGrid(10.0f,10.0f,true,true,true,true);
				localMatrixView.draw();
				player.draw();
			player.mainCam.end();
		};
	};
}
