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
	auto mesh = ar.boxPrimitive(
			ar.Vector3f(0, 0, 0), 
			ar.Vector3f(1, 1, 1)
		);
	
	double soil = 0;
	double water = 0;
	Nutrient nutrient;
	
	void draw(NBHD nbhd){
		mesh.drawWireFrame;
	};
}

class Grid{
	Cell[][][] data;
	private ar.Vector3i origin_;
	
	ar.Vector3i origin()const{return origin_;}
	ar.Vector3i size()const{return ar.Vector3i(cast(int)data.length, cast(int)data[0].length, cast(int)data[0][0].length);}
	ar.Vector3i lowerRange()const{return -origin_;}
	ar.Vector3i upperRange()const{return size+lowerRange-ar.Vector3i(1, 1, 1);}
	
	this(in ar.Vector3i size, in ar.Vector3i origin_coordination = ar.Vector3i(0, 0, 0)){
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
	
	unittest{
		auto grid = new Grid(ar.Vector3i(10, 10, 10));
		grid.each!((ar.Vector3i vec,  Cell cell ){ cell.soil = 2.0; } );
		assert(grid.cell(2, 2, 2).soil == 2.0);
		assert(grid.cell(7, 7, 7).soil == 2.0);
	}
	
	
	NBHD nbhd(
		in ar.Vector3i target_cell_position,
		in ar.Vector3i range,
	){
		return NBHD(this, target_cell_position, range);
	}
	
	NBHD nbhd(
		in ar.Vector3i target_cell_position,
		in ar.Vector3i lower_range,
		in ar.Vector3i upper_range 
	){
		return NBHD(this, target_cell_position, lower_range, upper_range);
	}
	
	ref Cell cell(in ar.Vector3i cell_coordination){
		int x = cell_coordination[0] + origin[0];
		int y = cell_coordination[1] + origin[1];
		int z = cell_coordination[2] + origin[2];
		return data[x][y][z];
	}
	
	ref Cell cell(in int x, in int y, in int z){
		return cell(ar.Vector3i(x, y, z));
	}
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

struct NBHD{
	private Grid grid;
	private ar.Vector3i lowerRange_;
	private ar.Vector3i upperRange_;
	private ar.Vector3i targetCellPosition;
	
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
		targetCellPosition = target_cell_position;
		grid = source_grid;
		lowerRange_ = ar.Vector3i();
		upperRange_ = ar.Vector3i();
		for(int dim = 0; dim < 3; dim++) {
			lowerRange_[dim] = cast(int)fmax(lower_range[dim], source_grid.lowerRange[dim]-target_cell_position[dim]);
			upperRange_[dim] = cast(int)fmin(upper_range[dim], source_grid.upperRange[dim]-target_cell_position[dim]);
		}
	}
	
	ar.Vector3i size()const{
		return -lowerRange + upperRange + ar.Vector3i(1, 1, 1);
	}
	
	ar.Vector3i origin()const{
		return -lowerRange;
	}
	
	ar.Vector3i lowerRange()const{
		return lowerRange_;
	}
	
	ar.Vector3i upperRange()const{
		return upperRange_;
	}
	
	Cell cell(in ar.Vector3i local_pos){
		return grid.cell(local_pos+targetCellPosition);
	}
	
	Cell cell(in int x, in int y, in int z){
		return cell(ar.Vector3i(x, y, z));
	}
	
	NBHD nbhd(
		in ar.Vector3i target_cell_position,
		in ar.Vector3i range,
	){
		return NBHD(grid, target_cell_position+targetCellPosition, range);
	}
	
	NBHD nbhd(
		in ar.Vector3i target_cell_position,
		in ar.Vector3i lower_range,
		in ar.Vector3i upper_range 
	){
		return NBHD(grid, target_cell_position+targetCellPosition, lower_range, upper_range);
	}
}
unittest{
	auto grid = new Grid(ar.Vector3i(10, 10, 10), ar.Vector3i(2, 2, 2));
	grid.cell(1, 1, 1).soil = 2;
	
	auto nbhd = NBHD(
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
	
	auto nbhd = NBHD(
		grid,
		ar.Vector3i(1, 1, 1), 
		ar.Vector3i(-1, -1, -1), 
		ar.Vector3i(1, 1, 1),
	);
	assert(nbhd.cell(0, 0, 0).soil == 2);
	
	auto nbhd1 = nbhd.nbhd(ar.Vector3i(1, 1, 1), ar.Vector3i(1, 1, 1));
	assert(nbhd1.cell(-1, -1, -1).soil == 2);
}

class GlobalWorld{
	private Config config;
	Grid grid;
	DynamicEntity[] entities;
	
	this(Config conf){
		config = conf;
		grid = new Grid(config.grid_size); 
	}
}

class LocalWorld{
	private Config config;
	Grid grid;
	DynamicEntity[] entities;
	this(Config conf){
		config = conf;
		auto grid_size = config.renderingRange*2 +ar.Vector3i(1, 1, 1);
		auto origin = config.renderingRange;
		grid = new Grid(grid_size, origin); 
	}
}

class Solver{
	private Config config;
	private GlobalWorld world;
	this(Config confg, GlobalWorld world){
		this.config = config;
		this.world = world;
	}
	
	void solveWorld(){}
	
	private void solveCell(NBHD nbhd){}
}

class Renderer{
	private Config config;
	private GlobalWorld world;
	
	ar.Camera camera;

	this(Config config, GlobalWorld world){
		this.config = config;
		this.world = world;
		camera = new ar.Camera;
		camera.position = ar.Vector3f(0, 0, -40);
		camera.target= ar.Vector3f(2, 4, 0);
	}
	
	int counter = 0;
	
	void drawWorld(){
		counter++;
		camera.begin;
		ar.rotate(counter, ar.Vector3f(1, 1, 1));
		auto cameraTargetNBHD = world.grid.nbhd(cast(ar.Vector3i)camera.target, config.renderingRange);
		auto func = delegate void(ar.Vector3i position, Cell cell){
			ar.pushMatrix;
			ar.translate(cast(ar.Vector3f)position + camera.target);
			cell.draw(
				cameraTargetNBHD.nbhd(position, ar.Vector3i(1, 1, 1))
			);
			ar.popMatrix;
		};
		cameraTargetNBHD.each!(func);
		camera.end;
	};
}

class Network{
	GlobalWorld world;
	this(GlobalWorld world){
		this.world = world;
	}
	
	
	
	NBHD nbhd(){
		return NBHD();
	};
	
	void updateCell(
		in ar.Vector3i globalPosition,
		in ar.Vector3i lowerRange,
		in ar.Vector3i upperRange
	){
	
	};
	
	// void touchCell(in ar.Vector3i localPosition, in ToolType toolType){}
}

class TestApp : ar.BaseApp{
	private Config config;
	private GlobalWorld world;
	private Network network;
	private Solver solver;
	private Renderer renderer;
	
	this(){
		config = new Config();
		world = new GlobalWorld(config);
		network = new Network(world);
		solver = new Solver(config, world);
		renderer = new Renderer(config, world);
		
		world.grid.each!(
			(ar.Vector3i vec, Cell cell){
				cell.soil = 0.5;
			}
		);
	}
	
	void setup(){
		ar.targetFps = 60;
	}
	
	void update(){
		solver.solveWorld;
	}
	
	void draw(){
		renderer.drawWorld;
		( ar.fpsUseRate*100 ).writeln;
	}
}

void main(){ar.run(new TestApp);}
