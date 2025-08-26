#include<iostream>
using namespace std;

class Employee{
    int id;
    char name[20];
    public:
        void getdata();
        void putdata();
};

void Employee::getdata(){
    cout<<"Enter the id"<<endl;
    cin>>id;
    cout<<"Enter the name"<<endl;
    cin>>name;
}
void Employee::putdata(){
    cout<<id<<" "<<name<<endl;
}

int main(){
    Employee e[30];
    int n;
    cout<<"Enter the no of emp prenst today\n";
    cin>>n;
    cout<<"Accept the no of employee\n";
    for(int i=0;i<n;i++){
        e[i].getdata();
    }
    cout<<"display data of employee\n";
    for(int i=0;i<n;i++){
        e[i].putdata();
    }
}