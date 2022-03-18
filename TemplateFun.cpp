#include <iostream>

template<class tType , class cType>
void fun(tType,cType);

template<typename type,typename returnType>
returnType fun(type var);

int main()
{
    std::cout<<"Buff"<<std::endl;
    std::cout<<fun<int,int>(5)<<std::endl;
    std::cout<<fun<int,float>(12.5)<<std::endl;
    std::cout<<fun<float,int>(14.2)<<std::endl;
    fun<int,char>(14,'a');
    fun<int,int>(14.31,10);
    return 0;
}

template<class tType , class cType>
void fun(tType var1,cType var2)
{
    std::cout<<"PrintFunwithTwoArg "<<var1<<" "<<var2<<std::endl;
}
template<typename type,typename returnType>
returnType fun(type var){
    std::cout<<"printFunCtionwithReturnType "<<var<<std::endl;
    return var;
}