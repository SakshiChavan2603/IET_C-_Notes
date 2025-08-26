#include<iostream>
using namespace std;
void show();
int main(){
    show();
    show();
    show();
    show();
}

void show(){
    static int x;
    cout<<x<<endl;
    x++;
}