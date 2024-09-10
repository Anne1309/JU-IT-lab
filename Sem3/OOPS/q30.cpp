#include <iostream>
using namespace std;
class A{
    int a;
    public:
    void seta(int x){
        a=x;
    }
    void show(){
        cout<<"a="<<a<<endl;
    }
};
class B{
    int b;
    public:
    void setb(int z){
        b=z;
    }
    void show(){
        cout<<"b= "<<b<<endl;
    }
};
class C{
    int c;
    public:
    void setc(int x){
        c=x;
    }
    void show(){

        cout<<"c="<<c<<endl;
    }
};
class D:public A,public B{
    int d;
    public:
    void setd(int y){
        d=y;
    }
    void show(){
    cout<<"d= "<<d<<endl;
    }
};
class E:public B,public C{
    int e;
    public:
    void sete(int y){
        e=y;
    }
    void show(){
    cout<<"e= "<<e<<endl;
    }
};
class F:public D,public E{
    int f;
    public:
    void setf(int y){
        f=y;
    }
    void show(){
    cout<<"f= "<<f<<endl;
    }
};
int main(){
    F ob;
    ob.setf(5);
    ob.show();
}
