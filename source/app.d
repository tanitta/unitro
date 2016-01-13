import std.stdio;
import std.math;
import armos;

/++
++/
class Config {
	public{
		ar.Vector3i worldSize = ar.Vector3i(10, 10, 10);
		ar.Vector3i renderingRange = ar.Vector3i(4, 4, 4);
	}//public
}

/++
++/
struct GridRange{
	public{
		/++
		++/
		ar.Vector3i lowerRange;
		
		/++
		++/
		ar.Vector3i upperRange;
		
		/++
		++/
		this(ar.Vector3i lower, ar.Vector3i upper){
			lowerRange = lower;
			upperRange = upper;
		};
	}//public
}

/++
++/
struct Cell {
	public{
		double soil = 0;
	}//public

	private{
	}//private
}//struct Cell

/++
++/
struct Grid{
	public{
		ar.Vector3i size()const{return _size;};
		ar.Vector3i origin()const{return _origin;};
		ar.Vector3i lowerRange()const{return _origin;};
		ar.Vector3i upperRange()const{return -( _size - _origin - ar.Vector3i(1, 1, 1) );};
		GridRange gridRange()const{return GridRange(lowerRange, upperRange);}

		/++
		++/
		this(ar.Vector3i size)
			in{
				assert(size[0]>0);
				assert(size[1]>0);
				assert(size[2]>0);
			}
		body{
			_size = size;
			_origin = ar.Vector3i(0, 0, 0);
			allocate();
		}

		/++
		++/
		this(ar.Vector3i size, ar.Vector3i origin)
			in{
				assert(size[0]>0);
				assert(size[1]>0);
				assert(size[2]>0);
			}
		body{
			_size = size;
			_origin = origin;
			allocate();
		}
		unittest{
			Grid grid = Grid(ar.Vector3i(2, 3, 4));
			assert(grid.size == ar.Vector3i(2, 3, 4));
			assert(grid.origin == ar.Vector3i(0, 0, 0));
		}

		/++
		++/
		Cell cell(in int x, in int y, in int z)const{
			return cell(ar.Vector3i(x, y, z));
		}

		/++
		++/
		Cell cell(ar.Vector3i position)const{
			auto localPosition = position + origin;
			auto index = localPosition[0] + localPosition[1]*size[0] + localPosition[2]*size[0]*size[1];
			return cast(const(Cell))data[index];
		}

		/++
		++/
		void cell(in Cell c, in int x, in int y, in int z){
			cell(c, ar.Vector3i(x, y, z));
		}

		/++
		++/
		void cell(in Cell c, in ar.Vector3i position){
			auto localPosition = position + origin;
			auto index = localPosition[0] + localPosition[1]*size[0] + localPosition[2]*size[0]*size[1];
			data[index] = c;
		}
		unittest{
			Grid grid = Grid(ar.Vector3i(2, 3, 4));
			assert(grid.cell(1, 2, 3).soil == 0.0);
			Cell c = Cell();
			c.soil = 1.0;
			grid.cell(c, 1, 2, 3);
			assert(grid.cell(1, 2, 3).soil == 1.0);
		}

		/++
		++/
		Grid nbhd(ar.Vector3i target, ar.Vector3i lower, ar.Vector3i upper)const{
			auto grid = Grid(-lower + upper + ar.Vector3i(1, 1, 1), -lower);
			return grid;
		}

		/++
		++/
		void setNbhd(in Grid sourceGrid, in ar.Vector3i targetPosition){
			for (int i = sourceGrid.lowerRange[0]; i <= sourceGrid.upperRange[0]; i++) {
				for (int j = sourceGrid.lowerRange[1]; j <= sourceGrid.upperRange[1]; j++) {
					for (int k = sourceGrid.lowerRange[2]; k <= sourceGrid.upperRange[2]; k++) {
						cell(sourceGrid.cell(i, j, k), targetPosition+ar.Vector3i(i, j, k));
					}
				}
			}
		}
	}//public

	private{
		/++
		++/
		void allocate(){
			auto length = size[0]*size[1]*size[2];
			for(int i = 0; i < length; i++){
				data ~= Cell();
			}
		}

		Cell[] data;
		ar.Vector3i _size;
		ar.Vector3i _origin;
	}//private
}

/++
++/
void each(alias f, G)(G grid){
	for (int i = 0; i < grid.size[0]; i++) {
		for (int j = 0; j < grid.size[1]; j++) {
			for (int k = 0; k < grid.size[2]; k++) {
				ar.Vector3i local_position = ar.Vector3i(i, j, k)-grid.origin;
				f(local_position, grid.cell(local_position));
			}
		}

	}
}

/++
++/
void each(alias f, G)(G grid, GridRange range){
	each(f, G)(grid, range.lowerRange, range.upperRange);
}

/++
++/
void each(alias f, G)(G grid, ar.Vector3i lowerRange, ar.Vector3i upperRange){
	ar.Vector3i min(ar.Vector3i v1, ar.Vector3i v2){
		auto returnVec = ar.Vector3i(0, 0, 0);
		for (int i = 0; i < 3; i++) {
			if(v1[i]>v2[i]){
				returnVec[i] = v2[i];
			}else{
				returnVec[i] = v1[i];
			}
		}
		return returnVec;
	}
	ar.Vector3i max(ar.Vector3i v1, ar.Vector3i v2){
		auto returnVec = ar.Vector3i(0, 0, 0);
		for (int i = 0; i < 3; i++) {
			if(v1[i]<v2[i]){
				returnVec[i] = v2[i];
			}else{
				returnVec[i] = v1[i];
			}
		}
		return returnVec;
	}

	ar.Vector3i checkedLowerRange = min(lowerRange+grid.origin, ar.Vector3i(0, 0, 0));
	ar.Vector3i checkedUpperRange = max(upperRange+grid.origin, grid.size()-ar.Vector3i(1, 1, 1));

	for (int i = checkedLowerRange[0]; i <= checkedUpperRange[0]; i++) {
		for (int j = checkedLowerRange[1]; j <= checkedUpperRange[1]; j++) {
			for (int k = checkedLowerRange[2]; k <= checkedUpperRange[2]; k++) {
				ar.Vector3i local_position = ar.Vector3i(i, j, k)-grid.origin;
				f(local_position, grid.cell(local_position));
			}
		}

	}
}

