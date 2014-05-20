#pragma once

#include "ofMain.h"
#include "data/MatrixManager.hpp"
#include "graphics/Drawer.hpp"
#include "test/VirtualClass.hpp"
// #include "boost/multi_array.hpp"

namespace unitro{
	class Core
	{
	public:
		Core(){};
		~Core(){};
		
		void setup(){
			ofSetFrameRate(60);
			drawer.setup();
		};
		void update(){
			drawer.update();
		};
		void draw(){
			drawer.draw();
		};
		
		// unitro::data::MatrixManager matrixManager;
		unitro::graphics::Drawer drawer;
		
		// unitro::test::VirtualClass* hoge[10];
	};
}