#include<iostream>
using namespace std;

class Base{
    private: int pvt=1;
    protected: int prot=2;
    public: 
        int pub=3;
        int getPVT(){
            return pvt;
        }
};

class ProtectedDerived:protected Base{
    public:
        int getPROT(){
            return prot;
        }
};


int main(){
    ProtectedDerived p;
    cout<<"prot "<<p.getPROT()<<endl;
    // cout<<"pvt "<<p.getPVT()<<endl; //because it become protected so
    // cout<<"pub "<<p.pub<<endl; //because it become protected
    // cout<<"prot "<<p.prot<<endl; // because it is a protected

}