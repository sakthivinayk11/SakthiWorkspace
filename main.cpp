#include <iostream>
#include <vector>
#include <string>

using namespace std;

void fun(void){
    cout<<"Function Pointer"<<endl;
}
int main()
{
    vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};

    for (const string& word : msg)
    {
        cout << word << " ";
    }

    using FunPtr = void(*)(void);
    FunPtr FunPtradd = &fun;
    FunPtradd();
    cout << endl;
}