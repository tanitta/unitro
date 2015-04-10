#pragma once

#include <boost/numeric/ublas/vector.hpp>
#include "ofMain.h"
#include "../plants/base_plant.hpp"
#include "../items/base_item.hpp"
#include "../resource_cache.hpp"
#include <map>

namespace unitro{
namespace data{
	class Cell
	{
	public:
		std::map<std::string, double> parameters;

		unitro::plants::BasePlant *plant_;

		unitro::items::BaseItem *item_;
		// std::shared_ptr<unitro::plant_s::BasePlant> plant;
		// std::shared_ptr<unitro::item_s::BaseItem> item;
		Cell():
			plant_(new unitro::plants::BasePlant),
			item_(new unitro::items::BaseItem)
		{
			parameters["soil"] = 0.0;
			parameters["water"] = 0.0;
			parameters["water_in"] = 0.0;
			parameters["water_out"] = 0.0;
			parameters["temp"] = 0.0;
			parameters["air"] = 0.0;
			parameters["nut_p"] = 0.0;
			parameters["nut_n"] = 0.0;
			parameters["brightness"] = 0.0;
			// plant_ = new unitro::plants::BasePlant;
			// item_ = new unitro::items::BaseItem;
		};

		~Cell(){};
		void set_near_cell(){};

		double& operator[](std::string type){
			return parameters[type];
		};

		void setup(){};

		void update(){
			// plant_->draw();
		};

		void draw_plant(double shift, unitro::ResourceCache& resource_cache_ref){

			ofPushMatrix();
				ofTranslate(0,shift,0);
				plant_->draw(resource_cache_ref);
			ofPopMatrix();
		};

		void get_water_box_info(){};

		void draw_water(){
			if (parameters["water_out"] > 0.01) {
				float y = parameters["water_out"]*0.5;
				ofSetColor(0, 0, 112, 64);
				ofBox(0, -0.5+y, 0, 1.0, parameters["water_out"], 1.0);
			}
		};

		void get_soil_box_info(ofVec3f& near_cell, ofVec3f& pos, ofVec3f& size){
			int lockedAxis = 0;
			if (near_cell.x == 2)lockedAxis += 1;
			if (near_cell.y == 2)lockedAxis += 1;
			if (near_cell.z == 2)lockedAxis += 1;

			float l;
			float d;

			switch(lockedAxis){
				case 0:{
					l = (float)pow(parameters["soil"], 1.0/3.0);
					d = 0.5f - l*0.5f;
						pos = ofVec3f(near_cell.x*d,near_cell.y*d,near_cell.z*d);
						size = ofVec3f(l, l, l);

				}
				case 1:{
					l = (float)pow(parameters["soil"], 1.0/2.0);
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
					l = (float)parameters["soil"];
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
			if(parameters["soil"]> 1.0){
			pos = ofVec3f(0,0,0);
			size = ofVec3f(1, 1, 1);
			}
		};

		void draw(boost::numeric::ublas::vector<int>& near_cell, unitro::ResourceCache& resource_cache_ref){
			ofVec3f pos;
			ofVec3f size;
			ofVec3f near_cell_of = ofVec3f(near_cell[0],near_cell[1],near_cell[2]);
			get_soil_box_info(near_cell_of, pos, size);

			ofColor c;
			double l = (0.5-(parameters["water_in"]-0.5)*0.5)*255;
			double s = 255;
			c.setHsb(40+40*parameters["nut_p"],s*(1-std::abs(l-128)/128), l);
			ofSetColor(c);

			ofPushMatrix();
				ofTranslate(pos);

				ofBox(size.x, size.y, size.z);
				draw_plant(size.y*0.5, resource_cache_ref);

				// ofDisableDepthTest();
				draw_water();
				// ofEnableDepthTest();
				// ofEnableBlendMode(OF_BLENDMODE_ADD);
			ofPopMatrix();
		};

	};
}
}
