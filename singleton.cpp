#include <iostream>
template<class DerivedType>
struct Singleton{
    static DerivedType ptr;
    public:
    // static DerivedType* instance(void){
    //     static DerivedType *ptr;
    //     if(ptr == nullptr)
    //         ptr = new DerivedType;
    //     return ptr;
    // }
    static DerivedType instance(void){
        return ptr;
    }
    ~Singleton(){
        std::cout<<"Destructor"<<std::endl;
    }
};

template<class DerivedType>
DerivedType Singleton<DerivedType>::ptr;

class Derived:public Singleton<Derived>{
    uint32_t Var{0};
    static uint32_t var2;
    public:
    ~Derived(){
        std::cout<<"Derived Dest"<<std::endl;
    }
     void printFun(){
        std::cout<<"printFun "<<Var<<" & "<<var2<<std::endl;
    }
    void NotderivedFromBase(){
        ++Var;
        ++var2;
        //std::cout<<"NotFromBase "<<Var<<" & "<<var2<<std::endl;
    }
};

uint32_t Derived::var2;
int main(){
    uint32_t var = 5;
    while (var--)
    {    
        // Singleton<Derived>::instance().printFun();
        // Singleton<Derived>::instance().NotderivedFromBase();
        Derived::instance().NotderivedFromBase();
        Derived::instance().printFun();
    }
    return 0;
}