#include "iostream"

class CreateClass{
    private:
    int *a;
    public:
    CreateClass()= default;
    CreateClass(int var){
        std::cout<<"Param Constructor"<<std::endl;
        this->a = new int {var};
    }
    CreateClass(const CreateClass &obj){
        std::cout<<"Copy Constructor"<<std::endl;
        this->a = new int{*obj.a};
    }
    CreateClass(CreateClass &&refObj){
        std::cout<<"Move Constructor"<<std::endl;
        this->a = refObj.a;
        refObj.a = nullptr;
    }
    ~CreateClass(){
        delete a;
    }
    void checkPointer(){
        if(this->a == nullptr)std::cout<<"Null Pointer"<<std::endl;
        else std::cout<<"Valid Pointer"<<std::endl;}
};

template<class tType>
void printFun(tType obj){

}
int main(){
    std::cout<<"STD::MOVE sematics"<<std::endl;
    CreateClass objForClass{10};
    CreateClass obj2{static_cast<CreateClass &&>(objForClass)};
    CreateClass obj3{obj2};

    CreateClass obj4{std::move(obj3)};

    printFun(obj4);
    printFun(std::move(obj4));
    objForClass.checkPointer();
    obj2.checkPointer();
    obj3.checkPointer();
    obj4.checkPointer();

    int var1{23};
    int var2{std::move(var1)};

    std::cout<<"var 1 "<<var1<<",Var 2 "<<var2<<std::endl;
    return 0;
}