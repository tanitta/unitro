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

			void UpdateSoil(){
				std::cout<<"soil"<<std::endl;
			};
			void UpdateWater(){

				std::cout<<"water"<<std::endl;
			};
			void UpdatePlant(){
				std::cout<<"plant"<<std::endl;
			};

			void UpdateThread(){

				std::thread thread_soil([=]{this->UpdateSoil();});
				std::thread thread_water([=]{this->UpdateWater();});
				std::thread thread_plant([=]{this->UpdatePlant();});
				thread_soil.join();
				thread_water.join();
				thread_plant.join();
			};
			void Update(int update_rate){
				if(counter_ == 0){thread_ = std::thread([=]{
						this->UpdateThread();});
					std::cout<<"StartedSolverThread"<<std::endl;
				}

				counter_ ++;
				std::cout<<"counter_ : "<<counter_<<std::endl;
				if(counter_ >=update_rate){
					thread_.join();
					std::cout<<"FinishedSolverThread"<<std::endl;
					counter_ = 0;
				}
			};
	};
} // namespace unitro
