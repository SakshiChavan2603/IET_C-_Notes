#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the no of studnets\n";
    cin>>n;
    float * GPA = new float[n];

    cout<<"Enter the GPA of students\n";
    for(int i=0;i<n;i++){
        cout<<"Studnet "<<i+1<<":"<<endl;
        cin>>*(GPA+i);               //GPA[i];
    }

    cout<<"Display GPA of students\n";
    for(int i=0;i<n;i++){
        cout<<"Studnet "<<i+1<<":"<<*(GPA+i)<<endl;         //GPA[i];
    }
    
    delete [] GPA;

}