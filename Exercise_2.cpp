#include "iostream"
using namespace std;

class staticClass{
    private:
    uint32_t localVariable{0};
    static uint32_t staticVariable;
    static uint32_t constructorVar;
    public:
    ~staticClass(){
        constructorVar++;
        std::cout<<"ConstructorCalled "<<constructorVar<<std::endl;
    }
    static void GoToStaticFunction(void);
    void gotToNonStaticMethod(void);
    static staticClass& GetInstancePointer(void);
};


// staticClass staticClass::ptrForInstance;
uint32_t staticClass::constructorVar;

staticClass& staticClass::GetInstancePointer(){
    static staticClass ptrForInstance;
    return ptrForInstance;
}
uint32_t staticClass::staticVariable{0};
void staticClass::gotToNonStaticMethod(void){
    this->localVariable++;
    //this->staticVariable++;
    std::cout<<"In Non Static Method local "<<this->localVariable<<" static "<<this->staticVariable<<std::endl;

}
void staticClass::GoToStaticFunction(void){
    staticVariable++;
    std::cout<<"In Static Method "<<staticVariable<<std::endl;
    staticClass::GetInstancePointer().gotToNonStaticMethod();
}
int main(){
    cout<<"Exercise"<<std::endl;
    uint32_t i = 5;

    while ( i--)
    {   
        staticClass::GetInstancePointer().GoToStaticFunction();
        staticClass::GetInstancePointer().gotToNonStaticMethod();
    }
    return 0;
}