#pragma once

#include "ofMain.h"
#include "graphics/Drawer.hpp"
#include "Solver.hpp"
#include "data/BaseMatrix.hpp"
#include "avatar/UserPlayer.hpp"

#include "LocalMatrixView.hpp"
#include "LocalMatrixControler.hpp"
class Client : public ofBaseApp{

	public:
		unitro::data::BaseMatrix localMatrix;
		unitro::avatar::UserPlayer userPlayer;
		
		// unitro::graphics::Drawer drawer();
		
		//****************************************
		//unitro::avator::Player
		//unitro::avator::OtherPlayers
		
		//unitro::interface
		unitro::LocalMatrixView localMatrixView;
		unitro::LocalMatrixControler localMatrixControler;
		
		//network
		//unitro::avator::OtherPlayers
		//unitro::network::Input
		//unitro::network::OutPut
		
		//tmp
		unitro::Solver solver;
		
		int counter;
		
		Client():
			counter(0),
			localMatrix(10, 10, 10),
			localMatrixView(localMatrix),
			localMatrixControler(localMatrix),
			// drawer(LocalMatrix),
			solver(localMatrix)
		{};
		
		~Client(){};
		
		void setup(){
			ofSetFrameRate(unitro::env::General::frameRate);
			// drawer.setup();
			solver.setup();
			solver.startThread(true,false);
		};
		
		void update(){
			if (counter >= 1*unitro::env::General::frameRate-1)
			{
				if (!solver.isThreadRunning()){
					cout<<"thread is end"<<endl;
					solver.stopThread();
					solver.startThread(true,false);
					counter = 0;
				}
			}else{
				counter++;
			}
		};
		
		void draw(){
			ofPushMatrix();
				// drawer.draw();
			ofPopMatrix();
		};

		void keyPressed(int key){};
		void keyReleased(int key){};
		void mouseMoved(int x, int y ){};
		void mouseDragged(int x, int y, int button){};
		void mousePressed(int x, int y, int button){};
		void mouseReleased(int x, int y, int button){};
		void windowResized(int w, int h){};
		void dragEvent(ofDragInfo dragInfo){};
		void gotMessage(ofMessage msg){};
		void exit(){
			solver.stopThread();
		};
};
