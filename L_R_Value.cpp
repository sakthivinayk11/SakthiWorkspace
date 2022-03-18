#include <iostream>

void print(int &temp)
{
    std::cout<<"int & "<<temp<<std::endl;
}
void print(const int &temp)
{
    std::cout<<"Const Int & "<<temp<<std::endl;
}
void print(int &&temp)
{
    std::cout<<"Int && "<<temp<<std::endl;
}

int main(){
    int temp = 10;
    int &refTemp = temp;
    std::cout<<"Value "<<refTemp<<" "<<temp<<std::endl;
    temp++; //or refTemp++;

    int *ptr = &temp;
    //int &refTemp2 = 10; error
    std::cout<<"Value "<<refTemp<<" "<<temp<<std::endl;
    //int &&refRValue = temp; error
    int &&refRValue = 23;
    std::cout<<"R Value "<<refRValue<<std::endl;
    const int &refTemp2 = 3;
    std::cout<<"printValue "<<refTemp2<<std::endl;

   // char stringVar[] = "STring";
    print(5);
    print(temp);
    const int j = 32;
    print(j);
}