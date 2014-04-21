#pragma once

#include "Core.h"
namespace unitro{
	Core::Core(){};
	Core::~Core(){};
	void Core::setup(){
		ofSetFrameRate(60);
		drawer.setup();
		data::MatrixManager::getInstance()->initMatrix(100, 100, 100);
		data::MatrixManager::getInstance()->matrixNext[5][5][5].water = 10.0;
		cout<<"water"<<data::MatrixManager::getInstance()->matrixNext[5][5][5].water<<"\n";
		
		// for (int i = 0; i < 10; ++i)
		// {
		// 	hoge[i] = new unitro::test::HogeClass1;
		// }
		// hoge[0]->test();
		// hoge[0]->test();
		
		// hoge[0] = new unitro::test::HogeClass2;
		// hoge[0]->test();
		// hoge[9]->test();
		// unitro::data::Cell* hoge;
		// hoge = matrixManager.GetCellHandle(5,5,5);
		// hoge.[5][5][5].air = 1.0;
		// cout<<"GetCurrentMatrixHandle"<<sizeof(matrixManager.GetCurrentMatrixHandle())<<"\n";
		
		
		// std::map<string,double> mapint;
		// mapint["hoge"] = 1;
		// mapint["moge"] = 1;
		// mapint["hogea"] = 1;
		// mapint["mogea"] = 1;
		// mapint["hogeb"] = 1;
		// mapint["mogeb"] = 1;
		// // cout<<sizeof(longarray)<<"\n";
		// cout<<"char"<<sizeof(char)<<"\n";
		// cout<<"int"<<sizeof(int)<<"\n";
		// cout<<"float"<<sizeof(float)<<"\n";
		// cout<<"double"<<sizeof(double)<<"\n";
		// cout<<"mapint"<<sizeof(mapint)<<"\n";
	};
	void Core::update(){
		drawer.update();
	};
	
	void Core::draw(){
		drawer.draw();
	};	
}