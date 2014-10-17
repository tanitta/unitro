#pragma once

#include "ofMain.h"
#include "../plants/BasePlant.hpp"
#include "../items/BaseItem.hpp"
#include "../resources.hpp"

namespace unitro{
namespace data{
	class Cell
	{
	public:
		double soil_;
		double water_;
		double temp_;
		double air_;
		double nut_p_;
		double nut_n_;
		double brightness_;
		unitro::plants::BasePlant *plant_;
		unitro::items::BaseItem *item_;
		// std::shared_ptr<unitro::plant_s::BasePlant> plant;
		// std::shared_ptr<unitro::item_s::BaseItem> item;
		Cell():
			soil_(0.0),
			water_(0.0),
			temp_( 0.0),
			air_(0.0),
			nut_p_(0.0),
			nut_n_(0.0),
			brightness_(0.0),
			plant_(new unitro::plants::BasePlant),
			item_(new unitro::items::BaseItem)
		{
			// plant_ = new unitro::plants::BasePlant;
			// item_ = new unitro::items::BaseItem;
		};

		~Cell(){};
		void SetNearCell(){};

		void setup(){};

		void update(){
			// plant_->draw();
		};

		void drawPlant(double shift, unitro::Resources& resources){

			ofPushMatrix();
				ofTranslate(0,shift,0);
				plant_->draw(resources);
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
					l = (float)pow(soil_, 1.0/3.0);
					d = 0.5f - l*0.5f;
						pos = ofVec3f(nearCell.x*d,nearCell.y*d,nearCell.z*d);
						size = ofVec3f(l, l, l);

				}
				case 1:{
					l = (float)pow(soil_, 1.0/2.0);
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
					l = (float)soil_;
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
			if(soil_ > 1.0){
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
