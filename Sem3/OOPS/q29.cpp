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
class B2{
    int b2;
    public:
    void setb2(int z){
        b2=z;
    }
    void show(){
        cout<<"b2= "<<b2<<endl;
    }
};
class C:public B,public B2{
    int c;
    public:
    void setc(int y){
        c=y;
    }
    void show(){
    cout<<"c= "<<c<<endl;
    }
};int main(){
    C ob;
    ob.setc(5);
    ob.setb(10);
    ob.setb2(15);
    ob.show();
}
      