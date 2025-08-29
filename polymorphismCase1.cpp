//case 1: object creation on stack without virtual keyword

#include<iostream>
using namespace std;

class Employee{
    int id;
    public:
        Employee();
        Employee(int);
        void display();
        int calculateSalary();
};
Employee::Employee(){
    cout<<"In default constructor\n";
    id = 0;
}
Employee::Employee(int i){
    cout<<"In para constructor\n";
    id = i;
}
void Employee::display(){
    cout<<"id is "<<id<<endl;
}
int Employee::calculateSalary(){
    return 0;
}

class WageEmployee:public Employee{
    int hrs,rate;
    public:
        WageEmployee();
        WageEmployee(int,int,int);
        void display();
        int calculateSalary();
};
WageEmployee::WageEmployee(){
    cout<<"In default construct"<<endl;
    hrs=rate=0;
}
WageEmployee::WageEmployee(int i,int h,int r):Employee(i){
    cout<<"In para construct"<<endl;
    hrs = h;
    rate = r;
}
void WageEmployee::display(){
    Employee::display();
    cout<<"hrs is "<<hrs<<endl;
    cout<<"rate is "<<rate<<endl;;
}
int WageEmployee::calculateSalary(){
    return hrs*rate;
}

// class SalesManager:public WageEmployee{
//     int comm,sales;
//     public:
//         SalesManager();
//         SalesManager(int,int,int,int,int);
//         void display();
//         int calculateSalary();
// };
// SalesManager::SalesManager(){
//     cout<<"In default constructor"<<endl;
//     comm=sales=0;
// }
// SalesManager::SalesManager(int i,int h,int r,int s, int c){
//     sales=s;
//     comm = c;
// }
// int SalesManager::calculateSalary(){
//     return WageEmployee::calculateSalary()+comm*sales;
// }
// void SalesManager::display(){
//     WageEmployee::display();
//     cout<<"sales is "<<sales<<endl;
//     cout<<"comm is "<<comm<<endl;
// }

int main(){
    Employee *ptr;
    WageEmployee w(1,2,3);
    ptr = &w;
    cout<<ptr->calculateSalary()<<endl;
    // SalesManager s;
    // ptr = &s;
    // cout<<ptr->calculateSalary()<<endl;
}