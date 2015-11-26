import std.stdio;
import std.math;
import armos.app;


class Config {
	armos.math.Vector3i grid_size = armos.math.Vector3i(10, 10, 10);
	armos.math.Vector3i renderingRange = armos.math.Vector3i(4, 4, 4);
}

class Entity{}

class StaticEntity : Entity{}

class DynamicEntity : Entity{
	double mass = 1.0;
	armos.math.Vector3f position;
	armos.math.Vector3f velocity;
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
	private armos.math.Vector3i origin_;
	armos.math.Vector3i origin(){return origin_;}
	
	armos.math.Vector3i size(){return armos.math.Vector3i(cast(int)data.length, cast(int)data[0].length, cast(int)data[0][0].length);}
	armos.math.Vector3i lowerRange(){return -origin_;}
	armos.math.Vector3i upperRange(){return size+lowerRange-armos.math.Vector3i(1, 1, 1);}
	
	this(armos.math.Vector3i size, armos.math.Vector3i origin_coordination = armos.math.Vector3i(0, 0, 0)){
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
	
	void each(void delegate(armos.math.Vector3i position, Cell cell) f){
		for (int i = 0; i < size[0]; i++) {
			for (int j = 0; j < size[1]; j++) {
				for (int k = 0; k < size[2]; k++) {
					f(armos.math.Vector3i(i, j, k)-origin, data[i][j][k]);
				}
			}
		}
	}
	
	void each(void delegate(armos.math.Vector3i) f){
		each((armos.math.Vector3i position, Cell cell){f(position);});
	}
	
	void each(void delegate(Cell) f){
		each((armos.math.Vector3i position, Cell c){f(c);});
	}
	unittest{
		auto grid = new Grid(armos.math.Vector3i(10, 10, 10));
		grid.each(( Cell cell ){ cell.soil = 2.0; } );
		assert(grid.cell(2, 2, 2).soil == 2.0);
		assert(grid.cell(7, 7, 7).soil == 2.0);
	}
	
	void eachNBHD(
		void delegate(NBHD nbhd) f,
		in armos.math.Vector3i lower_range,
		in armos.math.Vector3i upper_range 
	){
		each((armos.math.Vector3i position){
			f(this.nbhd(position, lower_range, upper_range));
		});
	}
	
	void eachNBHD(
		void delegate(NBHD nbhd) f,
		in armos.math.Vector3i range,
	){
		eachNBHD(f, -range, range);
	}
	
	
	NBHD nbhd(
		in armos.math.Vector3i target_cell_position,
		in armos.math.Vector3i range,
	){
		return new NBHD(this, target_cell_position, range);
	}
	
	NBHD nbhd(
		in armos.math.Vector3i target_cell_position,
		in armos.math.Vector3i lower_range,
		in armos.math.Vector3i upper_range 
	){
		return new NBHD(this, target_cell_position, lower_range, upper_range);
	}
	
	ref Cell cell(armos.math.Vector3i cell_coordination){
		int x = cell_coordination[0] + origin[0];
		int y = cell_coordination[1] + origin[1];
		int z = cell_coordination[2] + origin[2];
		return data[x][y][z];
	}
	
	ref Cell cell(int x, int y, int z){
		return cell(armos.math.Vector3i(x, y, z));
	}
}
unittest{
	auto grid = new Grid(armos.math.Vector3i(10, 9, 8), armos.math.Vector3i(2, 2, 2));
}
unittest{
	auto grid = new Grid(armos.math.Vector3i(10, 9, 8));
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
		in armos.math.Vector3i target_cell_position,
		in armos.math.Vector3i range
	){
		this(source_grid, target_cell_position, -range, range);
	}
		
	this(
		Grid source_grid,
		in armos.math.Vector3i target_cell_position,
		in armos.math.Vector3i lower_range,
		in armos.math.Vector3i upper_range 
	){
		import std.math;
		auto lower_range_ = armos.math.Vector3i();
		auto upper_range_ = armos.math.Vector3i();
		for(int dim = 0; dim < 3; dim++) {
			lower_range_[dim] = cast(int)fmax(lower_range[dim], source_grid.lowerRange[dim]-target_cell_position[dim]);
			upper_range_[dim] = cast(int)fmin(upper_range[dim], source_grid.upperRange[dim]-target_cell_position[dim]);
		}
		super(armos.math.Vector3i(1, 1, 1) + upper_range_ - lower_range_, -lower_range_);
		each((armos.math.Vector3i position){
			cell(position) = source_grid.cell(position + target_cell_position);
		});
	}
}
unittest{
	auto grid = new Grid(armos.math.Vector3i(10, 10, 10), armos.math.Vector3i(2, 2, 2));
	grid.cell(1, 1, 1).soil = 2;
	
	auto nbhd = new NBHD(
		grid,
		armos.math.Vector3i(1, 1, 1), 
		armos.math.Vector3i(-4, -4, -4), 
		armos.math.Vector3i(4, 4, 4),
	);
	assert(nbhd.size == armos.math.Vector3i(8, 8, 8));
	assert(nbhd.origin == armos.math.Vector3i(3, 3, 3));
	assert(nbhd.lowerRange == armos.math.Vector3i(-3, -3, -3));
	assert(nbhd.upperRange == armos.math.Vector3i(4, 4, 4));
	assert(nbhd.cell(0, 0, 0).soil == 2);
}
unittest{
	auto grid = new Grid(armos.math.Vector3i(10, 10, 10), armos.math.Vector3i(2, 2, 2));
	grid.cell(1, 1, 1).soil = 2;
	
	auto nbhd = new NBHD(
		grid,
		armos.math.Vector3i(1, 1, 1), 
		armos.math.Vector3i(-1, -1, -1), 
		armos.math.Vector3i(1, 1, 1),
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
	
	armos.graphics.Camera camera;

	this(Config config, World world){
		this.config = config;
		this.world = world;
		camera = new armos.graphics.Camera;
	}
	
	void drawWorld(){
		camera.start;
		
		auto cameraTargetNBHD = world.grid.nbhd(cast(armos.math.Vector3i)camera.target, config.renderingRange);
		cameraTargetNBHD.eachNBHD(
			(NBHD nbhd){
				drawCell(nbhd);
			},
			armos.math.Vector3i(1, 1, 1)
		);
		
		camera.end;
	};
	
	private void drawCell(NBHD nbhd){}
}


class TestApp : armos.app.BaseApp{
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
	armos.app.run(new TestApp);
}