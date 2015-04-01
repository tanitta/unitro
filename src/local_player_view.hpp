#pragma once
#include "entity/player.hpp"
#include "resources.hpp"
namespace unitro {
	class LocalPlayerView {
		unitro::entity::Player& player_ref_;
		unitro::Resources& resources_ref_;

		public:
			LocalPlayerView(unitro::entity::Player& p, unitro::Resources& r):
				player_ref_(p),
				resources_ref_(r)
			{};
			virtual ~LocalPlayerView(){};

			void draw(){
				player_ref_.draw(resources_ref_);
			}
	};
} // namespace unitro
