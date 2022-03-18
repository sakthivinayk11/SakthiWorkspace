#include "iostream"

class Class1{
    private:
    uint32_t variable;
    uint32_t GetCounterValue;
    protected:
    void checkFun(){
        std::cout<<"ChechFun"<<std::endl;
    }
    public:
    static void nonVirtualFun(){
        std::cout<<"Class1 Class"<<std::endl;
    }
    virtual void VirtualFun(){
        std::cout<<"Class1 Virtual Fun"<<std::endl;
    }
};

class Class2{
    private:
    uint32_t Class2Var;
    public:
    void nonVirtualFun(){
        std::cout<<"Class2 Class"<<std::endl;
    }
    virtual void VirtualFun(){
        std::cout<<"Class2 Virtual Fun"<<std::endl;
    }
};
int main(){
    std::cout<<"Buff"<<std::endl;
    Class2 D1;
    D1.nonVirtualFun();
    D1.VirtualFun();

    Class1 *ptr = (Class1 *)(&D1);
    //Class1 *ptr1 = static_cast<Class1 *>(&D1); Will report error due to Type conversion from class2* to class1*
    ptr->VirtualFun();
    ptr->nonVirtualFun();
}

