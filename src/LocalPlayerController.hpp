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
			void update(){
				ofVec3f force = ofVec3f(
						(keyboard.isKey['a']-keyboard.isKey['d'])*100,
						(keyboard.isKey[32])*100,
						(keyboard.isKey['w']-keyboard.isKey['s'])*100
				);
				cout<<keyboard.isKey['w']<<endl;
				player.kineticModel.AddForce(force);
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
