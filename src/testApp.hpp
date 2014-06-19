#pragma once

#include "ofMain.h"
#include "Core.hpp"
class testApp : public ofBaseApp{

	public:
		void setup(){
			core.setup();
		};
		void update(){
			core.update();
		};
		void draw(){
			core.draw();
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

		unitro::Core core;
		
		// unitro::data::MatrixManager matrixManager;
		// unitro::graphics::Drawer drawer;
};
