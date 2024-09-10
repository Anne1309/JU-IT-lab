#include<iostream>
using namespace std;

void swap(int &x, int &y)
{
    x+=y-(y=x);
}
int main()
{
   int a,b;
   a = 10; b = 20;
   cout << "Initial value of a = " << a << "\n";
   cout << "Initial value of b = " << b << "\n";
   swap(a,b);
   cout << "Final value of a = " << a << "\n";
   cout << "Final value of b = " << b << "\n";
   return 0;
}
