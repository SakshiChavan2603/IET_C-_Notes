#include<iostream>
using namespace std;

void demo(){
    static int count=1,sum=0;
    sum=sum+count;
    count++;
    cout<<sum<<endl;;
}

int main(){
    for(int i=0;i<5;i++){
        demo();
    }
}

