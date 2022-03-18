#include<iostream>
struct stName{
    uint32_t _var1;
    float _FloatVar2;
    void printVariable(){
        std::cout<<"PrintFun"<<std::endl;
    }
};

using StNameVariable = struct stName;
template<class temp>
void TemplateFun(temp);
template<>
void TemplateFun(int var);   
template<>
void TemplateFun(StNameVariable stObj);
int main(){
    std::cout<<"Temmplate Exercise"<<std::endl;
    TemplateFun<int>(4.5);
    TemplateFun<float>(14);
    TemplateFun<StNameVariable>({12,14.3});
    return 0;
}

template<class temp>
void TemplateFun(temp ch){

    std::cout<<"TheEnteredVAlue = "<<ch<<std::endl;
}

template<>
void TemplateFun(int var)
{
    std::cout<<"SeperateFun FOr Integer = "<<var<<std::endl;
}

template<>
void TemplateFun(StNameVariable stObj){
    std::cout<<"StructureFunction "<<stObj._FloatVar2<<" "<<stObj._var1<<std::endl; 

    stObj.printVariable();
}