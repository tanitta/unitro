#pragma once

#include "ofMain.h"
#include "data/Cell.hpp"
#include "graphics/Drawer.hpp"
#include "boost/multi_array.hpp"
#include "solver.hpp"
namespace unitro{
	class Core
	{
	public:
		ofVec3f matrixSize;
		boost::multi_array<data::Cell, 3> currentLocalMatrix;
		boost::multi_array<data::Cell, 3> nextLocalMatrix;
		unitro::graphics::Drawer drawer;
		unitro::Solver solver;
		
		Core():matrixSize(ofVec3f(10,10,10)){};
		~Core(){};
		
		void setup(){
			currentLocalMatrix.resize(boost::extents[matrixSize.x][matrixSize.y][matrixSize.z]);
			nextLocalMatrix.resize(boost::extents[matrixSize.x][matrixSize.y][matrixSize.z]);
			
			ofSetFrameRate(60);
			drawer.setup(nextLocalMatrix);
			solver.setup(currentLocalMatrix,nextLocalMatrix);
		};
		void update(){
			solver.update(currentLocalMatrix,nextLocalMatrix);
		};
		void draw(){
			drawer.draw(nextLocalMatrix);
			solver.draw(currentLocalMatrix,nextLocalMatrix);
		};
		
		// unitro::data::MatrixManager matrixManager;
		
		// unitro::test::VirtualClass* hoge[10];
		
	};
}