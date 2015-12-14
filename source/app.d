import std.stdio;
import std.math;
import armos;

class Config {
	ar.Vector3i worldSize = ar.Vector3i(10, 10, 10);
	ar.Vector3i renderingRange = ar.Vector3i(4, 4, 4);
}

struct GridRange{
	ar.Vector3i lowerRange;
	ar.Vector3i upperRange;
	this(ar.Vector3i lower, ar.Vector3i upper){
	
	};
}

struct Cell{
	double soil = 0;
}

struct Grid{
	ar.Vector3i size()const{return _size;};
	ar.Vector3i origin()const{return _origin;};
	ar.Vector3i lowerRange()const{return _origin;};
	ar.Vector3i upperRange()const{return -( _size - _origin - ar.Vector3i(1, 1, 1) );};
	GridRange gridRange()const{return GridRange(lowerRange, upperRange);}
	
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
	
	const(Cell) cell(in int x, in int y, in int z){
		return cell(ar.Vector3i(x, y, z));
	}
	
	const(Cell) cell(ar.Vector3i position){
		auto localPosition = position + origin;
		auto index = localPosition[0] + localPosition[1]*size[0] + localPosition[2]*size[0]*size[1];
		return cast(const(Cell))data[index];
	}
	
	void cell(in Cell c, in int x, in int y, in int z){
		cell(c, ar.Vector3i(x, y, z));
	}
	
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
	
	Grid nbhd(ar.Vector3i target, ar.Vector3i lower, ar.Vector3i upper)const{
		auto grid = Grid(-lower + upper + ar.Vector3i(1, 1, 1), -lower);
		return grid;
	}
	
	void setNbhd(in Grid sourceGrid, in ar.Vector3i targetPosition, in GridRange range){
	}
	
	private void allocate(){
		auto length = size[0]*size[1]*size[2];
		for(int i = 0; i < length; i++){
			data ~= Cell();
		}
	}
	
	private Cell[] data;
	private ar.Vector3i _size;
	private ar.Vector3i _origin;
}

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

void each(alias f, G)(G grid, GridRange range){
	each(f, G)(grid, range.lowerRange, range.upperRange);
}

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

struct LocalWorld {
	Grid nbhd(ar.Vector3i target, ar.Vector3i lower, ar.Vector3i upper){return Grid();}
	
	void nbhd(in Grid grid, in ar.Vector3i target){};
	this(in GlobalWorld globalWorld, in ar.Vector3i targetPosition, in GridRange range){
		grid = globalWorld.nbhd(targetPosition, range.lowerRange, range.lowerRange);
	}
	
	private Grid grid;
}

class GlobalWorld{
	
	this(ar.Vector3i size){
		grid = Grid(size);
	};
	
	Grid nbhd(in ar.Vector3i targetPosition, in ar.Vector3i lower, in ar.Vector3i upper)const{
		auto grid = Grid(-lower + upper + ar.Vector3i(1, 1, 1), -lower);
		return grid;
	};
	
	void setNbhd(){
	
	}
	
	void setLocalWorld(in LocalWorld localWorld, in ar.Vector3i targetPosition){
		
	}
	
	void getLocalWorld(ref LocalWorld localWorld, in ar.Vector3i targetPosition, in GridRange range)const{
		localWorld = LocalWorld(this, targetPosition, range);
	}
	
	private Grid grid;
}

struct PlayerEvent{
	
}

class Network{
	this(Config config){
		this.config = config;
		world = new GlobalWorld(config.worldSize);
	}
	
	void setLocalWorld(in LocalWorld localWorld, ar.Vector3i targetPosition){
		world.setLocalWorld(localWorld, targetPosition);
		sync();
	}
	
	void getLocalWorld(ref LocalWorld localWorld, ar.Vector3i targetPosition, GridRange range){
		world.getLocalWorld(localWorld, targetPosition, range);
		sync();
	}
	
	void setPlayerEvent(PlayerEvent){
		sync();
	};
	
	void sync(){}
	
	private GlobalWorld world;
	private Config config;
}

class Renderer {
	Config config;
	Network network;
	// private LocalWorld world = new LocalWorld();
	private LocalWorld world;
	
	this(Config config, Network network){
		this.config = config;
	}
	
	void draw(){};
}

class Solver {
	Config config;
	Network network;
	private LocalWorld world;
	
	this(Config config, Network network){
		this.config = config;
	}
	
	void solve(){};
}

class TestApp : ar.BaseApp{
	private Config config;
	// private GlobalWorld world;
	// private Solver solver;
	private Network network;
	private Renderer renderer;
	private Solver solver;
	
	this(){
		config = new Config();
		network = new Network(config);
		renderer = new Renderer(config, network);
		solver = new Solver(config, network);
	}
	
	void setup(){
		ar.targetFps = 60;
	}
	
	void update(){
		// solver.solveWorld;
	}
	
	void draw(){
		renderer.draw;
		( ar.fpsUseRate*100 ).writeln;
	}
}

void main(){
	// ar.run(new TestApp);
}
