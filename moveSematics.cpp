#include <iostream>

class MoveSematics{
    private:
    int *value;
    public:
    MoveSematics(){
        std::cout<<"Constructor"<<std::endl;
        value = new int(0);
    }
    MoveSematics(int32_t _storeData){
       std::cout<<"MoveSematics int obj"<<std::endl;
        value = new int(_storeData);

    }
    MoveSematics(const MoveSematics & obj){
       std::cout<<"MoveSematics const MoveSematics &obj"<<std::endl;
        value = new int(*obj.value);
    }
    MoveSematics(MoveSematics &&obj)
    {
       std::cout<<"MoveSematics &&obj"<<std::endl;
        value = obj.value;
        obj.value = nullptr;
    }
    ~MoveSematics(){
        std::cout<<"Destructor"<<std::endl;
        delete value;
    }
    int32_t getValue()const;
    void setValue(int );
};

int32_t MoveSematics::getValue()const
{
    return *value;
}

void MoveSematics::setValue(int setValue){
    *value = setValue;
}

MoveSematics AddToValue(const MoveSematics &aValue,const MoveSematics &bValue)
{
    static MoveSematics buff;
    buff.setValue(aValue.getValue() + bValue.getValue());
    return buff;
}

int main(){
    MoveSematics obj1{1},obj2{2};
    obj1.setValue((AddToValue(obj1,obj2)).getValue());
    std::cout<<"Move Sematics "<<obj1.getValue()<<std::endl;
}