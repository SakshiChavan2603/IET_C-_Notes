#include<iostream>
using namespace std;

class Complex{
    public:
    static int count;
};
int Complex::count=10;
int main(){
    cout<<Complex::count;
}

// class Complex{
//     static int real,img;
//     public:
//     Complex(){
//         real=1;
//         img=2;
//     }
//     Complex(int a, int b){
//         real =a;
//         img = b;
//     }
//     static void show(){
//         cout<<real<<img<<endl;
//     }
// };
// int main(){
//     Complex c;
//     c.show();
//     c.show(10,20);
// }
