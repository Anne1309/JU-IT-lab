#include<iostream>
using namespace std;

int Maximum(int a, int b, int c)
{
    return (a>b&&a>c)? a : (b>c) ? b : c;
}

int Maximum(int arr[], int n)
{
    int m = arr[0];
    for(int i = 1; i < n; i++)
    m = max(m,arr[i]);

    return m;
}


int main()
{
    int x,y,z;
    cout << "Enter 3 numbers : \n";
    cin >> x >> y >> z;
    cout << "Maximum of the three numbers is = " << Maximum(x,y,z) << "\n";
    int n;
    cout << "Enter the size of the array : ";
    cin >> n;
    int a[n];
    cout << "Enter the elements of the array : \n";
    for(int i = 0; i < n ;i++)
    cin >> a[i];
    cout << "Maximum number in the array is = " << Maximum(a,n);
   return 0;
}
