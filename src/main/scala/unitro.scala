package trit.unitro

import org.lwjgl._
import opengl.{Display,GL11,DisplayMode}
import GL11._
import input._
import math._

import trit.EasyLWJGL._
import trit.unitro._


object unitro extends EasyLWJGL {
 
	override def setup{//初期化時の処理を記述
		Display.setTitle("unitro")
	}
	
	override def update{//毎フレーム実行させたい処理を記述
		Camera.update
		//シミュレータ本体
		//Soil
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
	
	override def draw{//描画処理を記述
		Camera.apply
		glColor3f(0.5f,0.3f,0.1f)
		//	ポリゴンの表示面の指定を有効にする
		glEnable(GL_CULL_FACE);
		//	ポリゴンの表示面を表（裏を表示しない）のみに設定する
		glCullFace(GL_BACK);
		val size = 10
		
		glDisable(GL_LIGHTING)
			glBegin(GL_QUADS);
				glVertex3f(-0.5f, -0.5f, 0); //	 1 つめの頂点の座標を指定する
				glVertex3f(0.5f, -0.5f, 0);		 //	2 つめの頂点の座標を指定する
				glVertex3f(0.5f, 0.5f, 0);							 // 3 つめの頂点の座標を指定する
				glVertex3f(-0.5f, 0.5f, 0);			 // 4 つめの頂点の座標を指定する
				//	四角形の表示おしまい
			glEnd();
			
			glColor3f(0.2f, 0.2f, 0.2f);
			glBegin(GL_LINES)
			for(i <- -size to size){
				glVertex2i(i,-size)
				glVertex2i(i, size)
				glVertex2i(-size,i)
				glVertex2i( size,i)
			}
			glEnd
		glEnable(GL_LIGHTING)
	}
}