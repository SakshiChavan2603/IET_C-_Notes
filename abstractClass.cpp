//case 4: object creation on heap  with virtual keyword
#include<iostream>
using namespace std;

class Employee {
    int id;
    public:
        Employee();
        Employee(int);
        virtual void display();
        virtual int calculateSalary()=0;
};
Employee::Employee(){
    cout<<"In default of emp\n";
    id =0;
}
Employee::Employee(int i) {
    cout<<"In param of emp\n";
    id = i;
}
void Employee::display() {
    
    cout<<"Id is "<<id<<endl;
}

class WageEmployee:public Employee {
    int hrs, rate;
    public:
        WageEmployee();
        WageEmployee(int, int, int);
        void display();
        int calculateSalary();
        void show();
};
WageEmployee::WageEmployee() {
    cout<<"In default of wage\n";
    hrs = 0;
    rate = 0;
}
WageEmployee::WageEmployee(int i, int h, int r):Employee(i) {
    cout<<"In param of wage\n";
    hrs = h;
    rate = r;
}
void WageEmployee::display() {
    cout<<"hrs"<<hrs<<"rate"<<rate;
}
int WageEmployee::calculateSalary() {
    return hrs * rate;
}
void WageEmployee::show(){
    cout<<"show ";
}

int main() {
    Employee * ptr = new WageEmployee(1,2,3);
    cout<<ptr->calculateSalary()<<endl;
    ptr->display();
    //ptr->show(); it give error because show fun is only iin the derived class
}
