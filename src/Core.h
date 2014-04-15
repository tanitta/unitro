#pragma once

#include "ofMain.h"
#include "data/MatrixManager.h"
#include "graphics/Drawer.h"

namespace unitro{
	class Core
	{
	public:
		Core();
		~Core();
		
		void setup();
		void update();
		void draw();
		
		// unitro::data::MatrixManager matrixManager;
		unitro::graphics::Drawer drawer;
	};
}