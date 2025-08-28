#include<iostream> 
using namespace std; 
class employee
{
	int id;
public:
	employee();
	employee(int);
     void display();
	 int findsalary()
	{
		return 0;
	}
};
employee::employee()
{
	cout<<"in default of emp\n";
	id=0;
}
employee::employee(int i)
{
	cout<<"in para of emp\n";
	id=i;
}
void employee::display()
{
	
	cout<<"id of an emp is "<<id<<endl;
}
class wageemployee:public employee
{
	int hrs,rate;
public:
	wageemployee();
	wageemployee(int,int,int);
     void display();
	 int findsalary()
	{
		return hrs*rate;
	}
};
wageemployee::wageemployee()
{
	cout<<"in default of wageemp\n";
	hrs=rate=0;
}
wageemployee::wageemployee(int i,int h,int r):employee(i)
{
	cout<<"in para of wageemp\n";
	hrs=h;
	rate=r;
}
void wageemployee::display()
{
	employee::display();
	cout<<"hrs of an eemp is "<<hrs<<endl;
	cout<<"rate of an eemp is "<<rate<<endl;
	
}
	
class salesperson:public wageemployee
{
	int sales,comm;
public:
salesperson();
salesperson(int,int,int,int,int);
     void display();
	 int findsalary()
	{
		return wageemployee::findsalary() + sales*comm;	
	}
};
salesperson::salesperson()
{
	cout<<"in default of salesperson\n";
	sales=comm=0;
}
salesperson::salesperson(int i,int h,int r,int s,int c):wageemployee(i,h,r)
{
	cout<<"in para of salespersonn";
	sales=s;
	comm=c;
}
void salesperson::display()
{
	wageemployee::display();
	cout<<"sales of an eemp is "<<sales<<endl;
	cout<<"comm of an eemp is "<<comm<<endl;
	
}
int main()
{
	/*wageemployee we1(1,5,1000);
	we1.display();
	cout<<"salary is "<<we1.findsalary();*/
	
	/*wageemployee * ptr=new wageemployee(1,5,1000);
	ptr->display();
	delete ptr;*/
	
	salesperson sp1(1,5,1000,100000,1);
	sp1.display();
	
	
	
}