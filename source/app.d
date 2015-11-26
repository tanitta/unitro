import std.stdio;
import std.math;
import armos;


class Config {
	ar.Vector3i grid_size = ar.Vector3i(10, 10, 10);
	ar.Vector3i renderingRange = ar.Vector3i(4, 4, 4);
}

class Entity{}

class StaticEntity : Entity{}

class DynamicEntity : Entity{
	double mass = 1.0;
	ar.Vector3f position;
	ar.Vector3f velocity;
}

class Plant : StaticEntity{}

class Animal : DynamicEntity{}

class StaticItem : StaticEntity{}

class DynamicItem : DynamicEntity{}

struct Nutrient {
	double positive = 0;
	double negative = 0;
}

class Cell{
	Plant plant;
	StaticItem item;
	DynamicEntity[] entities;
	
	double soil = 0;
	double water = 0;
	Nutrient nutrient;
}

class Grid{
	Cell[][][] data;
	private ar.Vector3i origin_;
	ar.Vector3i origin(){return origin_;}
	
	ar.Vector3i size(){return ar.Vector3i(cast(int)data.length, cast(int)data[0].length, cast(int)data[0][0].length);}
	ar.Vector3i lowerRange(){return -origin_;}
	ar.Vector3i upperRange(){return size+lowerRange-ar.Vector3i(1, 1, 1);}
	
	this(ar.Vector3i size, ar.Vector3i origin_coordination = ar.Vector3i(0, 0, 0)){
		origin_ = origin_coordination;
		data = new Cell[][][](size[0], size[1], size[2]);
		for (int i = 0; i < size[0]; i++) {
			for (int j = 0; j < size[1]; j++) {
				for (int k = 0; k < size[2]; k++) {
					data[i][j][k] = new Cell;
				}
			}
			
		}
	}
	
	void each(void delegate(ar.Vector3i position, Cell cell) f){
		for (int i = 0; i < size[0]; i++) {
			for (int j = 0; j < size[1]; j++) {
				for (int k = 0; k < size[2]; k++) {
					f(ar.Vector3i(i, j, k)-origin, data[i][j][k]);
				}
			}
		}
	}
	
	void each(void delegate(ar.Vector3i) f){
		each((ar.Vector3i position, Cell cell){f(position);});
	}
	
	void each(void delegate(Cell) f){
		each((ar.Vector3i position, Cell c){f(c);});
	}
	unittest{
		auto grid = new Grid(ar.Vector3i(10, 10, 10));
		grid.each(( Cell cell ){ cell.soil = 2.0; } );
		assert(grid.cell(2, 2, 2).soil == 2.0);
		assert(grid.cell(7, 7, 7).soil == 2.0);
	}
	
	void eachNBHD(
		void delegate(NBHD nbhd) f,
		in ar.Vector3i lower_range,
		in ar.Vector3i upper_range 
	){
		each((ar.Vector3i position){
			f(this.nbhd(position, lower_range, upper_range));
		});
	}
	
	void eachNBHD(
		void delegate(NBHD nbhd) f,
		in ar.Vector3i range,
	){
		eachNBHD(f, -range, range);
	}
	
	
	NBHD nbhd(
		in ar.Vector3i target_cell_position,
		in ar.Vector3i range,
	){
		return new NBHD(this, target_cell_position, range);
	}
	
	NBHD nbhd(
		in ar.Vector3i target_cell_position,
		in ar.Vector3i lower_range,
		in ar.Vector3i upper_range 
	){
		return new NBHD(this, target_cell_position, lower_range, upper_range);
	}
	
	ref Cell cell(ar.Vector3i cell_coordination){
		int x = cell_coordination[0] + origin[0];
		int y = cell_coordination[1] + origin[1];
		int z = cell_coordination[2] + origin[2];
		return data[x][y][z];
	}
	
	ref Cell cell(int x, int y, int z){
		return cell(ar.Vector3i(x, y, z));
	}
}
unittest{
	auto grid = new Grid(ar.Vector3i(10, 9, 8), ar.Vector3i(2, 2, 2));
}
unittest{
	auto grid = new Grid(ar.Vector3i(10, 9, 8));
	assert(grid.cell(0, 0, 0).soil == 0);
	grid.cell(0, 0, 0).soil = 2;
	assert(grid.cell(0, 0, 0).soil == 2);
	assert(grid.size[0] == 10);
	assert(grid.lowerRange[0] == 0);
	assert(grid.upperRange[2] == 7);
}

