#pragma once

#include "ofMain.h"
#include "data/MatrixManager.h"
#include "graphics/Drawer.h"
#include "test/VirtualClass.h"

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
		
		// unitro::test::VirtualClass* hoge[10];
	};
}