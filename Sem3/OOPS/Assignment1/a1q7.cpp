#include<iostream>
using namespace std;

int fact(const int z)
{
    int f = 1;
    for(int i = 1;i <= z; i++)
    f*=i;
    return f;
}
int main()
{
   int n;
   cout << "Enter a number : ";
   cin >> n;
   int x = fact(n);
   cout << "The factorial of " << n << " = " << x;
   return 0;
}
