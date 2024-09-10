#include<iostream>
using namespace std;


int main()
{
   int i = 100; //initial value of i

   for(int i = 1; i <= 10; i++) // i declared within loop
   {
       cout << "Inside the loop i = " << i << "\n";
   }

    cout << "Initial value of i = " << i; // initial value of i is printed 
   
   return 0;
}
