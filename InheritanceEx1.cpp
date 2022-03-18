#include "iostream"

class Base{
    private:
    uint32_t variable;
    uint32_t GetCounterValue;
    protected:
    void checkFun(){
        std::cout<<"ChechFun"<<std::endl;
    }
    public:
    static void nonVirtualFun(){
        std::cout<<"Base Class"<<std::endl;
    }
    virtual void VirtualFun(){
        std::cout<<"Base Virtual Fun"<<std::endl;
    }
};

class Derived:public Base{
    private:
    uint32_t derivedVar;
    public:
    void nonVirtualFun(){
        std::cout<<"Derived Class"<<std::endl;
    }
    using Base::checkFun;
    virtual void VirtualFun(){
        std::cout<<"Derived Virtual Fun"<<std::endl;
    }
};
int main(){
    std::cout<<"Buff"<<std::endl;
    std::cout<<"\nChecking BaseClass"<<std::endl;
    Derived D1;
    D1.nonVirtualFun();
    D1.checkFun();//It can be achieved by Keyword "using Base::checkFun" which makes the protected function as public
    D1.VirtualFun();


    std::cout<<"\nChecking DerivedClass"<<std::endl;
    Base B1;
    B1.nonVirtualFun();
    B1.VirtualFun();
    //B1.checkFun(); Since the Fun is protected it cant be accessed from Outside class


    std::cout<<"\nChecking BaseClassPtr"<<std::endl;
    Base *ptr;
    Derived D3;
    ptr = static_cast<Base *>(&D3);
    ptr->VirtualFun();

    std::cout<<"\nChecking StaticBaseClass"<<std::endl;
    static Base staticBase;
    staticBase.nonVirtualFun();
    staticBase.VirtualFun();

    std::cout<<"\nChecking StaticDerivedClass"<<std::endl;
    static Derived staticDerived;
    staticDerived.nonVirtualFun();
    staticDerived.checkFun();//It can be achieved by Keyword "using Base::checkFun" which makes the protected function as public
    staticDerived.VirtualFun(); 


    std::cout<<"\nChecking StaticClassptr"<<std::endl;
    static Base *newptr;
    Derived D4;
    newptr = &D4;
    newptr->VirtualFun();
}