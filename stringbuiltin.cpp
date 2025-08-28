#include<iostream>
#include<string.h>
using namespace std;

int main () {
    char str[50];
    cout<<"Enter the string : "<<endl;
    cin>>str;
    int len = strlen(str);
    cout<<"Length of "<<str<<" is "<<len<<endl;
    char str_cpy[50];
    cout<<"Enter another string : "<<endl;
    cin>>str_cpy;
    // strcpy(str, str_cpy); // Copy one string into another
    // cout<<str;

    // strcat(str, str_cpy); // Concatination of two strings
    // cout<<str;

    cout<<strrev(str); // String reverse

    
}