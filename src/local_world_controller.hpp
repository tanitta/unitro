#pragma once
#include "entity/player.hpp"

#include <data/matrix.hpp>

#include "local_matrix_controller.hpp"
#include "local_player_controller.hpp"
namespace unitro{
	class LocalWorldController{
		private:
			unitro::interface::Keyboard& keyboard_ref_;
			unitro::data::Matrix& matrix_ref_;
			unitro::entity::Player& player_ref_;

			unitro::LocalMatrixController local_matrix_controller_;
			unitro::LocalPlayerController local_player_controller_;

		public:
			LocalWorldController(unitro::interface::Keyboard& keyboard, unitro::data::Matrix& m,unitro::entity::Player& p):
				keyboard_ref_(keyboard),
				matrix_ref_(m),
				player_ref_(p),
				local_matrix_controller_(m),
				local_player_controller_(keyboard,p)
			{};
			virtual ~LocalWorldController(){};

			void Setup(){
				local_matrix_controller_.Setup();
				local_player_controller_.Setup();
			};

			void Update(){
				local_matrix_controller_.Update();
//
				local_player_controller_.KeyInput();
// 				if(player.getAdressInMatrix().x >= 1 && player.getAdressInMatrix().x < localMatrix.getSize().x-1){
// 				if(player.getAdressInMatrix().y >= 1 && player.getAdressInMatrix().y < localMatrix.getSize().y-1){
// 				if(player.getAdressInMatrix().z >= 1 && player.getAdressInMatrix().z < localMatrix.getSize().z-1){
// 					localMatrix(player.getAdressInMatrix()).soil += keyboard.isKey['q']*0.01;
// 					localMatrix(player.getAdressInMatrix()).soil -= keyboard.isKey['e']*0.01;
// 					ofVec3f nearCell = localMatrix.getNearCells(player.getAdressInMatrix());
//
// 					ofVec3f boxPos;
// 					ofVec3f boxSize;
// 					localMatrix(player.getAdressInMatrix()).getBoxInfo(nearCell,boxPos,boxSize);
//
// 					bool isContacting = (
// 							player.getAdressInMatrix().x+boxPos.x-boxSize.x*0.6 < player.kineticModel.pos.x &&
// 							player.getAdressInMatrix().x+boxPos.x+boxSize.x*0.6 > player.kineticModel.pos.x &&
// 							player.getAdressInMatrix().y+boxPos.y-boxSize.y*0.6 < player.kineticModel.pos.y &&
// 							player.getAdressInMatrix().y+boxPos.y+boxSize.y*0.6 > player.kineticModel.pos.y &&
// 							player.getAdressInMatrix().z+boxPos.z-boxSize.z*0.6 < player.kineticModel.pos.z &&
// 							player.getAdressInMatrix().z+boxPos.z+boxSize.z*0.6 > player.kineticModel.pos.z
// 					);
// 					if(isContacting){
// 						cout<<boxSize<<endl;
// // 						if(player.getAdressInMatrix().x+boxPos.x > player.kineticModel.pos.x){
// // 							player.kineticModel.pos.x = player.getAdressInMatrix().x+boxPos.x-boxSize.x*0.5;
// // 						}else{
// // 							player.kineticModel.pos.x = player.getAdressInMatrix().x+boxPos.x+boxSize.x*0.5;
// // 						}
//
// 						if(player.getAdressInMatrix().y+boxPos.y > player.kineticModel.pos.y){
// 							player.kineticModel.pos.y = player.getAdressInMatrix().y+boxPos.y-boxSize.y*0.5;
// 						}else{
// 							player.kineticModel.pos.y = player.getAdressInMatrix().y+boxPos.y+boxSize.y*0.5;
// 						}
//
// // 						if(player.getAdressInMatrix().z+boxPos.z > player.kineticModel.pos.z){
// // 							player.kineticModel.pos.z = player.getAdressInMatrix().z+boxPos.z-boxSize.z*0.5;
// // 						}else{
// // 							player.kineticModel.pos.z = player.getAdressInMatrix().z+boxPos.z+boxSize.z*0.5;
// // 						}
// // 						player.kineticModel.ver = player.kineticModel.ver * -1;
// // 						player.kineticModel.pos = player.kineticModel.pos - player.kineticModel.ver*0.1;
// // 						player.kineticModel.ver *= 0;
// 					}
// 				}
// 				}
// 				}
// 				local_player_controller_.update();
			};

			// void keyPressed(int key){
			// 	local_matrix_controller_.keyPressed(key);
			// 	local_player_controller_.keyPressed(key);
			// };
			// void keyReleased(int key){
			// 	local_matrix_controller_.keyReleased(key);
			// 	local_player_controller_.keyReleased(key);
			// };
			// void mouseMoved(int x, int y ){
			// 	local_matrix_controller_.mouseMoved(x, y);
			// 	local_player_controller_.mouseMoved(x, y);
			// };
			// void mouseDragged(int x, int y, int button){
			// 	local_matrix_controller_.mouseDragged(x, y, button);
			// 	local_player_controller_.mouseDragged(x, y, button);
			// };
			// void mousePressed(int x, int y, int button){
			// 	local_matrix_controller_.mousePressed(x, y, button);
			// 	local_player_controller_.mousePressed(x, y, button);
			// };
			// void mouseReleased(int x, int y, int button){
			// 	local_matrix_controller_.mouseReleased(x, y, button);
			// 	local_player_controller_.mouseReleased(x, y, button);
			// };
			// void windowResized(int w, int h){
			// 	local_matrix_controller_.windowResized(w, h);
			// 	local_player_controller_.windowResized(w, h);
			// };
			// void dragEvent(ofDragInfo dragInfo){
			// 	local_matrix_controller_.dragEvent(dragInfo);
			// 	local_player_controller_.dragEvent(dragInfo);
			// };
			// void gotMessage(ofMessage msg){
			// 	local_matrix_controller_.gotMessage(msg);
			// 	local_player_controller_.gotMessage(msg);
			// };
			// void exit(){
			// 	local_matrix_controller_.exit();
			// 	local_player_controller_.exit();
			// };
	};
}
