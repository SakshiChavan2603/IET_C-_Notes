#include<iostream>
using namespace std;

int main(){
    char *str;
    str = new char[50];
    cout<<"Enetr the name \n";
    cin>>str;
    delete [] str;
    
}