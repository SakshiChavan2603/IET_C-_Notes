#include<iostream>
using namespace std;

class A{
        int a;
        void show(){

        }
};
class B{
        int a;
        virtual void show(){
            
        }
};

int main(){
    A a;
    B b;
    cout<<"Size of A is "<<sizeof(a)<<endl;
    cout<<"Size of B is "<<sizeof(b)<<endl;
}