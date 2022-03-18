#include <iostream>

int main(){
    int var1 = 65;
    float var2 = static_cast<float>(var1)/5;
    std::cout<<"Output "<<var2<<std::endl;

    uint8_t *ptr = (uint8_t *)&var1;
    uint32_t storeValue = *ptr;
    std::cout<<"char Pointer "<<storeValue<<std::endl;

    //uint8_t *ptr2 = static_cast<uint8_t *>(&var1); static_cast will chack for validation
    uint8_t *ptr2 = reinterpret_cast<uint8_t *>(&var1);
    std::cout<<"ReinterpratedCast "<<*ptr2<<ptr2    <<std::endl;

    const int x = 10;
    int *ptrForConst = const_cast<int *>(&x);


    int i = 10;
    void *vp = static_cast<void *>(&i);
    int *ip = static_cast<int *>(vp);
    std::cout<<"The Value = "<<*ip<<std::endl;
    return 0;
}