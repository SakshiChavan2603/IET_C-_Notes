#include<iostream>
using namespace std;
 int maxindex(int a[], int n) {
    int max = a[0];
    int maxind = 0;
    for(int i = 1; i < n;i++) {
        if(max<a[i]) {
            max = a[i];
            maxind = i;
        }
    }
    return maxind;
 }                  
 
 int main() {
    int n;
    cout<<"Enter the size of array = "<<endl;
    cin>>n;
    int a[n];
    cout<<"Accept the elements of an array : "<<endl;
    for(int i = 0; i < n;i++) {
        cin>>a[i];
    }
     cout<<"Display the elements of an array : "<<endl;
    for(int i = 0; i < n;i++) {
        cout<<a[i]<<"\t";
    }
    cout<<endl;

    int maxind = maxindex(a, n);
    cout<<maxind<<endl;
    int max = a[maxind];
    cout<<max<<endl;
    for(int i = 0; i < n; i++) {
        if(max == a[i]) {
            a[i] = -1;
        }
    }
    for(int i = 0; i < n;i++) {
        cout<<a[i]<<"\t";
    }
    int secmax = maxindex(a, n);
    cout<<"Second largest element is = "<<a[secmax];
}