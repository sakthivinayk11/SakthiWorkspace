#include "iostream"
class Base{
    private:
    static uint32_t BaseConst;
    int a;
    public:
    virtual void run(void) = 0;
    void withoutVirtual(void){
        std::cout<<"WithoutVirtual_BaseClass"<<std::endl;
    }
    void baseMethod(int _a){
        this->a = _a;
        std::cout<<"Value is "<<this->a<<std::endl;
    }
    Base(){
        std::cout<<"Base COnstructor"<<std::endl;
    }
    ~Base(){
        ++BaseConst;
        std::cout<<"BaseDestructot "<<BaseConst<<std::endl;
    }
};
uint32_t Base::BaseConst;
class Derived:public Base{
    static uint32_t DrvConst;
    public:
    void withoutVirtual(void){
        std::cout<<"WithoutVirtual_DerivedClass"<<std::endl;
    }
    //private: //Even it is private its work fine
    void run(void){
        std::cout<<"Derived_Run"<<std::endl;
    }


    Derived(){

        std::cout<<"Derived COnstructor"<<std::endl;
    }
    ~Derived(){
        ++DrvConst;
        std::cout<<"Derived Destructor "<<DrvConst<<std::endl;
    }

     void derivedMethod(){
        std::cout<<"Derivedethod "<<std::endl;

        Base::baseMethod(56);
    }
};

uint32_t Derived::DrvConst;
int main(){

    Base *objBase; 
    Derived objDerived;
    objBase = &objDerived;

    objBase->run();
    objBase->withoutVirtual();
    objBase->baseMethod(15);

    std::cout<<std::endl;
    Base *ptr = new Derived;
    ptr->run();
    ptr->withoutVirtual();
    ptr->baseMethod(23);


    std::cout<<std::endl;
    Derived *ptr2 = new Derived;
    ptr2->run();
    ptr2->withoutVirtual();
    ptr2->baseMethod(35);
    ptr2->derivedMethod();
    std::cout<<std::endl;


   //git Derived NormalObj;
    objDerived.run();
    objDerived.withoutVirtual();
    objDerived.baseMethod(46);

    std::cout<<std::endl;

     //Base BaseObj; 
     //Base *BasePtr = &BaseObj;

    return 0;
}