#pragma once
#include "entity/UserPlayer.hpp"
#include "data/BaseMatrix.hpp"
namespace unitro{
	class LocalWorldControler{
	private:
		unitro::data::BaseMatrix& localMatrix;
		unitro::entity::UserPlayer& player;
	public:
		LocalWorldControler(unitro::data::BaseMatrix& m,unitro::entity::UserPlayer& p):
			localMatrix(m),
			player(p)
		{};
		~LocalWorldControler(){};
		
		void setup(){};
		
		void update(){
			player.update();
		};
	};
}