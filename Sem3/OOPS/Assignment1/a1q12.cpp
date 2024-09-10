#include<iostream>
using namespace std;

inline int add(int a, int b, int c){
    return a+b+c;
}

int main()
{
   int x,y,z;
   cout << "Enter three numbers : ";
   cin >> x >> y >> z;
   cout << "\nSum of the three numbers = " << add(x,y,z);
   return 0;
}
