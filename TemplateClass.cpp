#include <iostream>
#include <vector>
using namespace std;

template<class temp>
class TemplateClass
{
private:
    int var{20};
    temp A;
    int k{var};
public:
    TemplateClass(temp);
    TemplateClass(temp y,int _val):A(y),var(_val){
        cout<<"constructor "<<A<<" "<<TemplateClass::var<<endl;
    }
    void updateFun(temp val);
    template<typename classTemFun>
    void templateClassFun(classTemFun var);
};
template<class newTemp>
TemplateClass<newTemp>::TemplateClass(newTemp temp){
    A = temp;
    cout<<"Singgle Param "<<var<<" "<<A<<" "<<k<<endl;
}
template<class temp2>
void TemplateClass<temp2>::updateFun(temp2 val){
    A += val;
    cout<<"Update Fun "<<A<<" "<<TemplateClass::var<<endl;
}

template<class temp2>
template<typename classTemFun>
void TemplateClass<temp2>::templateClassFun(classTemFun name){
    A += name;
    cout<<"templateClassFun Fun "<<A<<" "<<TemplateClass::var<<endl;
}
int main(){
    cout<<"Buff"<<endl;
    TemplateClass<float> A{10,4};   
    TemplateClass<int> B{30,40};
    TemplateClass<double> C{43.1};
    A.updateFun(12.32);
    B.updateFun(11.25);
    B.templateClassFun<float>(13.2);
    return 0;
}