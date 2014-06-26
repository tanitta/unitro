#pragma once
#include "avatar/UserPlayer.hpp"
#include "data/BaseMatrix.hpp"
namespace unitro{
	class LocalWorldControler{
	private:
		unitro::data::BaseMatrix localMatrix;
		unitro::avatar::UserPlayer player;
	public:
		LocalWorldControler(unitro::data::BaseMatrix& m,unitro::avatar::UserPlayer& p):
			localMatrix(m),
			player(p)
		{};
		~LocalWorldControler(){};
		
		void setup(){};
		
		void update(){};
	};
}