#include<iostream>
using namespace std;

inline void add(int a, int b=0, int c=0){
    cout << "Sum of the three values = " << a+b+c << "\n";
}

int main()
{
   
   add(2,3,1);
   add(1,2);
   add(1);
   return 0;
}
