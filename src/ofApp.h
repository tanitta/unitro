#pragma once

#ifdef Success
#undef Success
#endif
#include <Eigen/Dense>
#include <pharticle/pharticle.hpp>

#include "ofMain.h"

#include "ofxAssimpModelLoader.h"

namespace unitro {
	class Config {
			std::string config_file_path;
		public:
			int cpu_cores_;
			int frame_rate_;
			Eigen::Vector3i grid_size_;
			Eigen::Vector3i render_distance_;
			
			Config():
				config_file_path(""),
				frame_rate_(30),
				cpu_cores_(2),
				grid_size_(10,10,10),
				render_distance_(3, 3, 3){};
			
			virtual ~Config(){};
			
			void load(){};
			void save(){};
	};
	
	template<typename T>
	class Grid {
		public:
		std::vector< std::vector<std::vector<T>>> grid_;
		
		Grid(const Eigen::Vector3i& size):
			grid_(size[0],std::vector<std::vector<T>>(size[1],std::vector<T>(size[2]))){};
		virtual ~Grid(){};

		std::vector<std::vector<T>>& operator[](int i){
			return grid_[i];
		}

		Grid& operator=(std::vector<std::vector<std::vector<T>>>& a){
			return *this;
		}

		T& operator()(Eigen::Vector3i coordinate){
			return grid_[coordinate[0]][coordinate[1]][coordinate[2]];
		}

		Eigen::Vector3i size(){
			return Eigen::Vector3i(grid_.size(), grid_[0].size(), grid_[0][0].size());
		};

		void each(std::function<void(T&)> func){
			for (auto&& i : grid_) {
				for (auto&& j : i) {
					for (auto&& k : j) {
						func(k);
					}
				}
			}
		}
	};
	
	class Nutrient {
		public:
			double positive_;
			double negative_;
			Nutrient():positive_(0), negative_(0){};
			virtual ~Nutrient(){};
	};

	class Water {
		public:
			double in_;
			double out_;
			
			Water():in_(0), out_(0){};
			virtual ~Water(){};
	};
	
	
	class Resource;
	class NBHD;
	class BasePlant {
		public:
			// BasePlant(Config& config):config_(config){};
			Nutrient nutrient_;
			BasePlant():nutrient_(){};
			virtual ~BasePlant(){};
			virtual void update(NBHD& nbhd){};
			virtual void draw(Resource& resource, NBHD& nbhd){};
	};
	

	class Cell {
		public:
			double soil_;
			Water water_;
			Nutrient nutrient_;
			std::shared_ptr<BasePlant> plant_;
			
			Cell():soil_(0), water_(), nutrient_(){};
			virtual ~Cell(){};
			void update_soil(NBHD& nbhd){};
			void update_water(NBHD& nbhd){};
			void draw(NBHD& nbhd){
				std::cout<<"printed"<<std::endl;
			}
			void draw(Resource& resource, NBHD&& nbhd);/*{
				ofDrawBox(0, 0, 0, 0.5);
			}*/
	};
	
	class Butterbur : public BasePlant{
		public:
			// Butterbur(Config& config):BasePlant(config){};
			Butterbur(){};
			virtual ~Butterbur(){};
			void update(NBHD& nbhd){
				std::cout<<"update_butterbur"<<std::endl;
				nutrient_.negative_ += 0.1;
			};
			void draw(Resource& resource, NBHD& nbhd);
	};

	using CellGrid = Grid<Cell>;
	using CellPtrGrid = Grid<Cell*>;

	class NBHD : public CellPtrGrid{
		const Eigen::Vector3i upper_range_; // value >= 0
		const Eigen::Vector3i lower_range_; // value <= 0

		public:
		NBHD(CellGrid& cell_grid, const Eigen::Vector3i& target_cell, const Eigen::Vector3i& lower_range, const Eigen::Vector3i& upper_range):
			CellPtrGrid(Eigen::Vector3i(1,1,1)+upper_range-lower_range),
			upper_range_(upper_range),
			lower_range_(lower_range)
		{
			for (int i = lower_range[0]; i <= upper_range[0]; i++) {
				for (int j = lower_range[1]; j <= upper_range[1]; j++) {
					for (int k = lower_range[2]; k <= upper_range[2]; k++) {
						if (
								i+target_cell[0] < 0 || cell_grid.size()[0] <= i+target_cell[0] ||
								j+target_cell[1] < 0 || cell_grid.size()[1] <= j+target_cell[1] ||
								k+target_cell[2] < 0 || cell_grid.size()[2] <= k+target_cell[2]
						){
							local_cell(Eigen::Vector3i(i, j, k)) = nullptr;
						}else{
							local_cell(Eigen::Vector3i(i, j, k)) = &cell_grid[i+target_cell[0]][j+target_cell[1]][k+target_cell[2]];
						}
						
						// if (local_cell(Eigen::Vector3i(i, j, k))->soil_ != 0.0) {
						// 	std::cout<<"soil amount : "<<std::endl;
						// 	std::cout<<local_cell(Eigen::Vector3i(i, j, k))->soil_<<std::endl;
						// }
					}
				}
			}
		};

