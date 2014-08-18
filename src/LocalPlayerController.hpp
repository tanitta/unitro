#pragma once
#include "entity/Player.hpp"
namespace unitro {
	class LocalPlayerController {
		private:
			unitro::entity::Player& player;
		public:
			LocalPlayerController(unitro::entity::Player& p):
				player(p)
			{};
			virtual ~LocalPlayerController(){};

			void setup(){};
			void update(){
				player.update();
			};

			void keyPressed(int key){};
			void keyReleased(int key){};
			void mouseMoved(int x, int y ){};
			void mouseDragged(int x, int y, int button){};
			void mousePressed(int x, int y, int button){};
			void mouseReleased(int x, int y, int button){};
			void windowResized(int w, int h){};
			void dragEvent(ofDragInfo dragInfo){};
			void gotMessage(ofMessage msg){};
			void exit(){};
	};
} // namespace unitro
