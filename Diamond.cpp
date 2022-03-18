#include<iostream>
using namespace std;

class A
{
static int x;
public:
A()=default;
A(int i) { x = i; }
void print() { cout << x; }
};
int A::x;
class B: virtual public A
{
public:
B():A(10) { }
};

class C: virtual public A
{
public:
C():A(10) { }
};

class D: public B, public C {
    public:
    D():A(20){}
};

int main()
{
	D d;
	d.print();
	return 0;
}
