#pragma once

#include "ofMain.h"
#include "CellDrawer.h"
namespace unitro{
namespace graphics{
	class Drawer
	{
	public:
		Drawer();
		~Drawer();
		void setup();
		void update();
		void draw();
		
		
		
		ofRectangle viewport;	
		ofEasyCam mainCam;
		CellDrawer cellDrawer;
	};
}
}