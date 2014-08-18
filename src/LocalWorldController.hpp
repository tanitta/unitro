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
		public:
			LocalWorldController(unitro::data::BaseMatrix& m,unitro::entity::Player& p):
				localMatrix(m),
				player(p),
				localMatrixController(m),
				localPlayerController(p)
			{};
			virtual ~LocalWorldController(){};

			void setup(){
				localPlayerController.setup();
			};

			void update(){
				localPlayerController.update();
// 				player.update();
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
