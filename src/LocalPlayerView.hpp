#pragma once
#include "entity/Player.hpp"
#include "Resources.hpp"
namespace unitro {
	class LocalPlayerView {
		unitro::entity::Player& player;
		unitro::Resources& resources;

		public:
			LocalPlayerView(unitro::entity::Player& p, unitro::Resources& r):
				player(p),
				resources(r)
			{};
			virtual ~LocalPlayerView(){};

			void draw(){
				player.draw(resources);
			}
	};
} // namespace unitro
