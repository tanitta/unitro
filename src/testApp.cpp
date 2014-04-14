#include "testApp.h"


#include "map"
//--------------------------------------------------------------
void testApp::setup(){
	ofSetFrameRate(60);
	drawer.setup();
	matrixManager.initMatrix(10, 10, 10);
	matrixManager.matrixNext[5][5][5].water = 10.0;
	
	unitro::data::Cell* hoge;
	// hoge = matrixManager.GetCellHandle(5,5,5);
	// cout<<"hoge.water = "<<matrixManager.GetCellHandle(5,5,5)->water<<"\n";
	// hoge.[5][5][5].air = 1.0;
	cout<<"GetCurrentMatrixHandle"<<sizeof(matrixManager.GetCurrentMatrixHandle())<<"\n";
	
	
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
}

//--------------------------------------------------------------
void testApp::update(){
	drawer.update();
	
	// for (int i = 0; i < 5*1000*1000*20; ++i)
	// {
	// 	longarray[i] = 0;
	// }
	
	
}

//--------------------------------------------------------------
void testApp::draw(){
	drawer.draw();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
