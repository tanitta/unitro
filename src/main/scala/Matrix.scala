package trit.unitro

import trit.unitro._

object Mtx{
	var soil = Array.ofDim[SoilCell](Env.Zone.sizX,Env.Zone.sizY,Env.Zone.sizZ)
	var soilB = Array.ofDim[SoilCell](Env.Zone.sizX,Env.Zone.sizY,Env.Zone.sizZ)
	
	init
	
	def init{
		for( i <- 0 to Env.Zone.sizX-1) {
			for( j <- 0 to Env.Zone.sizY-1) {
				for( k <- 0 to Env.Zone.sizZ-1) {
					soil(i)(j)(k) = new SoilCell
					soilB(i)(j)(k) = new SoilCell
				}
			}
		} 	
			
	}
}
