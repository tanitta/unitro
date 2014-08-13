#pragma once

#include "ofMain.h"
#include "graphics/Drawer.hpp"
#include "Solver.hpp"
#include "data/BaseMatrix.hpp"
#include "entity/Player.hpp"
#include "Resources.hpp"
#include "LocalWorldView.hpp"
#include "LocalWorldController.hpp"
class Client : public ofBaseApp{

	public:
		unitro::Resources resouces;
		unitro::data::BaseMatrix localMatrix;
		unitro::entity::Player player;

		// unitro::graphics::Drawer drawer();

		//****************************************
		//unitro::avator::Player
		//unitro::avator::OtherPlayers

		//unitro::interface
		unitro::LocalWorldView localWorldView;
		unitro::LocalWorldController localWorldController;
// 		unitro::LocalMatrixController localMatrixControler;


		//network
		//unitro::avator::OtherPlayers
		//unitro::network::Input
		//unitro::network::OutPut

		//tmp
		unitro::Solver solver;

		int counter;

		Client():
			resouces(),
			counter(0),
			localMatrix(10, 10, 10),
			localWorldView(localMatrix, player),
			localWorldController(localMatrix, player),
// 			localMatrixController(localMatrix),
			// drawer(LocalMatrix),
			solver(localMatrix)
		{};

		~Client(){};

		void setup(){
			resouces["Butterbur/Body.3ds"]->setScale(0,0,0);
			ofSetWindowTitle("unitro ver.alpha 0.0.1");
			ofSetFrameRate(unitro::env::General::frameRate);
			// drawer.setup();
			solver.setup();
			solver.startThread(true,false);

			localWorldView.setup();

		};

		void update(){
			//Interface
			localWorldController.update();

			//Solver
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
				localWorldView.draw();

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
