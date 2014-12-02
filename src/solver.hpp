#pragma once
#include <data/cell.hpp>
#include <data/matrix.hpp>
#include <thread>

namespace unitro {
	class Solver {
		private:
			unitro::data::Matrix& matrix_ref_;
			int counter_;
			std::thread thread_;
		public:
			Solver(unitro::data::Matrix& matrix_ref):matrix_ref_(matrix_ref),counter_(0){};
			virtual ~Solver(){};

			void UpdateSoil(){};
			void UpdateWater(){};
			void UpdatePlant(){};

			void UpdateThread(){

				std::thread thread_soil([=]{this->UpdateSoil();});
				std::thread thread_water([=]{this->UpdateWater();});
				std::thread thread_plant([=]{this->UpdatePlant();});
				thread_soil.join();
				thread_water.join();
				thread_plant.join();
			};
			void Update(){
				if(counter_ == 0){thread_ = std::thread([=]{this->UpdateThread();});}

				counter_ ++;

				if(counter_ >=30){
					thread_.join();
					counter_ = 0;
				}
			};
			void StartThread(){};
			void EndThread(){};
	};
} // namespace unitro
