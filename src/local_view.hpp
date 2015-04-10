#pragma once
#include "world.hpp"
#include "camera.hpp"
#include "local_world_view.hpp"
#include "resource_cache.hpp"
namespace unitro {
	class LocalView {
		private:
			unitro::data::World& world_ref_;
			unitro::Camera camera_;
			unitro::LocalWorldView local_world_view_;
			unitro::ResourceCache resource_cache_;
		public:
			LocalView(unitro::data::World& world_ref):
			world_ref_(world_ref),
			local_world_view_(world_ref,resource_cache_)
			{};
			virtual ~LocalView(){};
			
			void draw(){
				camera_.begin();
					local_world_view_.draw();
				camera_.end();
			};
	};
} // namespace unitro
