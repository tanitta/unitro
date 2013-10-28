package trit.unitro

import trit.unitro._
import scala.math._
class SoilCell extends BaseCell {
	
}



class SoilSolver {
	val co1 = 0.01f//拡散速度
	var count = 0.0
	def solve{
		count += 0.01
		Mtx.soil(2)(2)(2).eneN = sin(count).toFloat*100+100
		Mtx.soil(5)(6)(6).eneN = -sin(count+0.1).toFloat*100-100
		
		//Mtx.soil(4)(4)(4).mass = 10.0f
		//養分の拡散
		for( i <- 1 to Env.Zone.sizX-2) {
			for( j <- 1 to Env.Zone.sizY-2) {
				for( k <- 1 to Env.Zone.sizZ-2) {
					if(Mtx.soilB(i)(j)(k).mass>0){
						if(Mtx.soilB(i-1)(j)(k).mass>0){Mtx.soil(i)(j)(k).eneN += (Mtx.soilB(i-1)(j)(k).eneN - Mtx.soil(i)(j)(k).eneN)*co1}
						if(Mtx.soilB(i+1)(j)(k).mass>0){Mtx.soil(i)(j)(k).eneN += (Mtx.soilB(i+1)(j)(k).eneN - Mtx.soil(i)(j)(k).eneN)*co1}

						if(Mtx.soilB(i)(j-1)(k).mass>0){Mtx.soil(i)(j)(k).eneN += (Mtx.soilB(i)(j-1)(k).eneN - Mtx.soil(i)(j)(k).eneN)*co1}
						if(Mtx.soilB(i)(j+1)(k).mass>0){Mtx.soil(i)(j)(k).eneN += (Mtx.soilB(i)(j+1)(k).eneN - Mtx.soil(i)(j)(k).eneN)*co1}
						
						if(Mtx.soilB(i)(j)(k-1).mass>0){Mtx.soil(i)(j)(k).eneN += (Mtx.soilB(i)(j)(k-1).eneN - Mtx.soil(i)(j)(k).eneN)*co1}
						if(Mtx.soilB(i)(j)(k+1).mass>0){Mtx.soil(i)(j)(k).eneN += (Mtx.soilB(i)(j)(k+1).eneN - Mtx.soil(i)(j)(k).eneN)*co1}
						println(Mtx.soil(i)(j)(k).eneN)
					}
				}
			}
		}
		
		
	}
		
	def update{
		Mtx.soil.copyToArray(Mtx.soilB)
		
	}
	
}