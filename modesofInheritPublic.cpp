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
class publicDerived:public Base{
    public:
        int getPROT(){
            return prot;
        }
};

int main(){
    publicDerived p;
    int prott=p.getPROT();
    cout<<"Protected data is "<<prott<<endl;
    int pvtt = p.getPVT();
    cout<<"Private data is "<<pvtt<<endl;
    cout<<"Public data is "<<p.pub;
    //cout << "Public = " << p.prot<< endl; //error
}