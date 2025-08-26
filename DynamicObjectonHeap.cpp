/* Dynamic object creation on heap*/

#include<iostream>
using namespace std;

class Cdate{
    int dd,mm,yy;
    public:
        Cdate(){
            dd=mm=yy=0;
        }
        Cdate(int d,int m,int y){
            dd = d;
            mm = m;
            yy = y;
        }

        void show(){
            cout<<dd<<"/"<<mm<<"/"<<yy<<endl;
        }
};

int main(){
    Cdate* ptr =new Cdate();
    ptr->show();
    Cdate* ptr1 = new Cdate(26,8,25);
    ptr1->show();
}