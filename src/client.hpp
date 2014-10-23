#pragma once

#include "ofMain.h"
// #include "solver.hpp"
// #include "data/BaseMatrix.hpp"
#include "entity/player.hpp"
#include "resources.hpp"

#include "local_world_view.hpp"
#include "local_world_controller.hpp"

#include <data/matrix.hpp>
#include "interface/keyboard_controller.hpp"
#include "interface/keyboard.hpp"
namespace unitro {
	class Client : public ofBaseApp{
		private:
			unitro::Resources resources_;
			unitro::data::Matrix local_matrix_;
			unitro::entity::Player player_;

			//unitro::interface
			unitro::LocalWorldView local_world_view_;
			unitro::LocalWorldController local_world_controller_;

			//network
			//unitro::avator::OtherPlayers
			//unitro::network::Input
			//unitro::network::OutPut

			//tmp
			// unitro::Solver solver_;
			unitro::interface::Keyboard keyboard_;
			unitro::interface::KeyboardController keyboard_controller_;

		public:

			Client():
				local_matrix_(10,10,10),
				resources_(),
				keyboard_(),
				keyboard_controller_(keyboard_),
				local_world_view_(local_matrix_, player_, resources_),
				local_world_controller_(keyboard_,local_matrix_, player_)
				// 			localMatrixController(localMatrix),
				// drawer(LocalMatrix),

				// solver_(local_matrix_)
		{};

			~Client(){};

			void setup(){
				ofSetWindowTitle("unitro ver.alpha 0.0.1");
				ofSetFrameRate(60);
				// drawer.setup();
				// solver_.setup();
				// solver_.startThread(true,false);
				//
				local_world_controller_.Setup();
				local_world_view_.Setup();

			};

			void update(){
				//Interface
				local_world_controller_.Update();

				//Solver
				// if (counter_ >= 1*60-1)
				// {
				// 	if (!solver_.isThreadRunning()){
				// 		cout<<"thread is end"<<endl;
				// 		solver_.stopThread();
				// 		solver_.startThread(true,false);
				// 		counter_ = 0;
				// 	}
				// }else{
				// 	counter_++;
				// }
				// keyboard_controller_.update();
			};

			void draw(){
				ofPushMatrix();
				// // drawer.draw();
				local_world_view_.Draw();
				ofPopMatrix();
			};

			void keyPressed(int key){
				keyboard_controller_.SetKeyPressed(key);
			};
			void keyReleased(int key){
				keyboard_controller_.SetKeyReleased(key);
				// local_world_controller_.keyReleased(key);
			};
			void mouseMoved(int x, int y ){
				// local_world_controller_.mouseMoved(x, y);
			};
			void mouseDragged(int x, int y, int button){
				// local_world_controller_.mouseDragged(x, y, button);
			};
			void mousePressed(int x, int y, int button){
				// local_world_controller_.mousePressed(x, y, button);
			};
			void mouseReleased(int x, int y, int button){
				// local_world_controller_.mouseReleased(x, y, button);
			};
			void windowResized(int w, int h){
				// local_world_controller_.windowResized(w, h);
			};
			void dragEvent(ofDragInfo dragInfo){
				// local_world_controller_.dragEvent(dragInfo);
			};
			void gotMessage(ofMessage msg){
				// local_world_controller_.gotMessage(msg);
			};
			void exit(){
				// local_world_controller_.exit();
				// solver_.stopThread();
			};
	};

} // namespace unitro
