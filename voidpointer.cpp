#include "iostream"

typedef struct{
    uint32_t variable1;
    uint32_t variable2;
    double doubType;
    bool boolType;
}_StructType;


void funMethod(){
    std::cout<<" Calling the FunMethod "<<std::endl;
}
int main()
{
    std::cout<<"VoidPointer"<<std::endl;
    uint32_t integerValue = 10;
    void *voidPtr = &integerValue;
    std::cout<<" pointerToTheIntegerAddres ="<<*(uint32_t *)voidPtr<<std::endl;

    voidPtr = (uint32_t *)5;
    std::cout<<" pointerToTheIntegerValue ="<<(uint32_t *)voidPtr<<std::endl;

    double floatValue = 14.3;    
    voidPtr = &floatValue;
    std::cout<<" pointerToTheFloatAddress ="<<*(double *)voidPtr<<std::endl;
    
    //voidPtr = (double *)32.3;
    voidPtr = (uint32_t *)'0';
    std::cout<<" pointerToTheCharValue ="<<(uint32_t *)voidPtr<<std::endl;

    uint8_t charVar = 'A';
    voidPtr = &charVar;
    std::cout<<" pointerToTheCharAddress ="<<*(uint8_t *)voidPtr<<std::endl;

    _StructType structVar = {88,456,14.89,true};
    voidPtr = &structVar;
    (*(_StructType *)voidPtr).doubType = 48.23;
    std::cout<<" pointerToTheSTructer : "<<(*(_StructType *)voidPtr).variable1<<
                " Variable 2 : "<<(*(_StructType *)voidPtr).variable2<<
                " FloatVal : "<<(*(_StructType *)voidPtr).doubType<<
                " BoolType : "<<(*(_StructType *)voidPtr).boolType<<std::endl;

    void (*ptrFun)(void) = &funMethod;
    ptrFun();
    return 0;
}