#pragma once
#include "data/matrix.hpp"
#include "world.hpp"
// #include "entity/player.hpp"
// #include "LocalMatrixView.hpp"
#include "local_matrix_view.hpp"
// #include "local_player_view.hpp"
// #include "LocalPlayerView.hpp"
#include "resource_cache.hpp"

namespace unitro{
	class LocalWorldView
	{
	private:
		// unitro::data::Matrix& matrix_ref_;
		// unitro::entity::Player& player_ref_;
		unitro::ResourceCache& resource_cache_ref_;

		unitro::LocalMatrixView local_matrix_view_;
		// unitro::LocalPlayerView local_player_view_;
		ofLight light_;
		// ofRectangle viewport_;
		// ofEasyCam main_cam_;

		unitro::data::World& world_ref_;

	public:
		LocalWorldView(unitro::data::World& world_ref, unitro::ResourceCache& r):
			// matrix_ref_(m),
			world_ref_(world_ref),
			local_matrix_view_(world_ref.matrix_, r),
			// local_player_view_(p,r),
			// player_ref_(p),
			resource_cache_ref_(r)
		{};

		~LocalWorldView(){};

		void setup(){
			ofEnableDepthTest();
			// ofEnableAntiAliasing();
			ofEnableAlphaBlending();
			//Rectangle
			// viewport_.x = 0;
			// viewport_.y = 0;
			// viewport_.width = 1024;
			// viewport_.height = 600;

			ofBackground(127);

			//Light
			light_.enable();
			light_.setSpotlight();
			light_.setPosition(10.0, 10.0, 10.0);
			light_.setAmbientColor(ofFloatColor(0.5,0.5,0.5,1.0));
			light_.setDiffuseColor(ofFloatColor(0.5,0.5,0.5));
			light_.setSpecularColor(ofFloatColor(1.0,1.0,1.0));
		};
		void update(){

		};
		void draw()const{
			// ofViewport(viewport_);
			// ofSetupScreen();
			
			ofDrawGrid(10.0f,10.0f,true,true,true,true);
			local_matrix_view_.draw();
			// local_player_view_.draw();
			
			// player_ref_.draw(resources_ref_);
		};
	};
}
