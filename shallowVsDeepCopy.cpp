#include<iostream>
using namespace std;

int main(){
    int *ptr = new int{5};
    int *ptr2 = ptr;
    int *ptr3 = new int{*ptr};
    cout<<"BUFF "<<*ptr<<" "<<*ptr2<<" "<<*ptr3<<endl;
    *ptr = 11;
    cout<<"BUFF "<<*ptr<<" "<<*ptr2<<" "<<*ptr3<<endl;
    return 0;
}