/++
++/
struct LocalWorld {
	public{
		/++
		++/
		Grid nbhd(ar.Vector3i target, ar.Vector3i lower, ar.Vector3i upper){return Grid();}

		void nbhd(in Grid grid, in ar.Vector3i target){};
		
		this(in GlobalWorld globalWorld, in ar.Vector3i targetPosition, in GridRange range){
			grid = globalWorld.nbhd(targetPosition, range.lowerRange, range.upperRange);
		}
	}//public

	private{
		Grid grid;
	}//private
}

/++
++/
class GlobalWorld{
	public{
		
		/++
		++/
		this(ar.Vector3i size){
			_grid = Grid(size);
		};

		/++
		++/
		Grid nbhd(in ar.Vector3i targetPosition, in ar.Vector3i lower, in ar.Vector3i upper)const{
			lower.print;
			upper.print;
			auto grid = Grid(-lower + upper + ar.Vector3i(1, 1, 1), -lower);
			return grid;
		};

		/++
		++/
		void setLocalWorld(in LocalWorld localWorld, in ar.Vector3i targetPosition){
			_grid.setNbhd(localWorld.grid, targetPosition);
		}

		/++
		++/
		void getLocalWorld(ref LocalWorld localWorld, in ar.Vector3i targetPosition, in GridRange range)const{
			localWorld = LocalWorld(this, targetPosition, range);
		}
	}//public

	private{
		Grid _grid;
	}//private
}

/++
++/
struct PlayerEvent{

}

/++
++/
class Network{
	public{
		/++
		++/
		this(Config config){
			_config = config;
			_world = new GlobalWorld(config.worldSize);
		}

		/++
		++/
		void setLocalWorld(in LocalWorld localWorld, ar.Vector3i targetPosition){
			_world.setLocalWorld(localWorld, targetPosition);
			sync();
		}

		/++
		++/
		void getLocalWorld(ref LocalWorld localWorld, in ar.Vector3i targetPosition, in GridRange range){
			_world.getLocalWorld(localWorld, targetPosition, range);
			sync();
		}

		/++
		++/
		void setPlayerEvent(PlayerEvent){
			sync();
		};

		/++
		++/
		void sync(){}
	}//public

	private{
		GlobalWorld _world;
		Config _config;
	}//private
}

/++
++/
interface ResourceEntity{
}

class CellBox{

}

class ResourceManager {
	public{
		/++
		++/
		void load(in string fileName){
			
		}
		
		/++
		++/
		ResourceEntity opIndex(in string name){
			return data[name];
		}
	}//public

	private{
		ResourceEntity[string] data;
	}//private
}//class Resource

/++
++/
class CellRenderer{
	public{
		/++
		++/
		void draw(in Grid nbhd){
			nbhd.each!((ar.Vector3i position, Cell cell){
				ar.pushMatrix;scope(exit)ar.popMatrix;
				ar.translate(cast(ar.Vector3f)position);
				soilMesh.drawWireFrame;
			});
		}
	}//public
	
	private{
		ar.Mesh soilMesh = ar.boxPrimitive(ar.Vector3f(0, 0, 0), ar.Vector3f(1, 1, 1));
	}//private
}


/++
++/
class WorldRenderer {
	public{
		/++
		++/
		this(Config config, Network network){
			_config = config;
			_network = network;
			_cellRenderer = new CellRenderer;
			_camera = new ar.Camera;
			_camera.target = ar.Vector3f(5, 5, 5);
			_camera.position = ar.Vector3f(5, 5, -20);
		}

		/++
		++/
		double angle = 0;
		void draw(){
			_network.getLocalWorld(_localWorld, cast(ar.Vector3i)_camera.target, GridRange(ar.Vector3i(-3, -3, -3), ar.Vector3i(3, 3, 3)));
			angle += 0.1;
			_camera.begin;
				ar.pushMatrix;
					ar.rotate(angle, 1, 1, 1);
					_cellRenderer.draw(_localWorld.grid);
				ar.popMatrix;
			_camera.end;
		};
	}//public

	private{
		Config _config;
		Network _network;
		CellRenderer _cellRenderer;
		LocalWorld _localWorld;
		ar.Camera _camera;
	}//private
}

/++
++/
class Solver {
	public{
		/++
		++/
		this(Config config, Network network){
			_config = config;
			_network = network;
		}

		/++
		++/
		void solve(){};
	}//public

	private{
		Config _config;
		Network _network;
		LocalWorld _world;
	}//private
}

/++
++/
class TestApp : ar.BaseApp{
	public{
		this(){
			config = new Config();
			network = new Network(config);
			renderer = new WorldRenderer(config, network);
			solver = new Solver(config, network);
		}

		void setup(){
			ar.targetFps = 60;
		}

		void update(){
			// solver.solveWorld;
		}

		void draw(){
			renderer.draw();
			( ar.fpsUseRate*100 ).writeln;
		}
	}//public

	private{
		Config config;
		Network network;
		WorldRenderer renderer;
		Solver solver;
	}//private
}

void main(){
	ar.run(new TestApp);
}