class NBHD : Grid{
	this(
		Grid source_grid,
		in ar.Vector3i target_cell_position,
		in ar.Vector3i range
	){
		this(source_grid, target_cell_position, -range, range);
	}
		
	this(
		Grid source_grid,
		in ar.Vector3i target_cell_position,
		in ar.Vector3i lower_range,
		in ar.Vector3i upper_range 
	){
		import std.math;
		auto lower_range_ = ar.Vector3i();
		auto upper_range_ = ar.Vector3i();
		for(int dim = 0; dim < 3; dim++) {
			lower_range_[dim] = cast(int)fmax(lower_range[dim], source_grid.lowerRange[dim]-target_cell_position[dim]);
			upper_range_[dim] = cast(int)fmin(upper_range[dim], source_grid.upperRange[dim]-target_cell_position[dim]);
		}
		super(ar.Vector3i(1, 1, 1) + upper_range_ - lower_range_, -lower_range_);
		each((ar.Vector3i position){
			cell(position) = source_grid.cell(position + target_cell_position);
		});
	}
}
unittest{
	auto grid = new Grid(ar.Vector3i(10, 10, 10), ar.Vector3i(2, 2, 2));
	grid.cell(1, 1, 1).soil = 2;
	
	auto nbhd = new NBHD(
		grid,
		ar.Vector3i(1, 1, 1), 
		ar.Vector3i(-4, -4, -4), 
		ar.Vector3i(4, 4, 4),
	);
	assert(nbhd.size == ar.Vector3i(8, 8, 8));
	assert(nbhd.origin == ar.Vector3i(3, 3, 3));
	assert(nbhd.lowerRange == ar.Vector3i(-3, -3, -3));
	assert(nbhd.upperRange == ar.Vector3i(4, 4, 4));
	assert(nbhd.cell(0, 0, 0).soil == 2);
	
	nbhd.cell(0, 0, 0).soil = 3;
	assert(grid.cell(1, 1, 1).soil == 3);
}
unittest{
	auto grid = new Grid(ar.Vector3i(10, 10, 10), ar.Vector3i(2, 2, 2));
	grid.cell(1, 1, 1).soil = 2;
	
	auto nbhd = new NBHD(
		grid,
		ar.Vector3i(1, 1, 1), 
		ar.Vector3i(-1, -1, -1), 
		ar.Vector3i(1, 1, 1),
	);
	assert(nbhd.cell(0, 0, 0).soil == 2);
}

class World{
	private Config config;
	Grid grid;
	DynamicEntity[] entities;
	
	this(Config conf){
		config = conf;
		grid = new Grid(config.grid_size); 
	}
}

class Solver{
	private Config config;
	private World world;
	this(Config confg, World world){
		this.config = config;
		this.world = world;
	}
	
	void solveWorld(){}
	
	private void solveCell(NBHD nbhd){}
}

class Renderer{
	private Config config;
	private World world;
	
	ar.Camera camera;

	this(Config config, World world){
		this.config = config;
		this.world = world;
		camera = new ar.Camera;
	}
	
	void drawWorld(){
		camera.start;
		
		auto cameraTargetNBHD = world.grid.nbhd(cast(ar.Vector3i)camera.target, config.renderingRange);
		cameraTargetNBHD.eachNBHD(
			(NBHD nbhd){
				drawCell(nbhd);
			},
			ar.Vector3i(1, 1, 1)
		);
		
		camera.end;
	};
	
	private void drawCell(NBHD nbhd){
		drawPlant(nbhd);
	}
	
	private void drawPlant(NBHD nbhd){}
}


class TestApp : ar.BaseApp{
	private Config config;
	private World world;
	private Solver solver;
	private Renderer renderer;
	
	this(){
		config = new Config();
		world = new World(config);
		solver = new Solver(config, world);
		renderer = new Renderer(config, world);
	}
	
	void setup(){}
	
	void update(){
		solver.solveWorld;
	}
	
	void draw(){
		renderer.drawWorld;
	}
}

void main(){
	ar.run(new TestApp);
}