		virtual ~NBHD(){};

		Cell*& local_cell(Eigen::Vector3i local_coordinate){
			return this->operator()(local_coordinate-lower_range_);
		}
		
		bool isEmpty(Eigen::Vector3i local_position){
			auto index_position = local_position - lower_range_;
			//is local_position inside?
			if(
					!(index_position[0] < 0 || size()[0] < index_position[0] ||
						index_position[1] < 0 || size()[1] < index_position[1] ||
						index_position[2] < 0 || size()[2] < index_position[2]) 
			){
				return ( local_cell(local_position)==nullptr );
			}
			return true;
		};
	};
	
	void Cell::draw(Resource& resource, NBHD&& nbhd){
		if (soil_ <= 0.0) {
			return;
		}
		
		Eigen::Vector3d soil_exist_state(0, 0, 0);
		if (nbhd.local_cell(Eigen::Vector3i(-1, 0, 0))->soil_ > 0.0) {
			soil_exist_state[0]--;
		}	
		if (nbhd.local_cell(Eigen::Vector3i(1, 0, 0))->soil_ > 0.0) {
			soil_exist_state[0]++;
		}	
		if (nbhd.local_cell(Eigen::Vector3i(0, -1, 0))->soil_ > 0.0) {
			soil_exist_state[1]--;
		}	
		if (nbhd.local_cell(Eigen::Vector3i(0, 1, 0))->soil_ > 0.0) {
			soil_exist_state[1]++;
		}	
		if (nbhd.local_cell(Eigen::Vector3i(0, 0, -1))->soil_ > 0.0) {
			soil_exist_state[2]--;
		}	
		if (nbhd.local_cell(Eigen::Vector3i(0, 0, 1))->soil_ > 0.0) {
			soil_exist_state[2]++;
		}	
		
		nbhd.local_cell(Eigen::Vector3i(0, 0, 0))->soil_;
		Eigen::Vector3d way = soil_exist_state * (1.0 - soil_)*0.5;
		
		ofSetColor(160, 128, 60);
		ofDrawBox(way[0], way[1], way[2], soil_);
		
		if(plant_){
			Eigen::Vector3d center_of_top(way[0], way[1] + soil_*0.5, way[2]);
			ofPushMatrix();
			ofTranslate(center_of_top[0], center_of_top[1], center_of_top[2]);
			plant_->draw(resource, nbhd);
			ofPopMatrix();
		};
	}

	// Cell : Cell -> NBHD -> Cell

	class BaseAnimal {
		Config& config_;
		
		protected:
		bool is_alive_;
		
		public:
			BaseAnimal(Config& config):config_(config),is_alive_(true){};
			
			virtual ~BaseAnimal(){};
			
			void update(NBHD& nbhd){
			};
			
			bool is_alive()const{
				return is_alive_;
			};
			
			void die(){
				is_alive_ = true;
			};
	};
	

	class World {
		Config& config_;

		void remove_dead_animals(){
			animals_.remove_if([](const BaseAnimal& obj){ return !obj.is_alive(); });
		};
		
		public:
		CellGrid cell_grid_;
		std::list<BaseAnimal> animals_;
		
		World(Config& config):config_(config),cell_grid_(config_.grid_size_){
		};

		virtual ~World(){};
		
