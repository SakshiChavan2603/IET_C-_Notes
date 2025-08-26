#include<iostream>
using namespace std;

class Base{
    private: int pvt;
    protected: int prot;
    public: 
        int pub;
        int getPVT(){
            return pvt;
        }
};

class ProtectedDerived: