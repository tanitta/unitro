#pragma once
#include "entity/Player.hpp"
#include "data/BaseMatrix.hpp"
#include "LocalMatrixController.hpp"
#include "LocalPlayerController.hpp"
namespace unitro{
	class LocalWorldController{
		private:
			unitro::data::BaseMatrix& localMatrix;
			unitro::entity::Player& player;
			unitro::LocalMatrixController localMatrixController;
			unitro::LocalPlayerController localPlayerController;
			unitro::interface::Keyboard keyboard;
		public:
			LocalWorldController(unitro::data::BaseMatrix& m,unitro::entity::Player& p):
				localMatrix(m),
				player(p),
				localMatrixController(m),
				localPlayerController(p),
				keyboard()
			{};
			virtual ~LocalWorldController(){};

			void setup(){
				localMatrixController.setup();
				localPlayerController.setup();
			};

			void update(){
				localMatrixController.update();

				localPlayerController.keyInput();
				if(player.getAdressInMatrix().x >= 1 && player.getAdressInMatrix().x < localMatrix.getSize().x-1){
				if(player.getAdressInMatrix().y >= 1 && player.getAdressInMatrix().y < localMatrix.getSize().y-1){
				if(player.getAdressInMatrix().z >= 1 && player.getAdressInMatrix().z < localMatrix.getSize().z-1){
					localMatrix(player.getAdressInMatrix()).soil += keyboard.isKey['q']*0.01;
					localMatrix(player.getAdressInMatrix()).soil -= keyboard.isKey['e']*0.01;
					ofVec3f nearCell = localMatrix.getNearCells(player.getAdressInMatrix());

					ofVec3f boxPos;
					ofVec3f boxSize;
					localMatrix(player.getAdressInMatrix()).getBoxInfo(nearCell,boxPos,boxSize);

					bool isContacting = (
							player.getAdressInMatrix().x+boxPos.x-boxSize.x*0.6 < player.kineticModel.pos.x &&
							player.getAdressInMatrix().x+boxPos.x+boxSize.x*0.6 > player.kineticModel.pos.x &&
							player.getAdressInMatrix().y+boxPos.y-boxSize.y*0.6 < player.kineticModel.pos.y &&
							player.getAdressInMatrix().y+boxPos.y+boxSize.y*0.6 > player.kineticModel.pos.y &&
							player.getAdressInMatrix().z+boxPos.z-boxSize.z*0.6 < player.kineticModel.pos.z &&
							player.getAdressInMatrix().z+boxPos.z+boxSize.z*0.6 > player.kineticModel.pos.z
					);
					if(isContacting){
						cout<<boxSize<<endl;
// 						if(player.getAdressInMatrix().x+boxPos.x > player.kineticModel.pos.x){
// 							player.kineticModel.pos.x = player.getAdressInMatrix().x+boxPos.x-boxSize.x*0.5;
// 						}else{
// 							player.kineticModel.pos.x = player.getAdressInMatrix().x+boxPos.x+boxSize.x*0.5;
// 						}

						if(player.getAdressInMatrix().y+boxPos.y > player.kineticModel.pos.y){
							player.kineticModel.pos.y = player.getAdressInMatrix().y+boxPos.y-boxSize.y*0.5;
						}else{
							player.kineticModel.pos.y = player.getAdressInMatrix().y+boxPos.y+boxSize.y*0.5;
						}

// 						if(player.getAdressInMatrix().z+boxPos.z > player.kineticModel.pos.z){
// 							player.kineticModel.pos.z = player.getAdressInMatrix().z+boxPos.z-boxSize.z*0.5;
// 						}else{
// 							player.kineticModel.pos.z = player.getAdressInMatrix().z+boxPos.z+boxSize.z*0.5;
// 						}
// 						player.kineticModel.ver = player.kineticModel.ver * -1;
// 						player.kineticModel.pos = player.kineticModel.pos - player.kineticModel.ver*0.1;
// 						player.kineticModel.ver *= 0;
					}
				}
				}
				}
				localPlayerController.update();
			};

			void keyPressed(int key){
				localMatrixController.keyPressed(key);
				localPlayerController.keyPressed(key);
			};
			void keyReleased(int key){
				localMatrixController.keyReleased(key);
				localPlayerController.keyReleased(key);
			};
			void mouseMoved(int x, int y ){
				localMatrixController.mouseMoved(x, y);
				localPlayerController.mouseMoved(x, y);
			};
			void mouseDragged(int x, int y, int button){
				localMatrixController.mouseDragged(x, y, button);
				localPlayerController.mouseDragged(x, y, button);
			};
			void mousePressed(int x, int y, int button){
				localMatrixController.mousePressed(x, y, button);
				localPlayerController.mousePressed(x, y, button);
			};
			void mouseReleased(int x, int y, int button){
				localMatrixController.mouseReleased(x, y, button);
				localPlayerController.mouseReleased(x, y, button);
			};
			void windowResized(int w, int h){
				localMatrixController.windowResized(w, h);
				localPlayerController.windowResized(w, h);
			};
			void dragEvent(ofDragInfo dragInfo){
				localMatrixController.dragEvent(dragInfo);
				localPlayerController.dragEvent(dragInfo);
			};
			void gotMessage(ofMessage msg){
				localMatrixController.gotMessage(msg);
				localPlayerController.gotMessage(msg);
			};
			void exit(){
				localMatrixController.exit();
				localPlayerController.exit();
			};
	};
}
