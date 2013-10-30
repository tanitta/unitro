package trit.unitro

import trit.unitro._
import scala.math._
class WaterCell extends BaseCell {
	
}



class WaterSolver {
	val co1 = 0.01f//拡散速度
	def solve{
		
		//Mtx.water(4)(4)(4).mass = 10.0f
		//養分の拡散
		for( i <- 1 to Env.Zone.sizX-2) {
			for( j <- 1 to Env.Zone.sizY-2) {
				for( k <- 1 to Env.Zone.sizZ-2) {
					if(Mtx.waterB(i)(j)(k).mass>0){
						if(Mtx.waterB(i-1)(j)(k).mass>0){Mtx.water(i)(j)(k).eneN += (Mtx.waterB(i-1)(j)(k).eneN - Mtx.water(i)(j)(k).eneN)*co1}
						if(Mtx.waterB(i+1)(j)(k).mass>0){Mtx.water(i)(j)(k).eneN += (Mtx.waterB(i+1)(j)(k).eneN - Mtx.water(i)(j)(k).eneN)*co1}

						if(Mtx.waterB(i)(j-1)(k).mass>0){Mtx.water(i)(j)(k).eneN += (Mtx.waterB(i)(j-1)(k).eneN - Mtx.water(i)(j)(k).eneN)*co1}
						if(Mtx.waterB(i)(j+1)(k).mass>0){Mtx.water(i)(j)(k).eneN += (Mtx.waterB(i)(j+1)(k).eneN - Mtx.water(i)(j)(k).eneN)*co1}
						
						if(Mtx.waterB(i)(j)(k-1).mass>0){Mtx.water(i)(j)(k).eneN += (Mtx.waterB(i)(j)(k-1).eneN - Mtx.water(i)(j)(k).eneN)*co1}
						if(Mtx.waterB(i)(j)(k+1).mass>0){Mtx.water(i)(j)(k).eneN += (Mtx.waterB(i)(j)(k+1).eneN - Mtx.water(i)(j)(k).eneN)*co1}
						println(Mtx.water(i)(j)(k).eneN)
					}
				}
			}
		}
		
		
	}
		
	def update{
		Mtx.water.copyToArray(Mtx.waterB)
		
	}
	
}