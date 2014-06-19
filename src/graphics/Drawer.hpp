#pragma once

#include "ofMain.h"
#include "boost/multi_array.hpp"


namespace unitro{
namespace graphics{
	class Drawer
	{
	public:
		typedef boost::multi_array<data::Cell, 3> mat3;
		ofVec3f matrixSize;
		ofLight light;		
		ofRectangle viewport;	
		ofEasyCam mainCam;
		ofVec3f nearCell;
		
		
		Drawer(){};
		
		~Drawer(){};
		void setup(mat3& mat){
			ofSetWindowTitle("unitro ver.alpha 0.0.1");
			ofEnableDepthTest();
			ofEnableAntiAliasing();
			
			viewport.x = 0;
			viewport.y = 0;
			viewport.width = 1024;
			viewport.height = 600;
			mainCam.setDistance(10);
			mainCam.setNearClip(0.01);
			ofBackground(127);
			
			light.enable();
			light.setSpotlight();
			light.setPosition(10.0, 10.0, 10.0);
			light.setAmbientColor(ofFloatColor(0.5,0.5,0.5,1.0));
			light.setDiffuseColor(ofFloatColor(0.5,0.5,0.5));
			light.setSpecularColor(ofFloatColor(1.0,1.0,1.0));
			
			matrixSize.x = mat.size();
			matrixSize.y = mat[0].size();
			matrixSize.z = mat[0][0].size();
			
		};
		
		void update(){};
		
		void draw(mat3& mat){
			ofViewport(viewport);
			ofSetupScreen();
			
			mainCam.begin();
				ofDrawGrid(10.0f,10.0f,true,true,true,true); 
				
				for (int i = 1; i < matrixSize.x-1; ++i){for (int j = 1; j < matrixSize.y-1; ++j){for (int k = 1; k < matrixSize.z-1; ++k){
						if (mat[i][j][k].soil!=0){
							if(!(mat[i-1][j][k].soil!=0&&
								mat[i+1][j][k].soil!=0&&
								mat[i][j-1][k].soil!=0&&
								mat[i][j+1][k].soil!=0&&
								mat[i][j][k-1].soil!=0&&
								mat[i][j][k+1].soil!=0)
							){
								nearCell.x = 0;
								nearCell.y = 0;
								nearCell.z = 0;
								if (mat[i][j][k].soil<1){
									if(mat[i-1][j][k].soil!=0)nearCell.x--;
									if(mat[i+1][j][k].soil!=0)nearCell.x++;
									if(mat[i][j-1][k].soil!=0)nearCell.y--;
									if(mat[i][j+1][k].soil!=0)nearCell.y++;
									if(mat[i][j][k-1].soil!=0)nearCell.z--;
									if(mat[i][j][k+1].soil!=0)nearCell.z++;
								}
								ofPushMatrix();
									ofTranslate(i,j,k);
									mat[i][j][k].draw(nearCell);
								ofPopMatrix();
							}
						}
				}}};
			mainCam.end();
		};
		
	};
}
}