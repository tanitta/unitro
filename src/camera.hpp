#pragma once
#include <ofMain.h>
namespace unitro {
	class Camera {
		private:
			ofEasyCam camera_;
		public:
			Camera(){};
			virtual ~Camera(){};
			void begin(){
				camera_.begin();
			}
			void end(){
				camera_.end();
			}
	};
} // namespace unitro
