#include<iostream>
using namespace std;

class Complex{
    int real;
    int img;
    public:
    Complex(int real,int img){
        this->real=real;
        this->img=img;
    }
    void show(){
        cout<<real<<" "<<img;
    }
};

int main(){
    Complex c(10,20);
    //cout<<this;
    c.show();
}