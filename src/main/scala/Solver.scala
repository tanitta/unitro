package trit.unitro
import trit.unitro._
class Solver {
	var soil = new SoilSolver
	
	def init = {
		
	}
	
	def solve{
		soil.solve
	}
	
	def update = {
		soil.update
	}
}
