#include<iostream>
using namespace std;

int main()
{
   int c;
   double f;
   for(c = 0; c <= 100; c++)
   {
       f = (9.0/5.0) * c + 32;
       cout << "Celsius = " << c << " Fahrenheit = " << f << "\n";
   }
   return 0;
}
