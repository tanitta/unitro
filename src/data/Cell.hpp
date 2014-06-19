#pragma once

#include "ofMain.h"
#include "../plants/BasePlant.hpp"
#include "../plants/VoidPlant.hpp"

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
			
		};
		
		~Cell(){};
		void SetNearCell(){};
		
		void setup(){};
		
		void update(){};
		
		void draw(ofVec3f& nearCell){
			// ofDrawBox(0,0,0,soil);

			int lockedAxis = 0;
			if (nearCell.x == 2)lockedAxis += 1;
			if (nearCell.y == 2)lockedAxis += 1;
			if (nearCell.z == 2)lockedAxis += 1;

			switch(lockedAxis){
				case 0:{
					float l = (float)pow(soil, 1.0/3.0);
					float d = 0.5f - l*0.5f;
					//translate
					ofPushMatrix();
						ofTranslate(nearCell.x*d,nearCell.y*d,nearCell.z*d);
						// ofDrawBox(0,0,0,soil);
						ofDrawBox(l, l, l);
					ofPopMatrix();
					// break;
				}
				case 1:{
					float l = (float)pow(soil, 1.0/2.0);
					float d = 0.5f - l*0.5f;
					if (nearCell.x == 2){
						//translate
						ofPushMatrix();
							ofTranslate(0,nearCell.y*d,nearCell.z*d);
							ofDrawBox(1, l, l);
						ofPopMatrix();
					}
					if (nearCell.y == 2){
						//translate
						ofPushMatrix();
							ofTranslate(nearCell.x*d,0,nearCell.z*d);
							ofDrawBox(l, 1, l);
						ofPopMatrix();
					}
					if (nearCell.z == 2){
						//translate
						ofPushMatrix();
							ofTranslate(nearCell.x*d,nearCell.y*d,0);
							ofDrawBox(l, l, 1);
						ofPopMatrix();
					}
					// break;
				}
				case 2:{
					float l = (float)soil;
					float d = 0.5f - l*0.5f;
					if (nearCell.x == 2){
						if(nearCell.y == 2){
							ofPushMatrix();
								ofTranslate(0,0,nearCell.z*d);
								ofBox(1, 1, l);
							ofPopMatrix();		
						}
						if(nearCell.z == 2){
							ofPushMatrix();
								ofTranslate(0,nearCell.y*d,0);
								ofBox(1, l, 1);
							ofPopMatrix();
						}
						
					}
					if(nearCell.y == 2 && nearCell.z == 2){
						ofPushMatrix();
							ofTranslate(nearCell.x*d,0,0);
							ofBox(l, 1, 1);
						ofPopMatrix();
					}

					break;
				}
			}
		};
		
		
	};
}	
}