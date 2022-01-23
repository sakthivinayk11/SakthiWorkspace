#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Temp{
    private:
    int a;
   public:
   Temp() = default;
    Temp(int aa):a{aa}{
        cout<<"ParamConst "<<this->a<<endl;
    }
    void printfunc(void);
    void callUsingMain(void);
    void callUsingInside(void);

    void crosscheckFun(){
        std::cout<<"CrossCheckFun"<<std::endl;
    }
    using FuncPtrInsideClass = void(Temp::*)();
    FuncPtrInsideClass holdAddressInsideClass = &Temp::callUsingInside;
};

void Temp::printfunc(void){
    std::cout<<"PrintFun"<<endl;
    (this->*holdAddressInsideClass)();
    this->crosscheckFun();
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
    //Using Namespace reference for function pointer
    using ptrToFun = void(*)(void);
    ptrToFun FunPtradd = &normalFun;
    (*FunPtradd)();

    //Using Function Pointer
    void (*ptrFunDumm)(void) = &normalFun;
    (*ptrFunDumm)();

    //Create an object and pointer for class Temp
    Temp objForTemp(20);
    Temp *ptr = &objForTemp;
    //Refer the class function to Function pointer
    using ptrToClassFun = void(Temp::*)();
    ptrToClassFun funPtrHoldAdd = &Temp::callUsingMain;
    ptr->printfunc();
    //Calling the function pointer with obj and pointer
    (objForTemp.*funPtrHoldAdd)();
    (ptr->*funPtrHoldAdd)();

    //Create a second obj
    Temp objForTemp2(43);
    Temp *ptr2 = new Temp;
    ptr2 = &objForTemp2;
    //Called From Oustside Fun
    (objForTemp2.*(objForTemp2.holdAddressInsideClass))();
    (ptr2->*ptr2->holdAddressInsideClass)();

    (objForTemp2.*funPtrHoldAdd)();
    (ptr->*funPtrHoldAdd)();
}