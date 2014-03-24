package trit.unitro
import trit.unitro._
import processing.core._
// import trit.easyprocessing._

object unitro extends processing.core.PApplet{
	var Solver = new Solver
	var Drawer = new Drawer(this)	

  override def setup() {    
  	Drawer.setup
  }
	
	def update = {
		//シミュレータ本体
		Solver.solve//主計算
		Solver.update//Bufferを更新
	}
	override def draw(){
		update 
			
		Drawer.draw  	
  }

  def main(args: Array[String]){
  	runSketch()
  }
}
