package trit.EasyLWJGL
import org.lwjgl._
import opengl.{Display,GL11,DisplayMode}
import GL11._
import input._
import math._

object Camera{
  var angle = 0.0f
  var rotationX = 0.0f
  var rotationY = 0.0f
  var posX = 0.0f
  var posY = 0.0f
  var posZ = -15.0f
  
  def setPos(x:Float,y:Float,z:Float){
  	posX = x;
  	posY = y;
  	posZ = z;
  	
  }

  def update{
  	import Keyboard._
    if(isKeyDown(KEY_J))
      rotationY -= 0.8f
    if(isKeyDown(KEY_L))
      rotationY += 0.8f
    if(isKeyDown(KEY_I))
      rotationX -= 0.8f
    if(isKeyDown(KEY_K))
      rotationX += 0.8f
  }

  def apply{
    glLoadIdentity
    glTranslatef(posX,posY,posZ)
    glRotatef(rotationX,1,0,0)
    glRotatef(rotationY,0,0,1)
  }
}

class EasyLWJGL{
	val GAME_TITLE = "My Game"
	val FRAMERATE = 30
	val width = 640
	val height = 480

	// setup needs to be called before display list of player can be created
	init
	
	//
	var finished = false

	def init{
		println("setup Display")
		Display.setTitle(GAME_TITLE)
		Display.setVSyncEnabled(true)
		Display.setDisplayMode(new DisplayMode(width,height))
		setup
		Display.create


		println("setup gl")
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_LIGHTING)
		glEnable(GL_LIGHT0)	
		adjustcam
	}

	def main(args:Array[String]){
		while(!finished){
			Display.update
			
			import Keyboard._
			if(isKeyDown(KEY_ESCAPE))
				finished = true
			if(Display.isCloseRequested)
				finished = true		
					
			update
						
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			draw

			Display.sync(FRAMERATE)
		}
	}

	def cleanup{
		Display.destroy
	}

	def adjustcam{
	    val v = width.toFloat / height.toFloat
	    
	    glMatrixMode(GL_PROJECTION)
	    glLoadIdentity
	    glFrustum(-v,v,-1,1,5,100)
	    glMatrixMode(GL_MODELVIEW)
	}

	def setup{}

	def update{}

	def draw{}
}



// the player is a singleton, because we only have one player
// if we want to make this game into a multiplayer game, we only need to 
// replace object with class, and instanciate some player objects.
// object Player
// {
//	 // short form to setup three variables
//	 var x,y,z = 0f 

//	 val vertexData = BufferUtils.createFloatBuffer(18);
//	 val normalData = BufferUtils.createFloatBuffer(18);
	
//	 vertexData.put(Array[Float](0,0,0.5f, -0.5f,-0.5f,0, -0.5f, 0.5f,0,	0.5f, 0.5f,0,	0.5f,-0.5f,0, -0.5f,-0.5f,0)).flip
//	 normalData.put(Array[Float](0,0,	 1, -1	 ,-1	 ,1, -1	 , 1	 ,1,	1	 , 1	 ,1,	1	 ,-1	 ,1, -1	 ,-1	 ,1)).flip
	
//	 val displayList = glGenLists(1)
	
//	 glEnableClientState(GL_VERTEX_ARRAY)
//	 glEnableClientState(GL_NORMAL_ARRAY)
		
//	 glVertexPointer(3,0,vertexData)
//	 glNormalPointer(0,normalData)
		
//	 glNewList(displayList,GL_COMPILE)
//	 glDrawArrays(GL_TRIANGLE_FAN,0,6)
//	 glEndList
	
//	 glDisableClientState(GL_VERTEX_ARRAY)
//	 glDisableClientState(GL_NORMAL_ARRAY)

//	 def update{
//		 // in scala we can locally import all methods from Keyboard.

//	 }
	
//	 def draw = {
//		 // glPushMatrix
//		 // glTranslatef(x,y,z)
//		 // glRotatef(Camera.angle, 0, 0, 1.0f)
//		 // glColor3f(1, 0, 0)
//		 // glCallList(displayList)
//		 // glPopMatrix
//	 }
// }
