package trit.unitro

import trit.unitro._

object Mtx{
	var soil = Array.ofDim[SoilCell](Env.Zone.sizX,Env.Zone.sizY,Env.Zone.sizZ)
	var soilB = Array.ofDim[SoilCell](Env.Zone.sizX,Env.Zone.sizY,Env.Zone.sizZ)

	var water = Array.ofDim[SoilCell](Env.Zone.sizX,Env.Zone.sizY,Env.Zone.sizZ)
	var waterB = Array.ofDim[SoilCell](Env.Zone.sizX,Env.Zone.sizY,Env.Zone.sizZ)
		
	
	
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
		
		for( i <- 1 to 6) {
			for( j <- 1 to 6) {
				for( k <- 2 to 9) {

					soil(i)(j)(k).mass = 10.0f
					soilB(i)(j)(k).mass = 10.0f
					
				}
			}
		} 
		Mtx.soil(4)(4)(4).eneN = 1000.0f
		
		for( i <- 0 to Env.Zone.sizX-1) {
			for( j <- 0 to Env.Zone.sizY-1) {
				for( k <- 0 to Env.Zone.sizZ-1) {
					water(i)(j)(k) = new waterCell
					waterB(i)(j)(k) = new waterCell
					
				}
			}
		} 
		
		for( i <- 1 to 6) {
			for( j <- 1 to 6) {
				for( k <- 2 to 9) {

					water(i)(j)(k).mass = 10.0f
					waterB(i)(j)(k).mass = 10.0f
					
				}
			}
		} 
	}
	
	def isVoid(a:Int,b:Int,c:Int) = {
  		if(a < 0 || a > Env.Zone.sizX-1){true}
  		if(b < 0 || b > Env.Zone.sizY-1){true}
  		if(c < 0 || c > Env.Zone.sizZ-1){true}
  		false
  	}
}
