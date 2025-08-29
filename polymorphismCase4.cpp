//case 4: object creation on heap  with virtual keyword
#include<iostream>
using namespace std;

class Employee {
    int id;
    public:
        Employee();
        Employee(int);
        virtual void display();
        virtual int calculateSalary();
};
Employee::Employee(){
    id =0;
}
Employee::Employee(int i) {
    id = i;
}
void Employee::display() {
    cout<<"Id is "<<id<<endl;
}
int Employee::calculateSalary() {
    return 0;
}

class WageEmployee:public Employee {
    int hrs, rate;
    public:
        WageEmployee();
        WageEmployee(int, int, int);
        void display();
        int calculateSalary();
};
WageEmployee::WageEmployee() {
    hrs = 0;
    rate = 0;
}
WageEmployee::WageEmployee(int i, int h, int r):Employee(i) {
    hrs = h;
    rate = r;
}
void WageEmployee::display() {
    cout<<"hrs"<<hrs<<"rate"<<rate;
}
int WageEmployee::calculateSalary() {
    return hrs * rate;
}

int main() {
    Employee * ptr = new WageEmployee(1,2,3);
    
    cout<<ptr->calculateSalary()<<endl;
    ptr->display();
}
