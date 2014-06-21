#pragma once

#include "ofMain.h"
#include "Core.hpp"
class testApp : public ofBaseApp{

	public:
		int a;
		void setup(){
			core.setup();
			a = 0;
		};
		void update(){
			core.update();
			a += 1;
		};
		void draw(){
			core.draw();
			cout<<"main : "<<a<<endl;
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
			core.exit();
		};
		unitro::Core core;
		
		// unitro::data::MatrixManager matrixManager;
		// unitro::graphics::Drawer drawer;
};
