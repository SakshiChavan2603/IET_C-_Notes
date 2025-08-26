#include<iostream>
using namespace std;
int main(){
    //int * a;
    //float * b;
    int *a = new int;
    float *b = new float;
    *a=10;
    *b=10.5;
    int *c = new int(20);
    cout<<"*a "<<*a<<endl;
    cout<<"*b "<<*b<<endl;
    cout<<"*c "<<*c<<endl;
    delete a;
    delete b;
    delete c;
}