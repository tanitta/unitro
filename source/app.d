import std.stdio;
import std.math;
import armos.app;


class Config {
	armos.math.Vector3i grid_size = armos.math.Vector3i(10, 10, 10);
}

class Cell{
	double soil = 0;
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
		for (int i = lower_range_[0]; i < upper_range_[0]; i++) {
			for (int j = lower_range_[1]; j < upper_range_[1]; j++) {
				for (int k = lower_range_[2]; k < upper_range_[2]; k++) {
					cell(i, j, k) = source_grid.cell(armos.math.Vector3i(i, j, k) + target_cell_position);
				}
			}
			
		}
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
	Config config;
	Grid grid;
	this(Config conf){
		config = conf;
		grid = new Grid(config.grid_size); 
	}
}

class Solver{
	void solveCell(NBHD nbhd){
	
	}
}

class Renderer{
	void drawCell(NBHD nbhd){
	}
}

class TestApp : armos.app.BaseApp{
	Config config;
	World world;
	
	this(){
		config = new Config;
		world = new World(config);
	}
	
	void setup(){}
	
	void update(){}
	
	void draw(){}
}

void main(){
	armos.app.run(new TestApp);
}
