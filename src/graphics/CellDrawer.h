#pragma once

#include "ofMain.h"
#include "../data/MatrixManager.h"
namespace unitro{
namespace graphics{
	class CellDrawer
	{
	public:
		CellDrawer();
		~CellDrawer();
		
		data::MatrixManager* mM;
		void setup();
		void draw();
	};
}
}