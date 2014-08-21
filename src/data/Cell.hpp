#pragma once

#include "ofMain.h"
#include "../plants/BasePlant.hpp"
#include "../items/BaseItem.hpp"
#include "../Resources.hpp"

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
		unitro::plants::BasePlant *plant;
		unitro::items::BaseItem *item;
		// std::shared_ptr<unitro::plants::BasePlant> plant;
		// std::shared_ptr<unitro::items::BaseItem> item;
		Cell():
			soil(0.0),
			water(0.0),
			temp( 0.0),
			air(0.0),
			nutP(0.0),
			nutN(0.0),
			brightness(0.0),
			plant(new unitro::plants::BasePlant),
			item(new unitro::items::BaseItem)
		{
			// plant = new unitro::plants::BasePlant;
			// item = new unitro::items::BaseItem;
		};

		~Cell(){};
		void SetNearCell(){};

		void setup(){};

		void update(){
			// plant->draw();
		};

		void drawPlant(double shift, unitro::Resources& resources){

			ofPushMatrix();
				ofTranslate(0,shift,0);
				plant->draw(resources);
			ofPopMatrix();
		};

		void getBoxInfo(ofVec3f& nearCell, ofVec3f& pos, ofVec3f& size){
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
						pos = ofVec3f(nearCell.x*d,nearCell.y*d,nearCell.z*d);
						size = ofVec3f(l, l, l);

				}
				case 1:{
					l = (float)pow(soil, 1.0/2.0);
					d = 0.5f - l*0.5f;
					if (nearCell.x == 2){
							pos = ofVec3f(0,nearCell.y*d,nearCell.z*d);
							size = ofVec3f(1, l, l);
					}
					if (nearCell.y == 2){
							pos = ofVec3f(nearCell.x*d,0,nearCell.z*d);
							size = ofVec3f(l, 1, l);

					}
					if (nearCell.z == 2){
							pos = ofVec3f(nearCell.x*d,nearCell.y*d,0);
							size = ofVec3f(l, l, 1);

					}
					break;
				}
				case 2:{
					l = (float)soil;
					d = 0.5f - l*0.5f;
					if (nearCell.x == 2){
						if(nearCell.y == 2){
								pos = ofVec3f(0,0,nearCell.z*d);
								size = ofVec3f(1, 1, l);
						}
						if(nearCell.z == 2){
								pos = ofVec3f(0,nearCell.y*d,0);
								size = ofVec3f(1, l, 1);
						}

					}
					if(nearCell.y == 2 && nearCell.z == 2){
							pos = ofVec3f(nearCell.x*d,0,0);
							size = ofVec3f(l, 1, 1);

					}
					break;
				}
			}
			if(soil > 1.0){
			pos = ofVec3f(0,0,0);
			size = ofVec3f(1, 1, 1);
			}
		};

		void draw(ofVec3f& nearCell, unitro::Resources& resources){
			ofVec3f pos;
			ofVec3f size;
			getBoxInfo(nearCell, pos, size);

			ofPushMatrix();
				ofTranslate(pos);
				ofBox(size.x, size.y, size.z);
				drawPlant(size.y*0.5, resources);
			ofPopMatrix();
		};

	};
}
}
