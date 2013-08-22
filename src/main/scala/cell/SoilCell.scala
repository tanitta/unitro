package trit.unitro

import trit.unitro._

class SoilCell extends BaseCell {
	
}



class SoilSolver {
	
	def soil{
		Mtx.soil(4)(4)(4).mass = 10.0f
		val co1 = 0.3f
		for( i <- 1 to Env.Zone.sizX-2) {
			for( j <- 1 to Env.Zone.sizY-2) {
				for( k <- 1 to Env.Zone.sizZ-2) {
					Mtx.soil(i)(j)(k).mass += (Mtx.soilB(i-1)(j)(k).mass - Mtx.soil(i)(j)(k).mass)*co1
					Mtx.soil(i)(j)(k).mass += (Mtx.soilB(i+1)(j)(k).mass - Mtx.soil(i)(j)(k).mass)*co1

					Mtx.soil(i)(j)(k).mass += (Mtx.soilB(i)(j-1)(k).mass - Mtx.soil(i)(j)(k).mass)*co1
					Mtx.soil(i)(j)(k).mass += (Mtx.soilB(i)(j+1)(k).mass - Mtx.soil(i)(j)(k).mass)*co1
					
					Mtx.soil(i)(j)(k).mass += (Mtx.soilB(i)(j)(k-1).mass - Mtx.soil(i)(j)(k).mass)*co1
					Mtx.soil(i)(j)(k).mass += (Mtx.soilB(i)(j)(k+1).mass - Mtx.soil(i)(j)(k).mass)*co1
				}
			}
		}
		
		Mtx.soil.copyToArray(Mtx.soilB)
	}
}