#include <iostream>

int* refFun(){
    static int var = 11;
    return &var;
}

int passRef(int var){
    var *= 2;
    return var;
}
int main(){
    int *NewVar = refFun();
    std::cout<<"IoST "<<*NewVar<<" "<<passRef(*NewVar)<<std::endl;
}