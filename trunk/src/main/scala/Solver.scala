package trit.unitro
import trit.unitro._
class Solver {
	var soil = new SoilSolver
	var water = new WaterSolver
	def init = {
		
	}
	
	def solve{
		soil.solve
		water.solve
		
	}
	
	def update = {
		soil.update
		water.update
		
	}
}
