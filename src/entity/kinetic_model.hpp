#pragma once
#include "ofMain.h"
namespace unitro {
namespace entity {
	class KineticModel {
		public:
			double difference_time_;
			double mass_;
			double viscosity_;

			ofVec3f ver_;
			ofVec3f acc_;
			ofVec3f pos_;

			KineticModel():
				difference_time_(1.0/30.0),
				mass_(20.0),
				viscosity_(0),
				pos_(ofVec3f(0,0,0)),
				ver_(ofVec3f(0,0,0)),
				acc_(ofVec3f(0,0,0))
			{};

			virtual ~KineticModel(){};

			void AddForce(ofVec3f force){
				acc_ += force/mass_;
			}

			void ResetForce(){
				acc_ = ofVec3f(0,0,0);
			}

			void Update(){
				AddForce(ver_*-viscosity_);
				ver_ += acc_*difference_time_;
				pos_ += ver_*difference_time_;

				ResetForce();
			};

			void Draw(){}
	};
} // namespace entity
} // namespace unitro
