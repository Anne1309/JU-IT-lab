#include <iostream>
using namespace std;
class B{
    int b;
    public:
    void setb(int x){
        b=x;
    }
    void show(){
        cout<<"b="<<b<<endl;
    }
};
class C:public B{
    int c;
    public:
    void setc(int y){
        c=y;
    }
    void show(){
        cout<<"c= "<<c<<endl;
    }
};
int main(){
    C ob;
    ob.setc(5);
    ob.setb(10);
    ob.show();
}