		void setup(){
			// cell_grid_(Eigen::Vector3i(5, 5, 5)).soil_ = 0.5;
			// cell_grid_(Eigen::Vector3i(5, 6, 5)).soil_ = 1.0;
			// cell_grid_(Eigen::Vector3i(4, 6, 5)).soil_ = 0.8;
			// cell_grid_(Eigen::Vector3i(5, 7, 5)).soil_ = 0.7;
			// cell_grid_(Eigen::Vector3i(5, 7, 5)).plant_.reset(new Butterbur);
			// cell_grid_(Eigen::Vector3i(4, 6, 5)).plant_.reset(new Butterbur);
			
			
			for (int i = 0; i < cell_grid_.size()[0]; i++) {
				// for (int j = 5; j < cell_grid_.size()[1]; j++) {
				for (int k = 0; k < cell_grid_.size()[2]; k++) {
					// 			cell_grid_(Eigen::Vector3i(i, j, k)).soil_ = i*k*0.01;
					int height = 1+ofNoise(i*0.1,k*0.1)*7;
					std::cout<<height<<std::endl;
					for (int j = 0; j < height; j++) {
						cell_grid_(Eigen::Vector3i(i, j, k)).soil_ = 1.0;
						if (j == height-1 && height > 1) {
							cell_grid_(Eigen::Vector3i(i, j, k)).soil_ = ofMap(ofRandom(1.0), 0, 1, 0.1, 1);
							if (ofRandom(1.0) > 0.7) {
								cell_grid_(Eigen::Vector3i(i, j, k)).plant_.reset(new Butterbur);
								cell_grid_(Eigen::Vector3i(i, j, k)).plant_->nutrient_.negative_ = ofNoise(i*0.1,k*0.1)*2.0;
							}
						}
					}
					// 		}
				}
			}
		};
		
	};

	
	// template<typename T = void> 
	class Repeater {
		public:
			int counter_;
			int rate_;
			Repeater(int rate = 1):counter_(1), rate_(rate){};
			virtual ~Repeater(){};
			void run(std::function<void(void)> func){
				if (counter_==rate_) {
						func();
					counter_ = 1;
				}else{
					counter_++;
				}
			};
	};
	
	class Calculator {
		public:
			Config& config_;
			World& world_;
			Repeater plant_repeater_;
			
			Calculator(Config& config, World& world):
				config_(config),
				world_(world),
				plant_repeater_(30*60){};
			
			virtual ~Calculator(){};
			
			void each_update(std::function<void(Eigen::Vector3i cell_position, NBHD& nbhd)> func){
				Eigen::Vector3i target_cell_position(0, 0, 0);
				for (target_cell_position[0] = 0; target_cell_position[0] < world_.cell_grid_.size()[0]; target_cell_position[0]++) {
					for (target_cell_position[1] = 0; target_cell_position[1] < world_.cell_grid_.size()[1]; target_cell_position[1]++) {
						for (target_cell_position[2] = 0; target_cell_position[2] < world_.cell_grid_.size()[2]; target_cell_position[2]++) {
							//nullptr check
							if (world_.cell_grid_(target_cell_position).plant_) {
								NBHD near_cell(world_.cell_grid_, target_cell_position,Eigen::Vector3i(-1, -1, -1), Eigen::Vector3i(1, 1, 1));
								func(target_cell_position, near_cell);
							}
						}
					}
				}
			};
			
			void update(){
				//plant
				plant_repeater_.run([&](){
					each_update([&](Eigen::Vector3i cell_position, NBHD& nbhd){
						world_.cell_grid_(cell_position).plant_->update(nbhd);
					});
				});
			};
	};
	
	class Resource {
			map<string,ofxAssimpModelLoader> models_;
		public:
			Resource(){};
			virtual ~Resource(){};
			ofxAssimpModelLoader& operator()(std::string file_name){
				if (models_.find(file_name) == models_.end()) {
// 					// Not Find
					models_[file_name] = ofxAssimpModelLoader();
					if (!models_[file_name].loadModel(file_name)) {
						cout<<"LoadError"<<endl;
						// Load a model for error
						models_[file_name].loadModel("NoData/Body.x");
					}
					models_[file_name].setScaleNormalization(false);
				}
				return models_[file_name];
			};
			
	};
	
	class Renderer {
		public:
			Config& config_;
			World& world_;
			ofEasyCam& camera_;
			Resource resource_;
			
			Renderer(Config& config, World& world, ofEasyCam& camera):
				config_(config),
				world_(world),
				camera_(camera),
				resource_(){
					ofEnableDepthTest();
					// ofEnableAntiAliasing();
					ofEnableAlphaBlending();
					ofBackground(32);
				};
			
			virtual ~Renderer(){};
			
			void draw_nbhd(Cell* cell){
			};
			
