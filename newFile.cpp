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
    void callUsingMain(void);
    void callUsingInside(void);

    using FuncPtrInsideClass = void(Temp::*)();
    FuncPtrInsideClass holdAddressInsideClass = &Temp::callUsingInside;
};

void Temp::printfunc(void){
    std::cout<<"PrintFun"<<endl;
    (this->*holdAddressInsideClass)();
}

void Temp::callUsingMain(void){
    std::cout<<"callUsingMain"<<endl;
}

void Temp::callUsingInside(){
    std::cout<<"callUsingInside"<<endl;
}
void normalFun(void){
    cout<<"Function Pointer"<<endl;
}
int main()
{
    using ptrToFun = void(*)(void);
    ptrToFun FunPtradd = &normalFun;
    FunPtradd();

    Temp objForTemp(20);
    Temp *ptr = &objForTemp;
    using ptrToClassFun = void(Temp::*)();
    ptrToClassFun funPtrHoldAdd = &Temp::callUsingMain;
    ptr->printfunc();
    (objForTemp.*funPtrHoldAdd)();
    (ptr->*funPtrHoldAdd)();

    //Called From Oustside Fun
    (objForTemp.*objForTemp.holdAddressInsideClass)();
    (ptr->*ptr->holdAddressInsideClass)();
}