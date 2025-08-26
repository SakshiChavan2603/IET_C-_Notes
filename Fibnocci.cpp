#include<iostream>
using namespace std;

int main() {
    int n, a=0, b=1;
    int sum = 0;
    cout<<"Enter a Number to find Fibnocci Series: ";
    cin>>n;
    
    if(n==0){
        cout<<a<<"\t";
    }
    else{
        cout<<a<<"\t"<<b<<"\t";
        for(int i = 0;i < n; i++) {
            sum = a + b;
            a = b;
            b = sum;
            cout<<sum<<"\t";
        }
    }
}