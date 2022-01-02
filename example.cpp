#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Temp{
    private:
    int a;
    public:
    Temp(int aa):a{aa}{
        cout<<"ParamConst "<<this->a<<endl;
    }
    void printfunc(void);
    void callUsingPrint(void);
    using FunPtr = void(Temp::*)();
    FunPtr newFun = &Temp::callUsingPrint;
};

void Temp::printfunc(void){
    std::cout<<"PrintFun"<<endl;
}

void Temp::callUsingPrint(void){
    std::cout<<"callUsingPrint"<<endl;
}

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
    cout << endl;

    using FunPtr = void(*)(void);
    FunPtr FunPtradd = &fun;
    FunPtradd();

    Temp objForTemp(20);
    Temp *ptr = &objForTemp;
    ptr->printfunc();
    //(ptr->*newFun)();
   // (objForTemp.Temp::newFun)();
}