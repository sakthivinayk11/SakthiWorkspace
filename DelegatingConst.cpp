#include <iostream>

using namespace std;
class Temp{
    private:
    int var1;
    int var2;
    int var3;
    public:
    Temp():Temp(0){
        cout<<"Default Const"<<endl;
        //var1 = 7;
        //var2 = 8;
    }
    Temp(int _Bvar):Temp(_Bvar,0){
        cout<<"Single Par Const"<<endl;
        //var2 = 45;
    }
    Temp(int _Bvar1,int _Bvar2){
        cout<<"Double Para Const"<<endl;
        this->var1 = _Bvar1;
        this->var2 = _Bvar2;
        this->var3 = 0;
    }
    void printFun()const;
    void updateFun(int _bufVar){
        var3 = _bufVar;
    }
    void updateFun(float) = delete;
};

void Temp::printFun(void)const{
    cout<<"printFun "<<var1<<" "<<var2<<endl;
}
int main()
{
    Temp obj;
    Temp obj1{20};
    Temp obj2{11,22};
    obj.printFun();
    obj1.printFun();
    obj2.printFun();

    obj.updateFun(12);
    //obj.updateFun(12.3); because of delete
    cout<<"Delegating Constructor"<<endl;
}