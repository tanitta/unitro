#include "ofMain.h"
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
		
	};
}
}