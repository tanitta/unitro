import armos;

/++
++/
class TestApp : ar.BaseApp{
	public{
		this(){
		}

		void setup(){
			ar.targetFps = 60;
			ar.enableDepthTest;
			ar.blendMode(ar.BlendMode.Alpha);
			
			_gui = (new ar.Gui)
			.add(
				(new ar.List)
				.add(new ar.Partition())
				.add(new ar.Label("unitro"))
				.add(new ar.Partition())
			);
		}

		void update(){
		}

		void draw(){
			import std.stdio;
			( ar.fpsUseRate*100 ).writeln;
			
			
			_gui.draw;
		}
	}//public

	private{
		ar.Gui _gui;
	}//private
}

void main(){
	ar.run(new TestApp);
}

// import std.stdio;
// import std.math;
//
// /++
// ++/
// void each(alias f, G)(G grid){
// 	for (int i = 0; i < grid.size[0]; i++) {
// 		for (int j = 0; j < grid.size[1]; j++) {
// 			for (int k = 0; k < grid.size[2]; k++) {
// 				ar.Vector3i local_position = ar.Vector3i(i, j, k)-grid.origin;
// 				f(local_position, grid.cell(local_position));
// 			}
// 		}
//
// 	}
// }
//
// /++
// ++/
// void each(alias f, G)(G grid, GridRange range){
// 	each(f, G)(grid, range.lowerRange, range.upperRange);
// }
//
// /++
// ++/
// void each(alias f, G)(G grid, ar.Vector3i lowerRange, ar.Vector3i upperRange){
// 	ar.Vector3i min(ar.Vector3i v1, ar.Vector3i v2){
// 		auto returnVec = ar.Vector3i(0, 0, 0);
// 		for (int i = 0; i < 3; i++) {
// 			if(v1[i]>v2[i]){
// 				returnVec[i] = v2[i];
// 			}else{
// 				returnVec[i] = v1[i];
// 			}
// 		}
// 		return returnVec;
// 	}
// 	ar.Vector3i max(ar.Vector3i v1, ar.Vector3i v2){
// 		auto returnVec = ar.Vector3i(0, 0, 0);
// 		for (int i = 0; i < 3; i++) {
// 			if(v1[i]<v2[i]){
// 				returnVec[i] = v2[i];
// 			}else{
// 				returnVec[i] = v1[i];
// 			}
// 		}
// 		return returnVec;
// 	}
//
// 	ar.Vector3i checkedLowerRange = min(lowerRange+grid.origin, ar.Vector3i(0, 0, 0));
// 	ar.Vector3i checkedUpperRange = max(upperRange+grid.origin, grid.size()-ar.Vector3i(1, 1, 1));
//
// 	for (int i = checkedLowerRange[0]; i <= checkedUpperRange[0]; i++) {
// 		for (int j = checkedLowerRange[1]; j <= checkedUpperRange[1]; j++) {
// 			for (int k = checkedLowerRange[2]; k <= checkedUpperRange[2]; k++) {
// 				ar.Vector3i local_position = ar.Vector3i(i, j, k)-grid.origin;
// 				f(local_position, grid.cell(local_position));
// 			}
// 		}
//
// 	}
// }
//
// /++
// ++/
// struct LocalWorld {
// 	public{
// 		/++
// 		++/
// 		Grid nbhd(ar.Vector3i target, ar.Vector3i lower, ar.Vector3i upper){return Grid();}
//
// 		void nbhd(in Grid grid, in ar.Vector3i target){};
//		
// 		this(in GlobalWorld globalWorld, in ar.Vector3i targetPosition, in GridRange range){
// 			grid = globalWorld.nbhd(targetPosition, range.lowerRange, range.upperRange);
// 		}
// 	}//public
//
// 	private{
// 		Grid grid;
// 	}//private
// }
//
// /++
// ++/
// class GlobalWorld{
// 	public{
//		
// 		/++
// 		++/
// 		this(ar.Vector3i size){
// 			_grid = Grid(size);
// 		};
//
// 		/++
// 		++/
// 		Grid nbhd(in ar.Vector3i targetPosition, in ar.Vector3i lower, in ar.Vector3i upper)const{
// 			lower.print;
// 			upper.print;
// 			auto grid = Grid(-lower + upper + ar.Vector3i(1, 1, 1), -lower);
// 			return grid;
// 		};
//
// 		/++
// 		++/
// 		void setLocalWorld(in LocalWorld localWorld, in ar.Vector3i targetPosition){
// 			_grid.setNbhd(localWorld.grid, targetPosition);
// 		}
//
// 		/++
// 		++/
// 		void getLocalWorld(ref LocalWorld localWorld, in ar.Vector3i targetPosition, in GridRange range)const{
// 			localWorld = LocalWorld(this, targetPosition, range);
// 		}
// 	}//public
//
// 	private{
// 		Grid _grid;
// 	}//private
// }
//
// /++
// ++/
// struct PlayerEvent{
//
// }
//
// /++
// ++/
// class Network{
// 	public{
// 		/++
// 		++/
// 		this(Config config){
// 			_config = config;
// 			_world = new GlobalWorld(config.worldSize);
// 		}
//
// 		/++
// 		++/
// 		void setLocalWorld(in LocalWorld localWorld, ar.Vector3i targetPosition){
// 			_world.setLocalWorld(localWorld, targetPosition);
// 			sync();
// 		}
//
// 		/++
// 		++/
// 		void getLocalWorld(ref LocalWorld localWorld, in ar.Vector3i targetPosition, in GridRange range){
// 			_world.getLocalWorld(localWorld, targetPosition, range);
// 			sync();
// 		}
//
// 		/++
// 		++/
// 		void setPlayerEvent(PlayerEvent){
// 			sync();
// 		};
//
// 		/++
// 		++/
// 		void sync(){}
// 	}//public
//
// 	private{
// 		GlobalWorld _world;
// 		Config _config;
// 	}//private
// }
//
// /++
// ++/
// interface ResourceEntity{
// }
//
// class CellBox : ResourceEntity{
// 	public{
// 		/++
// 		++/
// 		void draw(){}
// 	}//public
//	
// 	private{
// 		auto _model = new ar.Model;
// 	}//private
// }
//
// class ResourceManager {
// 	public{
// 		/++
// 		++/
// 		void load(in string fileName){
//			
// 		}
//		
// 		/++
// 		++/
// 		ResourceEntity opIndex(in string name){
// 			return data[name];
// 		}
// 	}//public
//
// 	private{
// 		ResourceEntity[string] data;
// 	}//private
// }//class Resource
//
// /++
// ++/
// class CellRenderer{
// 	public{
// 		/++
// 		++/
// 		void draw(in Grid nbhd){
// 			nbhd.each!((ar.Vector3i position, Cell cell){
// 				ar.pushMatrix;scope(exit)ar.popMatrix;
// 				ar.translate(cast(ar.Vector3f)position);
// 				ar.pushStyle;{
// 					ar.setColor(200.0*cell.soil, 0, 0);
// 					soilMesh.drawWireFrame;
// 				}ar.popStyle;
// 			});
// 		}
// 	}//public
//	
// 	private{
// 		ar.Mesh soilMesh = ar.boxPrimitive(ar.Vector3f(0, 0, 0), ar.Vector3f(1, 1, 1));
// 	}//private
// }
//
// /++
// ++/
// class WorldRenderer {
// 	public{
// 		/++
// 		++/
// 		this(Config config, Network network){
// 			_config = config;
// 			_network = network;
// 			_cellRenderer = new CellRenderer;
// 			_camera = new ar.Camera;
// 			_camera.target = ar.Vector3f(0, 0, 0);
// 			_camera.position = ar.Vector3f(5, 5, -20);
// 		}
//
// 		double angle = 0;
//		
// 		/++
// 		++/
// 		void draw(){
// 			_network.getLocalWorld(_localWorld, cast(ar.Vector3i)_camera.target, GridRange(ar.Vector3i(-3, -3, -3), ar.Vector3i(3, 3, 3)));
// 			angle += 0.1;
// 			_camera.begin;
// 				ar.pushMatrix;
// 					ar.rotate(angle, 1, 1, 1);
// 					_cellRenderer.draw(_localWorld.grid);
// 					ar.drawGrid(1, 10);
// 					// ar.drawAxis(100);
// 				ar.popMatrix;
// 			_camera.end;
// 		};
// 	}//public
//
// 	private{
// 		Config _config;
// 		Network _network;
// 		CellRenderer _cellRenderer;
// 		LocalWorld _localWorld;
// 		ar.Camera _camera;
// 	}//private
// }
//
// /++
// ++/
// class Solver {
// 	public{
// 		/++
// 		++/
// 		this(Config config, Network network){
// 			_config = config;
// 			_network = network;
// 		}
//
// 		/++
// 		++/
// 		void solve(){};
// 	}//public
//
// 	private{
// 		Config _config;
// 		Network _network;
// 		LocalWorld _world;
// 	}//private
// }
//
// /++
// ++/
// class TestApp : ar.BaseApp{
// 	public{
// 		this(){
// 			_config = new Config();
// 			_network = new Network(_config);
// 			_renderer = new WorldRenderer(_config, _network);
// 			_solver = new Solver(_config, _network);
// 		}
//
// 		void setup(){
// 			ar.targetFps = 60;
// 			ar.enableDepthTest;
// 			ar.blendMode(ar.BlendMode.Alpha);
//			
// 			_gui = (new ar.Gui)
// 			.add(
// 				(new ar.List)
// 				.add(new ar.Partition())
// 				.add(new ar.Label("unitro"))
// 				.add(new ar.Partition())
// 			);
// 		}
//
// 		void update(){
// 			// solver.solveWorld;
// 		}
//
// 		void draw(){
// 			_renderer.draw();
// 			( ar.fpsUseRate*100 ).writeln;
//			
//			
// 			_gui.draw;
// 		}
// 	}//public
//
// 	private{
// 		Config _config;
// 		Network _network;
// 		WorldRenderer _renderer;
// 		Solver _solver;
// 		ar.Gui _gui;
// 	}//private
// }
//
// void main(){
// 	ar.run(new TestApp);
// }
