#include<iostream>
using namespace std;

void add(int a=40,int b=50,int c=70){
    cout<<a<<"\t"<<b<<"\t"<<c<<"\t"<<endl;
}
//void add(int=1,int =2,int=3);
int main(){
    add();
    add(10);
    add(10,20);
    add(10,20,30);
}

// void add(int a,int b,int c){
//     cout<<a<<"\t"<<b<<"\t"<<c<<"\t"<<endl;
// }