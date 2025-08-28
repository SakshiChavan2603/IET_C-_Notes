#include<iostream>
using namespace std;
int main(){
    for(int i=0;i<5;i++){
        for(int j=0;j<i;j++){
            cout<<"*";
        }
        cout<<endl;
    }
    cout<<endl;
    for(int i=1;i<=5;i++){
        for(int j=0;j<i;j++){
            cout<<i;
        }
        cout<<endl;
    }
    cout<<endl;
    for(int i=0;i<5;i++){
        for(int j=1;j<=i;j++){
            cout<<j;
        }
        cout<<endl;
    }
cout<<endl;
    int c = 65;
    for(int i=0;i<5;i++){
        for(int j=0;j<i;j++){
            cout<<char(c);
            c++;
        }
        cout<<endl;
    }
    cout<<endl;

    int c1 = 65;
    for(int i=0;i<5;i++){
        for(int j=0;j<=i;j++){
            cout<<char(c1);
        }
        c1++;
        cout<<endl;
    }
    cout<<endl;

    
    for(int i=0;i<5;i++){
        int c2 = 65;
        for(int j=0;j<=i;j++){
            cout<<char(c2);
            c2++;
        }   
        cout<<endl;
    }

    cout<<endl;
    int rows = 5;
    for(int i=0;i<rows;i++){
        for(int j=0;j<rows-i-1;j++){
            cout<<" ";
        }  
        for(int j=0;j<=i;j++){
            cout<<"*";
        } 
        cout<<endl;
    }

    cout<<endl;
    int rows1 = 5;
    for(int i=1;i<rows1;i++){
        for(int j=0;j<rows1-i-1;j++){
            cout<<" ";
        }  
        for(int j=1;j<=i;j++){
            cout<<i;
        } 
        cout<<endl;
    }

    cout<<endl;
    int rows2 = 5;
    for(int i=1;i<rows2;i++){
        for(int j=0;j<rows2-i-1;j++){
            cout<<" ";
        }  
        for(int j=1;j<=i;j++){
            cout<<j;
        } 
        cout<<endl;
    }

    cout<<endl;

    int num = 5;
    for(int i=1;i<=num;i++){
        for(int j=0;j<=num-i;j++){
            cout<<" ";
        }  
        for(int j=1;j<=i;j++){
            cout<<j;
            
        } 
        for(int j=i-1;j>=1;j--){
            cout<<j;
        } 
        cout<<endl;
    }

    cout<<endl;
     int num1 = 5;
    for(int i=1;i<=num1;i++){
        for(int j=0;j<=num1-i;j++){
            cout<<" ";
        }  
        int k = i;
        for(int j=1;j<=i;j++){
            cout<<k;
            k++;
            
        } 
        int l = k-2;
        for(int j=i-1;j>=1;j--){
            cout<<l;
            l--;
            
        } 
        cout<<endl;
    }


}