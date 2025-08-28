#include<iostream>
using namespace std;

class Base{
    int pvt=1;
    protected: int prot=2;
    public:
        int pub =3;
        int getPVT(){
            return pvt;
        }
};

class PrivateDerived:private Base{
    public: 
        int getPROT(){
            return prot;
        }
};

int main(){
    PrivateDerived p;
    cout<<"Prot "<<p.getPROT()<<endl;
    //cout<<"pvt "<<p.getPVT()<<endl; // it becomes private in sub class
    //cout<<"pub "<<p.pub<<endl; //it becomes private in sub class
}