#include "ofMain.h"
namespace unitro{
namespace test{
	class VirtualClass
	{
	public:
		VirtualClass(){};
		~VirtualClass(){};
		virtual void test(){};	
	};
	
	class HogeClass1 : public VirtualClass
	{
	public:
		HogeClass1(){};
		~HogeClass1(){};
		void test(){test1();};
		void test1(){cout<<"HogeClass1::test1\n";};
	};
	
	class HogeClass2 : public VirtualClass
	{
	public:
		void test(){test2();};
		void test2(){cout<<"HogeClass2::test2\n";};
		
	};
}
}