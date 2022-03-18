#include "iostream"

void updateFun(const int &ref){
    std::cout<<"InsRef"<<std::endl;
}
int main(){
    std::cout<<"Constant Var"<<std::endl;
    int var1 = 10;
    const int *ptr = &var1;
    // (*ptr)++; Error we cant access the 

    const int var2 = 32; 
    const int *const ptr1 = &var2;

    const int &refVal = var2;

    //refVal++; //Cant Modify Ref VAlue

    auto autoPtr = &var1;
    std::cout<<"Pointer Var "<<*autoPtr<<std::endl;
    updateFun(refVal);
    
}