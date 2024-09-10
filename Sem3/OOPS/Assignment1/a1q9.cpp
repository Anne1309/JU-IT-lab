#include<iostream>
using namespace std;

void swapByAddress(string *x, string *y)
{
    string z = *x;
    *x = *y;
    *y = z;
}
void swapByReference(string &x, string &y)
{
    string z = x;
    x = y;
    y = z;
}
int main()
{
   string a,b;
   a = "Information"; b="Technology";
   cout << "Initial value of a = " << a << "\n";
   cout << "Initial value of b = " << b << "\n";
   swapByAddress(&a,&b);
   cout << "Final value of a swapping by address = " << a << "\n";
   cout << "Final value of b swapping by address = " << b << "\n";
   return 0;}
