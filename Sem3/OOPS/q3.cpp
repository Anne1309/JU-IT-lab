#include <iostream>
using namespace std;
int main(){
    int n,f=1;
    cout<<"enter limit: ";
    cin>>n;
    for (int i=1;i<=n;i++){
        f=f*i;
        cout<<i<<"! = "<<f<<endl;
    }
    return 0;
}
