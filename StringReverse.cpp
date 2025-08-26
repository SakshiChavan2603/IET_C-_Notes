#include<iostream>
#include<cstring>
using namespace std;
//  int main() {
//     char a[50];
//     cout<<"Enter the string: "<<endl;
//     cin.getline(a,50);
//     int len = strlen(a);
//     //cout<<len;
//     char b[len];
//     int j=0;
//     for(int i = len-1; i >= 0; i--) {
//         b[j] = a[i];
//         //cout<<j<<"\t"<<b[j]<<endl;
//         j++;
//     }
//     b[j]='\0';
//     cout<<b;
//  }

//***********************************************/


// void revstring(char* str)
// {
//     char* start = str;
//     char* end = str+ strlen(str)-1;

//     while(start<end)
//     {
//         char temp = *start;
//         * start =* end;
//         *end=temp;

//         start++;
//         end--;
//     }
// }

// int main()
// {
//     char a[50];
//     cout<<"Enter the string = ";
//     cin.getline(a,50);
//     revstring(a);
//     cout<<"Reverse string is = "<<a;
// }

//*************************************************************/

void reverse_string(char str1[],int len){
    int start =0,end=len-1;
    while(start<end){
        char temp = str1[start];
        str1[start] = str1[end];
        str1[end]= temp;
        start++;
        end--;
    }
    cout<<str1<<endl;;
}
int main(){
    char str[40];
    cout<<"Enetr the string\n";
    cin>>str;
    int len = strlen(str);
    //cout<<len<<endl;
    reverse_string(str,len);
    cout<<str<<endl;
}

//************************************************************** */

// #include <iostream>
// using namespace std;

// void reverseCharArray(char arr[], int n) {
//     int start = 0, end = n - 1;
//     while (start < end) {
//         // Swap characters
//         swap(arr[start], arr[end]);
//         start++;
//         end--;
//     }
// }

// int main() {
//     char str[] = "HelloWorld";
//     int n = sizeof(str) / sizeof(str[0]) - 1; // Exclude null terminator
//     reverseCharArray(str, n);
//     cout << "Reversed String: " << str << endl;
//     return 0;
// }

//*************************************************************** */

// int main(){
//     char a[50];
//     cout<<"Enter the string: "<<endl;
//     cin>>a;
//     int len = strlen(a);
//     //cout<<len;
//     char b[len];
//     int j=0;
//     while(a[j]!='\0'){
//         b[j]=a[len-1-j];
//         j++;
//     }
//     cout<<b;
// }