/* creation of Dynamic Array of object on heap section */

// #include<iostream>
// using namespace std;
//  class Student{
//     int roll;
//     char name[20];
//     public:
//         void accept(){
//             cout<<"Enter the roll no\n";
//             cin>>roll;
//             cout<<"enetr the name\n";
//             cin>>name;
//         }

//         void display(){
//             cout<<"Roll no = "<<roll<<" Name ="<<name<<endl;
//         }
// };

// int main(){
//     int n;
//     cout<<"Enter the no of studnets\n";
//     cin>>n;
//     Student* ptr = new Student[n];
//     cout<<"Accept the details: \n";
//     for(int i=0;i<n;i++){
//         ptr[i].accept();  //(ptr+i).accept()
//     }
//     cout<<"Display the details: \n";
//     for(int i=0;i<n;i++){
//         ptr[i].display();
//     }
// }

/*********************************************************** */

/*//accept no of subjects and name from the user dynamically and 
accept marks for each subject and display average and name of the student*/

#include<iostream>
using namespace std;
 class Student{
    int roll;
    char name[20];
    float marks[5];
    public:
        void accept_display(){
            cout<<"Enter the roll no\n";
            cin>>roll;
            cout<<"enetr the name\n";
            cin>>name;
            for(int i=0;i<5;i++){
                cout<<"enetr the marks of sub \n"<<i+1<<endl;
                cin>>marks[i];
            }
            int sum =0;
            for(int i=0;i<5;i++){
                sum = sum+*(marks+i);            //marks[i];
            }
            float avg = (float) sum/5;
            cout<<"Avg is ="<<avg<<endl;
        }
};

int main(){
    int n;
    cout<<"Enter the no of studnets\n";
    cin>>n;
    Student* ptr = new Student[n];
    cout<<"Accept and display the details: \n";
    for(int i=0;i<n;i++){
        ptr[i].accept_display();  //(ptr+i).accept()
    }
}