#pragma once

#include "ofMain.h"
#include "../plants/BasePlant.hpp"
#include "../items/BaseItem.hpp"


namespace unitro{
namespace data{
	class Cell
	{
	public:
		double soil;
		double water;
		double temp;
		double air;
		double nutP;
		double nutN;
		double brightness;
		unitro::plants::BasePlant* plant;
		unitro::items::BaseItem* item;
		
		Cell():
			soil(0.0),
			water(0.0),
			temp( 0.0),
			air(0.0),
			nutP(0.0),
			nutN(0.0),
			brightness(0.0)
		{
			plant = new unitro::plants::BasePlant;
		};
		
		~Cell(){};
		void SetNearCell(){};
		
		void setup(){};
		
		void update(){
			// plant->draw();
		};
		
		void drawPlant(double shift){
			ofPushMatrix();
				ofTranslate(0,shift,0);
				plant->draw();
			ofPopMatrix();
		};
		
		void draw(ofVec3f& nearCell){
			ofColor c;
			c.setHsb(0,0,255);
			ofSetColor(c);
			int lockedAxis = 0;
			if (nearCell.x == 2)lockedAxis += 1;
			if (nearCell.y == 2)lockedAxis += 1;
			if (nearCell.z == 2)lockedAxis += 1;
			
			float l;
			float d;
			
			switch(lockedAxis){
				case 0:{
					l = (float)pow(soil, 1.0/3.0);
					d = 0.5f - l*0.5f;
					//translate
					ofPushMatrix();
						ofTranslate(nearCell.x*d,nearCell.y*d,nearCell.z*d);
						ofDrawBox(l, l, l);
						drawPlant(l*0.5);
					ofPopMatrix();
					
				}
				case 1:{
					l = (float)pow(soil, 1.0/2.0);
					d = 0.5f - l*0.5f;
					if (nearCell.x == 2){
						//translate
						ofPushMatrix();
							ofTranslate(0,nearCell.y*d,nearCell.z*d);
							ofDrawBox(1, l, l);
							drawPlant(l*0.5);
						ofPopMatrix();
						
					}
					if (nearCell.y == 2){
						//translate
						ofPushMatrix();
							ofTranslate(nearCell.x*d,0,nearCell.z*d);
							ofDrawBox(l, 1, l);
							drawPlant(0.5);
						ofPopMatrix();
						
					}
					if (nearCell.z == 2){
						//translate
						ofPushMatrix();
							ofTranslate(nearCell.x*d,nearCell.y*d,0);
							ofDrawBox(l, l, 1);
							drawPlant(l*0.5);
						ofPopMatrix();
						
					}
					break;
				}
				case 2:{
					l = (float)soil;
					d = 0.5f - l*0.5f;
					if (nearCell.x == 2){
						if(nearCell.y == 2){
							ofPushMatrix();
								ofTranslate(0,0,nearCell.z*d);
								ofBox(1, 1, l);
								drawPlant(0.5);
							ofPopMatrix();
							
						}
						if(nearCell.z == 2){
							ofPushMatrix();
								ofTranslate(0,nearCell.y*d,0);
								ofBox(1, l, 1);
								drawPlant(l*0.5);
							ofPopMatrix();
							
						}
						
					}
					if(nearCell.y == 2 && nearCell.z == 2){
						ofPushMatrix();
							ofTranslate(nearCell.x*d,0,0);
							ofBox(l, 1, 1);
							drawPlant(0.5);
						ofPopMatrix();
						
					}
					break;
				}
			}
		};
		
		
	};
}	
}