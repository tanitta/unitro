#pragma once

#include "ofMain.h"
#include "data/Cell.hpp"
#include "graphics/Drawer.hpp"
#include "boost/multi_array.hpp"
#include "solver.hpp"
#include "Env.h"
namespace unitro{
	class Core
	{
	public:
		ofVec3f matrixSize;
		boost::multi_array<data::Cell, 3> currentLocalMatrix;
		boost::multi_array<data::Cell, 3> nextLocalMatrix;
		unitro::graphics::Drawer drawer;
		unitro::Solver solver;
		int counter;
		Core():counter(0),matrixSize(ofVec3f(10,10,10)){};
		~Core(){};
		
		void setup(){
			currentLocalMatrix.resize(boost::extents[matrixSize.x][matrixSize.y][matrixSize.z]);
			nextLocalMatrix.resize(boost::extents[matrixSize.x][matrixSize.y][matrixSize.z]);
			
			ofSetFrameRate(60);
			drawer.setup(nextLocalMatrix);
			solver.setup(currentLocalMatrix,nextLocalMatrix);
			solver.startThread(true,false);
		};
		void update(){
			// solver.update(currentLocalMatrix,nextLocalMatrix);
			if (counter >= 10*60-1)
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
				ofScale(4,4,4);
				drawer.draw(nextLocalMatrix);
				//solver.draw(currentLocalMatrix,nextLocalMatrix);
			ofPopMatrix();
		};
		
		void exit(){
			solver.stopThread();
		};
	};
}