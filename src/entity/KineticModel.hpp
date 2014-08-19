#pragma once
#include "ofMain.h"
namespace unitro {
namespace entity {
	class KineticModel {
		public:
			double differenceTime;
			double mass;
			double viscosity;

			ofVec3f ver;
			ofVec3f acc;
			ofVec3f pos;

			KineticModel():
				differenceTime(1.0/30.0),
				mass(20.0),
				viscosity(0),
				pos(ofVec3f(0,0,0)),
				ver(ofVec3f(0,0,0)),
				acc(ofVec3f(0,0,0))
			{};

			virtual ~KineticModel(){};

			void AddForce(ofVec3f force){
				acc += force/mass;
			}

			void ResetForce(){
				acc = ofVec3f(0,0,0);
			}

			void update(){
				AddForce(ver*-viscosity);
				ver += acc*differenceTime;
				pos += ver*differenceTime;

				ResetForce();
			};

			void draw(){}
	};
} // namespace entity
} // namespace unitro
