#pragma once

#include "ofMain.h"
#include "data/Cell.hpp"
#include "data/Matrix.hpp"
#include "graphics/Drawer.hpp"
// #include "boost/multi_array.hpp"
#include "Solver.hpp"
#include "Env.h"
#include "data/BaseMatrix.hpp"
namespace unitro{
	class Core
	{
	public:
		unitro::data::BaseMatrix LocalMatrix;
		
		unitro::graphics::Drawer drawer;
		// unitro::Solver solver();
		int counter;

		
		Core():
			counter(0),
			LocalMatrix(10, 10, 10),
			drawer(LocalMatrix)
		{};
		
		~Core(){};
		
		void setup(){
			ofSetFrameRate(unitro::env::General::frameRate);
			drawer.setup();
			// solver.setup();
			// solver.startThread(true,false);
		};
		void update(){
			if (counter >= 1*unitro::env::General::frameRate-1)
			{
				// if (!solver.isThreadRunning()){
				// 	cout<<"thread is end"<<endl;
				// 	solver.stopThread();
				// 	solver.startThread(true,false);
				// 	counter = 0;
				// }
			}else{
				counter++;
			}
		};
		void draw(){
			ofPushMatrix();
				drawer.draw();
				// solver.draw();
			ofPopMatrix();
		};
		
		void exit(){
			// solver.stopThread();
		};
	};
}