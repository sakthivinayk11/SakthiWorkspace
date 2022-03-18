// CPP Program to demonstrate derived class redefines base
// class member method and generates compiler error
#include <iostream>
using namespace std;

class Base {
public:
	void fun() { cout << "Base::fun() called"; }
	void fun(int i) 
    { 
        cout << "Base::fun(int i) called"; 
    }
};

class Derived : public Base {
public:
    // Both fun() and fun()
	void fun(char ch) 
    { cout << "Derived::fun() called"; }

    using Base::fun;
};

// Driver Code
int main()
{
	Derived d;
	d.fun('A');
    //d.fun();// **Compile Error **//

    //* After using keyword Line No 21 *//
    d.fun();
    d.fun(5);
	return 0;
}
