#pragma once

#include "ofMain.h"
#include "data/Cell.hpp"
#include "data/Matrix.hpp"
#include "graphics/Drawer.hpp"
#include "boost/multi_array.hpp"
#include "Solver.hpp"
#include "Env.h"
#include "data/BaseMatrix.hpp"
namespace unitro{
	class Core
	{
	public:
		unitro::graphics::Drawer drawer;
		unitro::Solver solver;
		int counter;
		// data::untMat3 data::currentLocalMatrix;
		// data::untMat3 data::nextLocalMatrix;
		std::unique_ptr<unitro::plants::BasePlant> plant;
		
		// std::unique_ptr<int> test;
		boost::multi_array<std::shared_ptr<int>, 3> test;
		
		unitro::data::BaseMatrix testMatrix;
		Core():counter(0),testMatrix(10, 10, 10){
			unitro::data::currentLocalMatrix.resize(boost::extents[unitro::env::General::matrixSize.x][unitro::env::General::matrixSize.y][unitro::env::General::matrixSize.z]);
			unitro::data::nextLocalMatrix.resize(boost::extents[unitro::env::General::matrixSize.x][unitro::env::General::matrixSize.y][unitro::env::General::matrixSize.z]);
		};
		
		~Core(){};
		
		void setup(){
			testMatrix[2][2][2].soil = 3.0;
			cout<<"testMatrix : " << testMatrix[2][2][2].soil << endl;
			
			ofSetFrameRate(unitro::env::General::frameRate);
			drawer.setup();
			solver.setup();
			solver.startThread(true,false);
		};
		void update(){
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
				drawer.draw();
				solver.draw();
			ofPopMatrix();
		};
		
		void exit(){
			solver.stopThread();
		};
	};
}