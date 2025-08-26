//Access Specifier private,protected,public

#include<iostream>
using namespace std;

// class Circle{
//     int radius;
//     public:
//         float area(){
//             return 3.14*radius*radius;
//         }
// };

// int main(){
//     Circle c;
//     //c.radius;
//     c.area();
// }


/* public*/

// class Circle{
//     public:
//         int radius;
//         float area(){
//             return 3.14*radius*radius;
//         }
// };

// int main(){
//     Circle c;
//     c.radius = 2;
//     cout<<"Radius is "<<c.radius<<endl;
//     float areaC =c.area();
//     cout<<"Area "<<areaC;
// }

/* protected*/

class Circle1{
    protected: 
            int radius;
};

class Circle2: public Circle1{
    public:
        void getrad(int r){
            radius=r;
        }
        void areaC(){
            cout<<"Area "<<3.14*radius*radius;
        }


};

int main(){
    Circle2 c;
    c.getrad(5);
    c.areaC();
}