			// void draw(NBHD nbhd){
			// 	Eigen::Vector3i target_cell_position(0, 0, 0);
			// 	for (auto&& i : nbhd.grid_) {
			// 		target_cell_position[1]=0;
			// 		for (auto&& j : i) {
			// 			target_cell_position[2]=0;
			// 			for (auto&& cell : j) {
			// 				ofPushMatrix();
			// 				ofTranslate(target_cell_position[0], target_cell_position[1], target_cell_position[2]);
			// 				cell->draw(resource_, NBHD(world_.cell_grid_, target_cell_position, Eigen::Vector3i(-1, -1, -1), Eigen::Vector3i(1, 1, 1)));
			// 				ofPopMatrix();
			//				
			// 				target_cell_position[2]++;
			// 			}
			// 			target_cell_position[1]++;
			// 		}
			// 		target_cell_position[0]++;
			// 	}
			// };
			
			void draw_cell(Eigen::Vector3i position){
				world_.cell_grid_(position).draw(resource_, NBHD(world_.cell_grid_, position, Eigen::Vector3i(-1, -1, -1), Eigen::Vector3i(1, 1, 1)));
			};
				
			void draw(Eigen::Vector3i position){
				Eigen::Vector3i global_position(0, 0, 0);
				for (int i = -config_.render_distance_[0]; i <= config_.render_distance_[0]; i++) {
					for (int j = -config_.render_distance_[1]; j <= config_.render_distance_[1]; j++) {
						for (int k = -config_.render_distance_[2]; k <= config_.render_distance_[2]; k++) {
							global_position<<i+position[0], j+position[1], k+position[2];
							if (global_position[0]<0||world_.cell_grid_.size()[0]<=global_position[0]||
							    global_position[1]<0||world_.cell_grid_.size()[1]<=global_position[1]||
							    global_position[2]<0||world_.cell_grid_.size()[2]<=global_position[2]){
								continue;
							}
							ofPushMatrix();
							ofTranslate(global_position[0], global_position[1], global_position[2]);
							draw_cell(global_position);
							ofPopMatrix();
						}
					}

				}
			};
	};
	
	void Butterbur::draw(Resource& resource, NBHD& nbhd){
		ofColor c;
		c.setHsb(0,64,255);
		ofSetColor(c);
		ofPushMatrix();
		ofScale(1.0+nutrient_.negative_, 1.0+nutrient_.negative_, 1.0+nutrient_.negative_);
		resource("Butterbur/Body.x").draw(OF_MESH_FILL);
		ofPopMatrix();
	};
	
	class EventManager {
		public:
			EventManager(){};
			virtual ~EventManager(){};
	};
	
	// class BaseApp {
	// 	protected:
	// 		Config config_;
	// 	public:
	// 		BaseApp():config_(){};
	// 		virtual ~BaseApp(){};
	// };
	//
	// class Server : public BaseApp{
	// 	Calculator calculator_;
	// 	World world_;
	// 	public:
	// 		Server():calculator_(),world_(config_){};
	// 		virtual ~Server(){};
	// };
	//
	// class Client : public BaseApp{
	// 	World local_world_;
	// 	public:
	// 		Client():local_world_(config_){};
	// 		virtual ~Client(){};
	// };
	//
	//
	// class Single : public BaseApp {
	// 	// World world_;
	// 	public:
	// 		Single(){};
	// 		virtual ~Single(){};
	// };
} // namespace unitro

class ofApp : public ofBaseApp{
	unitro::Config config_;
	unitro::World world_;
	
	ofEasyCam camera_;
	unitro::Renderer renderer_;
	unitro::Calculator calculator_;

	// std::unique_ptr<unitro::BaseApp> base_app_;
	
	public:
	ofApp():
		config_(),
		world_(config_),
		renderer_(config_, world_, camera_),
		calculator_(config_, world_){
	};
	
	virtual ~ofApp(){};

	void setup(){
		ofSetFrameRate(config_.frame_rate_);
		world_.setup();
	};
	
	void update(){
		calculator_.update();
	};
	
	void draw(){
		camera_.begin();
		ofDrawGrid(10, 10, 10, 10, true);
		renderer_.draw(Eigen::Vector3i(5, 4, 5));
		// for (int i = 0; i < config_.grid_size_[0]; i++) {
		// 	for (int j = 0; j < config_.grid_size_[1]; j++) {
		// 		for (int k = 0; k < config_.grid_size_[2]; k++) {
		// 			ofSetColor(0, 0, 0);
		// 			ofDrawSphere(i, j, k, 0.1);
		// 		}
		// 	}
		// }
		camera_.end();
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

};
