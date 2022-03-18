#include "iostream"
#include "Integer.hpp"

class Number{

    public:
    Integer objInt{};
    Number(int value):objInt{value}{
        //std::cout<<"Number(int)"<<std::endl;
    }

    //Number(const Number &obj):objInt{obj.objInt}{std::cout<<"Number(const number &)"<<std::endl;}
    //Number(Number &&obj):objInt{std::move(objInt)}{}
    Number(const Number &obj) = default;
    Number & operator = (const Number &obj) = default;
    Number & operator = (Number &&obj) = default;
    Number(Number &&obj) = default;
};

class NumberDerived:public Integer{
    public:
    NumberDerived(int value):Integer{value}{
        std::cout<<"NumberDerived(int)"<<std::endl;
    }
    // NumberDerived(const NumberDerived &obj){
    //     std::cout<<"CopyCOnstructor\n";
    // }
};

template<typename Ttype>
Ttype createNumber(const int numValue){
    std::cout<<"createNumber"<<std::endl; 
    Ttype num_1{numValue};
    return num_1;
}


int main(){
    std::cout<<"**MovSemEx2***"<<std::endl;
    std::cout<<"**Create Num Object**"<<std::endl;
    Number num{3};
    std::cout<<"**Create Num2 Object copy Num2(num)**"<<std::endl;
    Number num2{num};
    std::cout<<"**Assigning num2 = num**"<<std::endl;
    num2 = num;

    std::cout<<"\n**Create num3 objecte and pass the value using move semantics**"<<std::endl;
    Number num3{createNumber<Number>(3)};
    std::cout<<"**Assigning the value using move semantics**"<<std::endl;
    num3 = createNumber<Number>(5);

    std::cout<<"num1_Val = "<<num.objInt.getValue()<<",num2_val = "<<num2.objInt.getValue()<<",num3_val = "<<num3.objInt.getValue()<<std::endl;

    std::cout<<"\nDerivedClass\n"<<std::endl;
    NumberDerived newObj1{10};
    NumberDerived newObj2{newObj1};
    newObj1 = createNumber<NumberDerived>(121);
    std::cout<<"newObj1_Val = "<<newObj1.getValue()<<",newObj2_val = "<<newObj2.getValue()<<std::endl;

}