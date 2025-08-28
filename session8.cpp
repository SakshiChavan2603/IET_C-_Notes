// Write a student class and use it in your program.
// Store the data of 10 students and display
//  the sorted data according to their roll numbers, dates of birth, 
//and total marks

#include<iostream>
using namespace std;
class Student{
    public:
    int roll_no;
    //int roll[2];
    char dob[10];
    int marks[2];
    public:
        void accept(){
            cout<<"Enetr the roll no\n";
            cin>>roll_no;
            cout<<"Enetr the date of birth\n";
            cin>>dob;
            cout<<"Eneter the marks\n";
            for(int i=0;i<2;i++){
                cin>>marks[i];
            }
        }
        
        void display(){
            int sum=0;
            for(int i=0;i<2;i++){
                //cout<<marks[i]<<"\t";
                sum = sum+marks[i];
            }
            cout<<"Roll No is "<<roll_no<<endl;
            cout<<"DOB is "<<dob<<endl;
            cout<<"Total marks is "<<sum<<endl;
        }
};

int main(){
    int num =2;
    Student s[num];
    for(int i=0;i<num;i++){
        s[i].accept();
    }
    for(int i=0;i<num-1;i++){
        for(int j=0;j<num-1-i;j++){
            if(s[j].roll_no > s[j+1].roll_no){
                int temp = s[j].roll_no;
                s[j].roll_no = s[j+1].roll_no;
                s[j+1].roll_no = temp;
            }
        }
    }
    cout<<"Display details:\n";   
    for(int i=0;i<num;i++){
        s[i].display();
    }
}