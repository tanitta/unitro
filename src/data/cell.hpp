#pragma once

#include <boost/numeric/ublas/vector.hpp>
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
			water_(1.0),
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

		void getBoxInfo(ofVec3f& near_cell, ofVec3f& pos, ofVec3f& size){
			int lockedAxis = 0;
			if (near_cell.x == 2)lockedAxis += 1;
			if (near_cell.y == 2)lockedAxis += 1;
			if (near_cell.z == 2)lockedAxis += 1;

			float l;
			float d;

			switch(lockedAxis){
				case 0:{
					l = (float)pow(soil_, 1.0/3.0);
					d = 0.5f - l*0.5f;
						pos = ofVec3f(near_cell.x*d,near_cell.y*d,near_cell.z*d);
						size = ofVec3f(l, l, l);

				}
				case 1:{
					l = (float)pow(soil_, 1.0/2.0);
					d = 0.5f - l*0.5f;
					if (near_cell.x == 2){
							pos = ofVec3f(0,near_cell.y*d,near_cell.z*d);
							size = ofVec3f(1, l, l);
					}
					if (near_cell.y == 2){
							pos = ofVec3f(near_cell.x*d,0,near_cell.z*d);
							size = ofVec3f(l, 1, l);

					}
					if (near_cell.z == 2){
							pos = ofVec3f(near_cell.x*d,near_cell.y*d,0);
							size = ofVec3f(l, l, 1);

					}
					break;
				}
				case 2:{
					l = (float)soil_;
					d = 0.5f - l*0.5f;
					if (near_cell.x == 2){
						if(near_cell.y == 2){
								pos = ofVec3f(0,0,near_cell.z*d);
								size = ofVec3f(1, 1, l);
						}
						if(near_cell.z == 2){
								pos = ofVec3f(0,near_cell.y*d,0);
								size = ofVec3f(1, l, 1);
						}

					}
					if(near_cell.y == 2 && near_cell.z == 2){
							pos = ofVec3f(near_cell.x*d,0,0);
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

		void Draw(boost::numeric::ublas::vector<int>& near_cell, unitro::Resources& resources){
			ofVec3f pos;
			ofVec3f size;
			ofVec3f near_cell_of = ofVec3f(near_cell[0],near_cell[1],near_cell[2]);
			getBoxInfo(near_cell_of, pos, size);

			ofColor c;
			double l = (0.5-(water_-0.5)*0.5)*255;
			double s = 255;
			c.setHsb(40+40*nut_p_,s*(1-std::abs(l-128)/128), l);
			ofSetColor(c);

			ofPushMatrix();
				ofTranslate(pos);
				ofBox(size.x, size.y, size.z);
				drawPlant(size.y*0.5, resources);
			ofPopMatrix();
		};

	};
}
}
