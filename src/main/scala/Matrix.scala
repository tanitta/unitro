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
		
		for( i <- 1 to 6) {
			for( j <- 1 to 6) {
				for( k <- 2 to 9) {

					soil(i)(j)(k).mass = 10.0f
					soilB(i)(j)(k).mass = 10.0f
					
				}
			}
		} 
		Mtx.soil(4)(4)(4).eneN = 1000.0f
		
		
		// Mtx.soil(1)(1)(1).mass = 10.0f
		// Mtx.soil(1)(1)(2).mass = 10.0f
		// Mtx.soil(1)(1)(3).mass = 10.0f
		// Mtx.soil(1)(1)(4).mass = 10.0f
		// Mtx.soil(1)(1)(6).mass = 10.0f
		
		
		// Mtx.soil(1)(3)(1).mass = 10.0f
		// Mtx.soil(2)(2)(2).mass = 10.0f
		// Mtx.soil(3)(2)(3).mass = 10.0f
		// Mtx.soil(2)(1)(1).mass = 10.0f	
		// Mtx.soil(2)(1)(1).mass = 10.0f
		// Mtx.soil(2)(2)(1).mass = 10.0f
		
		// Mtx.soil(2)(1)(0).mass = 10.0f	
		
		
		// Mtx.soil(5)(1)(5).mass = 10.0f
		// Mtx.soil(5)(1)(5).eneN = 100.0f		
					
		// Mtx.soil(5)(2)(5).mass = 10.0f		
		// Mtx.soil(5)(3)(5).mass = 10.0f
		// Mtx.soil(5)(4)(5).mass = 10.0f		
		// Mtx.soil(5)(5)(5).mass = 10.0f		
		// Mtx.soil(5)(6)(5).mass = 10.0f		
		// Mtx.soil(5)(7)(5).mass = 10.0f
		// Mtx.soil(5)(8)(5).mass = 10.0f		
		// Mtx.soil(5)(9)(5).mass = 10.0f
		// Mtx.soil(5)(7)(5).eneN = 100.0f		
				
				
				
			
	}
	
	def isVoid(a:Int,b:Int,c:Int) = {
  		if(a < 0 || a > Env.Zone.sizX-1){true}
  		if(b < 0 || b > Env.Zone.sizY-1){true}
  		if(c < 0 || c > Env.Zone.sizZ-1){true}
  		false
  	}
}
