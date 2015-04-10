#pragma once

#include "ofMain.h"
// #include "solver.hpp"
// #include "data/BaseMatrix.hpp"
// #include "entity/player.hpp"
// #include "resources.hpp"

// #include "local_world_view.hpp"
// #include "local_world_controller.hpp"

// #include <data/matrix.hpp>
// #include <matrix_controller.hpp>
// #include "interface/keyboard_controller.hpp"
// #include "interface/keyboard.hpp"

// #include "plants/Butterbur.hpp"
#include "world.hpp"
#include "solver.hpp"
#include "local_view.hpp"
namespace unitro {
	class Client : public ofBaseApp{
		private:
			unitro::data::World world_;
			unitro::Solver solver_;
			unitro::LocalView local_view_;
			
		public:

			Client():
				world_(10,10,10),
				solver_(world_),
				local_view_(world_)
		{};

			~Client(){};

			void setup(){
				ofSetWindowTitle("unitro ver.alpha 0.0.1");
				ofSetFrameRate(60);
				
				world_.matrix_[4][4][4]["soil"] = 1;
				world_.matrix_[5][4][4]["soil"] = 0.8;
			};

			void update(){
			};

			void draw(){
				local_view_.draw();
			};

			void keyPressed(int key){
			};
			void keyReleased(int key){
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

