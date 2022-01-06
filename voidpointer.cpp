#include "iostream"

typedef struct{
    uint32_t variable1;
    uint32_t variable2;
    double doubType;
    bool boolType;
}_StructType;
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
    std::cout<<" pointerToTheIntegerValue ="<<(uint32_t *)voidPtr<<std::endl;

   // _StructType structVar = {10,12,14.89,true};
    return 0;
}