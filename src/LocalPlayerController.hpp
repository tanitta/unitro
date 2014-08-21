#pragma once
#include "entity/Player.hpp"
#include "interface/Keyboard.hpp"
namespace unitro {
	class LocalPlayerController {
		private:
			unitro::entity::Player& player;
			unitro::interface::Keyboard keyboard;
		public:
			LocalPlayerController(unitro::entity::Player& p):
				player(p)
			{
				player.kineticModel.viscosity = 40;
			};
			virtual ~LocalPlayerController(){};

			void setup(){};

			void keyInput(){
				ofVec3f force = ofVec3f(
						(keyboard.isKey['a']-keyboard.isKey['d'])*100,
						(keyboard.isKeyDown[32])*5000,
						(keyboard.isKey['w']-keyboard.isKey['s'])*100
				);
				player.kineticModel.AddForce(force);
			};


			void update(){
				if(player.kineticModel.pos.y > 0){
					player.kineticModel.AddForce(ofVec3f(0,-100,0));
				};
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
