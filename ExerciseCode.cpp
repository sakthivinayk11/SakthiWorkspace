#include<iostream>

template<class SingleTon>
struct SingleTonClass{
    static SingleTon Obj;
    public:
    static SingleTon& instance(){
        return Obj;
    }

    SingleTonClass(){
        std::cout<<"SingletonClass COnstructor"<<std::endl;
    }
    ~SingleTonClass(){
        std::cout<<"SingletonClass Destructor"<<std::endl;
    }
};


template<class SingleTon>
SingleTon SingleTonClass<SingleTon>::Obj;

class StaticClass:public SingleTonClass<StaticClass>{
    private:
    static int varStatic;
    int varLocal;
    int *ptr;
    public:
    void updateVariable();
    StaticClass():varLocal{7},ptr{&varLocal}{
        std::cout<<"Constructor"<<std::endl;
    }
    ~StaticClass(){
        std::cout<<"Destructor"<<std::endl;
    }
    void AddressPrint(){
        std::cout<<"Address "<<&varLocal<<" "<<ptr<<std::endl;
    }
};

int StaticClass::varStatic;

void StaticClass::updateVariable(){
    ++varStatic;
    ++varLocal;
    std::cout<<"StaticVar "<<varStatic<<" LocalVariable "<<varLocal<<" *ptr "<<*ptr<<std::endl;
}
int main(){
    std::cout<<"Debug"<<std::endl;
    for(int i = 0;i<2;i++){
        StaticClass varObj;
        varObj.updateVariable();
        varObj.AddressPrint();
    }
    std::cout<<std::endl;
    for(int i = 0;i<2;i++){
        static StaticClass varObjStatic;
        varObjStatic.updateVariable();
        varObjStatic.AddressPrint();
    }
    std::cout<<std::endl;
    for(int i = 0;i<2;i++){
        StaticClass::instance().updateVariable();
        StaticClass::instance().AddressPrint();
    }


    std::cout<<std::endl;

}
