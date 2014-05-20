#pragma once

#include "ofMain.h"
#include "data/MatrixManager.hpp"
#include "data/Cell.hpp"
#include "graphics/Drawer.hpp"
#include "test/VirtualClass.hpp"
#include "boost/multi_array.hpp"

namespace unitro{
	class Core
	{
	public:
		ofVec3f matrixSize;
		
		Core():matrixSize(ofVec3f(10,10,10)){};
		~Core(){};
		void setup(){
			currentLocalMatrix.resize(boost::extents[matrixSize.x][matrixSize.y][matrixSize.z]);
			nextLocalMatrix.resize(boost::extents[matrixSize.x][matrixSize.y][matrixSize.z]);
			
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
		boost::multi_array<data::Cell, 3> currentLocalMatrix;
		boost::multi_array<data::Cell, 3> nextLocalMatrix;
		
	};
}