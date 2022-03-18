#include <iostream>

class exConst{
    private:
    int a{0};
    int b{0};
    int var{30}; 
    public:
    exConst(int aTemp,int bTemp):a{aTemp},b{bTemp}{

    }
    exConst() = default;
    void updateFun(int _a,int _b);
    void printFun() const;
};

void exConst::updateFun(int _a,int _b) 
{
    this->a = _a;
    this->b = _b;
}
void exConst::printFun(void) const
{
    this->var;
   std::cout<<"Update Fun "<<this->a<<" "<<this->b<<" "<<this->var<<std::endl;
}
int main()
{
    std::cout<<"Buff"<<std::endl;
    exConst exc;
    exc.updateFun(10,20);
    exc.printFun();
    const exConst exc2{12,23};
    exc2.printFun();
    return 0;
}