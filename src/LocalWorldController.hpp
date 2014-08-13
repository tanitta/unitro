#pragma once
#include "entity/Player.hpp"
#include "data/BaseMatrix.hpp"
#include "LocalMatrixController.hpp"
namespace unitro{
	class LocalWorldController{
		private:
			unitro::data::BaseMatrix& localMatrix;
			unitro::entity::Player& player;
			unitro::LocalMatrixController localMatrixController;

		public:
			LocalWorldController(unitro::data::BaseMatrix& m,unitro::entity::Player& p):
				localMatrix(m),
				player(p),
				localMatrixController(localMatrix)
			{};
			virtual ~LocalWorldController(){};

			void setup(){};

			void update(){
				player.update();
			};
	};
}
