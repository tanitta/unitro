module unitro.grid;
import armos;

/++
++/
struct GridRange{
	public{
		/++
		++/
		immutable ar.Vector3i lower;
		
		/++
		++/
		immutable ar.Vector3i upper;
		
		/++
		++/
		this(in ar.Vector3i lower, in ar.Vector3i upper){
			this.lower= lower;
			this.upper= upper;
		};
	}//public
}

/++
++/
struct Grid{
	public{
		ar.Vector3i size()const{return _size;};
		ar.Vector3i origin()const{return _origin;};
		ar.Vector3i lowerRange()const{return -_origin;};
		ar.Vector3i upperRange()const{return  _size - _origin - ar.Vector3i(1, 1, 1);};
		GridRange gridRange()const{return GridRange(lowerRange, upperRange);}
		unittest{
			auto grid = Grid(ar.Vector3i(4, 4, 4), ar.Vector3i(2, 2, 2));
			assert(grid.size == ar.Vector3i(4, 4, 4));
			assert(grid.origin == ar.Vector3i(2, 2, 2));
			assert(grid.lowerRange == ar.Vector3i(-2, -2, -2));
			assert(grid.upperRange == ar.Vector3i(1, 1, 1));
			assert(grid.gridRange == GridRange(ar.Vector3i(-2, -2, -2), ar.Vector3i(1, 1, 1) ));
		}
		

		/++
		++/
		this(in ar.Vector3i size)
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
		this(in ar.Vector3i size, in ar.Vector3i origin)
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
		unitro.Cell cell(in int x, in int y, in int z)const{
			return cell(ar.Vector3i(x, y, z));
		}

		/++
		++/
		unitro.Cell cell(in ar.Vector3i position)const{
			auto localPosition = position + origin;
			auto index = localPosition[0] + localPosition[1]*size[0] + localPosition[2]*size[0]*size[1];
			
			return cast(const(unitro.Cell))data[index];
		}
		
		/++
		++/
		ref unitro.Cell cell(in int x, in int y, in int z){
			return cell(ar.Vector3i(x, y, z));
		}
		
		/++
		++/
		ref unitro.Cell cell(in ar.Vector3i position){
			auto localPosition = position + origin;
			auto index = localPosition[0] + localPosition[1]*size[0] + localPosition[2]*size[0]*size[1];
			return data[index];
		}

		/++
		++/
		void setCell(in unitro.Cell c, in int x, in int y, in int z){
			setCell(c, ar.Vector3i(x, y, z));
		}

		/++
		++/
		void setCell(in unitro.Cell c, in ar.Vector3i position){
			auto localPosition = position + origin;
			auto index = localPosition[0] + localPosition[1]*size[0] + localPosition[2]*size[0]*size[1];
			data[index] = c;
		}
		unittest{
			Grid grid = Grid(ar.Vector3i(2, 3, 4));
			assert(grid.cell(1, 2, 3).soil == 0.0);
			unitro.Cell c = unitro.Cell();
			c.soil = 1.0;
			grid.setCell(c, 1, 2, 3);
			assert(grid.cell(1, 2, 3).soil == 1.0);
		}

		/++
		++/
		Grid nbhd(ar.Vector3i target, ar.Vector3i lower, ar.Vector3i upper)const{
			
			T min(T) (T a, T b)
			{
				return (a < b) ? a : b;
			}

			T max(T) (T a, T b)
			{
				return (a > b) ? a : b;
			}
			
			auto safeGridRange = GridRange(
				ar.Vector3i(
					max(lower[0], this.lowerRange[0]-target[0]),
					max(lower[1], this.lowerRange[1]-target[1]),
					max(lower[2], this.lowerRange[2]-target[2])
				),
				ar.Vector3i(
					min(upper[0], this.upperRange[0]-target[0]),
					min(upper[1], this.upperRange[1]-target[1]),
					min(upper[2], this.upperRange[2]-target[2])
				)
			);
			
			auto grid = Grid(-safeGridRange.lower + safeGridRange.upper + ar.Vector3i(1, 1, 1), -safeGridRange.lower);
			
			for (int i = safeGridRange.lower[0]; i <= safeGridRange.upper[0]; i++) {
				for (int j = safeGridRange.lower[1]; j <= safeGridRange.upper[1]; j++) {
					for (int k = safeGridRange.lower[2]; k <= safeGridRange.upper[2]; k++) {
						grid.setCell(cell(target + ar.Vector3i(i, j, k)), i, j, k);
					}
				}
			}
			return grid;
		}
		
		/++
		++/
		Grid nbhd(ar.Vector3i target, in GridRange gridRange)const{
			return nbhd(target, gridRange.lower, gridRange.upper);
		}
		unittest{
			Grid grid = Grid(ar.Vector3i(2, 3, 4));
			grid.cell(ar.Vector3i(1, 1, 1)).soil = 1;
			auto grid2 = grid.nbhd(ar.Vector3i(1, 1, 1), GridRange(ar.Vector3i(-1, -1, -1), ar.Vector3i(1, 1, 1)));
			assert(grid2.size == ar.Vector3i(2, 3, 3));
			assert(grid2.cell(ar.Vector3i(0, 0, 0)).soil == 1.0);
		}

		/++
		++/
		void setNbhd(in Grid sourceGrid, in ar.Vector3i targetPosition){
			for (int i = sourceGrid.lowerRange[0]; i <= sourceGrid.upperRange[0]; i++) {
				for (int j = sourceGrid.lowerRange[1]; j <= sourceGrid.upperRange[1]; j++) {
					for (int k = sourceGrid.lowerRange[2]; k <= sourceGrid.upperRange[2]; k++) {
						setCell(sourceGrid.cell(i, j, k), targetPosition+ar.Vector3i(i, j, k));
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
				data ~= unitro.Cell();
			}
		}

		unitro.Cell[] data;
		ar.Vector3i _size;
		ar.Vector3i _origin;
	}//private
}
