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
}

struct Cell{
	double soil = 0;
}

struct Grid{
	ar.Vector3i size()const{return _size;};
	ar.Vector3i origin()const{return _origin;};
	ar.Vector3i lowerRange()const{return _origin;};
	ar.Vector3i upperRange()const{return -( _size - _origin - ar.Vector3i(1, 1, 1) );};
	
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

struct LocalWorld {
	Grid grid;
	Grid nbhd(ar.Vector3i target, ar.Vector3i lower, ar.Vector3i upper){return Grid();}
	void nbhd(in Grid grid, in ar.Vector3i target){};
	this(GlobalWorld globalWorld, ar.Vector3i targetPosition, GridRange range){
		grid = globalWorld.nbhd(targetPosition, range.lowerRange, range.lowerRange);
	}
}

class GlobalWorld{
	Grid grid;
	this(ar.Vector3i size){
		grid = Grid(size);
	};
	
	Grid nbhd(ar.Vector3i targetPosition, ar.Vector3i lower, ar.Vector3i upper){
		auto grid = Grid(-lower + upper + ar.Vector3i(1, 1, 1), -lower);
		return grid;
	};
	
	void set(in LocalWorld localWorld, in ar.Vector3i targetPosition){
	
	}
}

struct PlayerEvent{
}

class Network{
	private GlobalWorld world;
	Config config;
	
	this(Config config){
		this.config = config;
		world = new GlobalWorld(config.worldSize);
	}
	
	void getLocalWorld(ref LocalWorld localWorld, ar.Vector3i targetPosition, GridRange range){
		localWorld = LocalWorld(world, targetPosition, range);
		sync();
	}
	
	void setLocalWorld(in LocalWorld localWorld, ar.Vector3i targetPosition){
		world.set(localWorld, targetPosition);
		sync();
	}
	
	void setPlayerEvent(PlayerEvent){
		sync();
	};
	
	void sync(){}
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
	ar.run(new TestApp);
}
