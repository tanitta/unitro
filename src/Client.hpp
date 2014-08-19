#pragma once

#include "ofMain.h"
#include "Solver.hpp"
#include "data/BaseMatrix.hpp"
#include "entity/Player.hpp"
#include "Resources.hpp"
#include "LocalWorldView.hpp"
#include "LocalWorldController.hpp"
#include "interface/KeyboardController.hpp"
class Client : public ofBaseApp{

	public:
		unitro::Resources resources;
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
		unitro::interface::Keyboard keyboard;
		unitro::interface::KeyboardController keyboardController;
		int counter;

		Client():
			resources(),
			counter(0),
			localMatrix(10, 10, 10),
			localWorldView(localMatrix, player, resources),
			localWorldController(localMatrix, player),
			// 			localMatrixController(localMatrix),
			// drawer(LocalMatrix),
			keyboardController(),
			solver(localMatrix)
		{};

		~Client(){};

		void setup(){
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
			keyboardController.update();
		};

		void draw(){
			ofPushMatrix();
			// drawer.draw();
			localWorldView.draw();
			ofPopMatrix();
		};

		void keyPressed(int key){
			keyboardController.SetKeyPressed(key);
			localWorldController.keyPressed(key);
		};
		void keyReleased(int key){
			keyboardController.SetKeyReleased(key);
			localWorldController.keyReleased(key);
		};
		void mouseMoved(int x, int y ){
			localWorldController.mouseMoved(x, y);
		};
		void mouseDragged(int x, int y, int button){
			localWorldController.mouseDragged(x, y, button);
		};
		void mousePressed(int x, int y, int button){
			localWorldController.mousePressed(x, y, button);
		};
		void mouseReleased(int x, int y, int button){
			localWorldController.mouseReleased(x, y, button);
		};
		void windowResized(int w, int h){
			localWorldController.windowResized(w, h);
		};
		void dragEvent(ofDragInfo dragInfo){
			localWorldController.dragEvent(dragInfo);
		};
		void gotMessage(ofMessage msg){
			localWorldController.gotMessage(msg);
		};
		void exit(){
			localWorldController.exit();
			solver.stopThread();
		};
};
