#include <iostream>
#include <cmath>
using namespace std; 
double mod(int r,int i) 
{
	return pow(r*r,i*I,0.5);
}
template <class T>
T maximum (T x, T y)
{
	if (x>y)
	return x;
	else
	return y;
}
template <>
const char* maximum (const char* x,const char* y)
{
	int x1=0, y1=0;
  while (x[x1]!=’\0’)
  {
		x1++;
  }
  while (y[y1]!=’\0’)
  {
		y1++;
  }
  if(xl>yl) 
  return x; 
  else 
  return y;
}
int main()
{
	cout<<"Maximum of 2 integers: "<<maximum(5,6)<<endl;
	int x=1, ix=-1, y=2, iy=-2;
	cout<<"Maximum of mod of complex numbers: "<< maximum(mod(x,ix), mod(y,iy))<<endl;
	cout<<"Maximum of 2 strings: "<< maximum("hi","hello")<<endl;
}
