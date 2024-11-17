#include <iostream>
using namespace std; 
class Test 
{ 
  public: 
  class Custom 
  { 
    const char* description; 
    public: 
    Custom(const char* desc) 
    { 
      description=desc; 
    } 
    void disp() 
    { 
      cout<<description<<endl;
    }
	};
  void Test()
	{
	  Throw Custom(“Testing the Exception class”);
	}
};

int main() {
	Test obj;
	try{
		Obj.test();
	}
	catch (Test:::Custom ob) {
		Ob.disp();
	}
	return 0;
}
