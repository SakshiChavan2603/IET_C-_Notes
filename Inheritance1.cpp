/*When derived class obj is created memory is allocated for base class 
datamembers as well as for derived class data members. 
Through derived class obj, we can access base class members  as as well as 
derived class members except private 
*/

#include<iostream>
using namespace std;

class Parent{
    public:
        int a;
};

class Child: public Parent{
    public:
         int b;
};

int main() {
    Child c;
    c.a=10;
    c.b=20;
    cout<<"Parent "<<c.a<<endl;
    cout<<"Child "<<c.b<<endl;
    cout<<"size  of c"<<sizeof(c)<<endl;
    // Parent p;
    // p.a = 10; // valid
    // cout<<"size  of p"<<sizeof(p)<<endl; // 4
    // p.b = 20  // error not accessible
}