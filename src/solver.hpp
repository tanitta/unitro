#pragma once
#include <data/cell.hpp>
#include <data/matrix.hpp>
#include <thread>

namespace unitro {
	class Solver {
		private:
			unitro::data::Matrix& matrix_ref_;

		public:
			Solver(unitro::data::Matrix& matrix_ref):matrix_ref_(matrix_ref)
			{
			};
			virtual ~Solver(){};

			void UpdateSoil(){};
			void UpdateWater(){};
			void UpdatePlant(){};

			void Update(){

				std::thread thread_soil([=]{this->UpdateSoil();});
				std::thread thread_water([=]{this->UpdateWater();});
				std::thread thread_plant([=]{this->UpdatePlant();});
				thread_soil.join();
				thread_water.join();
				thread_plant.join();
			};
	};
} // namespace unitro
