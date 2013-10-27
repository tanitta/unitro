package trit.unitro

// import org.lwjgl._
// import opengl.{Display,GL11,DisplayMode}
// import GL11._
// import input._
import scala.math
import processing.core._

import trit.unitro._

class Camera(var ps:PApplet){
	var fov = 0.5f
	
	var rotate = 0.0
	
	var ax = 0.0f
	var ay = 0.0f
	var az = 0.0f
	
	var bx = 0.0f
	var by = 0.0f
	var bz = 0.0f
	
	
	
	def setup = {
			
	}
	
	def update = {
		rotate += 0.005
 		var x:Double = 15.0*math.cos(rotate)+Env.Zone.sizX/2.0
 		var z:Double = 15.0*math.sin(rotate)+Env.Zone.sizZ/2.0
		ps.camera( x.toFloat , 15.0f, z.toFloat, // 視点X, 視点Y, 視点Z
		bx+Env.Zone.sizX/2.0f, by+Env.Zone.sizY/2.0f, bz+Env.Zone.sizZ/2.0f, // 中心点X, 中心点Y, 中心点Z
		0.0f, -1.0f, 0.0f); // 天地X, 天地Y, 天地Z
 		ps.perspective(fov, Env.General.sizScreenX.toFloat/Env.General.sizScreenY.toFloat, 0.01f, 400.00f)
		
	}	
}	

class Drawer(var ps:PApplet){
	//parent = p
	
	
	//カメラ
	var camera = new Camera(ps)
	
	def setup = {
		ps.size(Env.General.sizScreenX,Env.General.sizScreenY,PConstants.OPENGL)
		ps.colorMode(PConstants.HSB, 100)
		ps.background(0,0,100)
		ps.smooth()

	}
	var point = Array.ofDim[Float](8,3)
	def soil = {
		for( i <- 0 to Env.Zone.sizX-1) {
			for( j <- 0 to Env.Zone.sizY-1) {
				for( k <- 0 to Env.Zone.sizZ-1) {
					//ps.translate(i,j,k);					
					//ps.box(1);
					//Mtx.soil(i)(j)(k).mass
					point(0)(0) = i-0.5f
					point(0)(1) = j-0.5f
					point(0)(2) = k+0.5f
					
					point(1)(0) = i+0.5f
					point(1)(1) = j-0.5f
					point(1)(2) = k+0.5f
					
					point(2)(0) = i+0.5f
					point(2)(1) = j+0.5f
					point(2)(2) = k+0.5f
					
					point(3)(0) = i-0.5f
					point(3)(1) = j+0.5f
					point(3)(2) = k+0.5f
					
					
					point(4)(0) = i-0.5f
					point(4)(1) = j-0.5f
					point(4)(2) = k-0.5f
					
					point(5)(0) = i+0.5f
					point(5)(1) = j-0.5f
					point(5)(2) = k-0.5f
					
					point(6)(0) = i+0.5f
					point(6)(1) = j+0.5f
					point(6)(2) = k-0.5f
					
					point(7)(0) = i-0.5f
					point(7)(1) = j+0.5f
					point(7)(2) = k-0.5f
					
					// ps.quad(point(0)(0),point(0)(1),point(0)(2),
					// point(1)(0),point(1)(1),point(1)(2),
					// point(2)(0),point(2)(1),point(2)(2),
					// point(3)(0),point(3)(1),point(3)(2)
					// )
					if(Mtx.soil(i)(j)(k).mass>0){ 
						ps.fill(33,Mtx.soil(i)(j)(k).eneN,100)
						ps.pushMatrix()
							ps.translate(i,j,k)
							ps.stroke(33,Mtx.soil(i)(j)(k).eneN,20)
							//ps.noStroke
							ps.box(Mtx.soil(i)(j)(k).eneN/25f)
						ps.popMatrix()
					}
				}
			}
		} 
	}
	def light = {
		ps.lights();
		
		//環境光
	    ps.ambientLight(53,39,10);	
	    //平行光
	    //ps.directionalLight(255,255,255,-1,0,0); 
	    //点光源
	    //ps.pointLight(63, 127, 255, 0, 0, 200); 
	    //スポットライト
	    //ps.spotLight(100, 100, 100, 0, 0, 200, 0, 0, -1, PConstants.PI, 2);	
	}
	
	def draw = {
		ps.background(0,0,100);
		
		this.light
		this.soil
		this.camera.update
		
	 
		ps.stroke(50)
		//ps.box(1);
		var size = 10
		ps.stroke(0,0,0)
		for(i <- -size to size){
			ps.line(i,0,-size,i, 0,size)
			ps.line(-size,0,i,size,0,i)
		}	  
		ps.stroke(0, 100, 100)
		ps.line(0,0,0,1,0,0)
		ps.stroke(100/3, 100, 100)
		ps.line(0,0,0,0,1,0)
		ps.stroke(100/3*2, 100, 100)
		ps.line(0,0,0,0,0,1)
		
		soil
	}
}