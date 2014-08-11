#pragma once
#include "entity/UserPlayer.hpp"
#include "data/BaseMatrix.hpp"
#include "LocalMatrixControler.hpp"
namespace unitro{
	class LocalWorldControler{
	private:
		unitro::data::BaseMatrix& localMatrix;
		unitro::entity::UserPlayer& player;
		unitro::LocalMatrixControler localMatrixControler;

	public:
		LocalWorldControler(unitro::data::BaseMatrix& m,unitro::entity::UserPlayer& p):
			localMatrix(m),
			player(p),
			localMatrixControler(localMatrix);
		{};
		virtual ~LocalWorldControler(){};
		
		void setup(){};
		
		void update(){
			player.update();
		};
	};
}
