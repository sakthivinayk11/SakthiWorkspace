#include "iostream"
using namespace std;

class staticClass{
    private:
    static staticClass *ptrForInstance;
    uint32_t localVariable{0};
    static uint32_t staticVariable;
    public:
    static void GoToStaticFunction(void);
    void gotToNonStaticMethod(void);
    static staticClass* GetInstancePointer(void);
};


staticClass * staticClass::ptrForInstance;


staticClass* staticClass::GetInstancePointer(){
    
    if(ptrForInstance == nullptr)
        ptrForInstance = new staticClass;
    return ptrForInstance;
}
uint32_t staticClass::staticVariable{0};
void staticClass::gotToNonStaticMethod(void){
    this->localVariable++;
    this->staticVariable++;
    std::cout<<"In Non Static Method "<<this->localVariable<<" "<<this->staticVariable<<std::endl;

}
void staticClass::GoToStaticFunction(void){
    staticVariable++;
    std::cout<<"In Static Method "<<staticVariable<<std::endl;
    staticClass::GetInstancePointer()->gotToNonStaticMethod();
}
int main(){
    cout<<"Exercise"<<std::endl;
    staticClass::GetInstancePointer()->GoToStaticFunction();
    staticClass::GetInstancePointer()->gotToNonStaticMethod();

    staticClass *anotherObject = staticClass::GetInstancePointer();
    anotherObject->GoToStaticFunction();
    anotherObject->gotToNonStaticMethod();
    return 0;
}