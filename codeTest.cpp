#include<iostream>
class temp
{
    private:
        int x;
    public:
        temp(int xp): x{xp}{
            std::cout<<"constructor"<<std::endl;
        };
    void printValue() const;
};

void temp::printValue() const
{
    std::cout<<"PrintValue = "<<this->x<<std::endl;
    //this->x = 20;  //Error
    (const_cast<temp*>(this))->x = 20;
     std::cout<<"PrintValue = "<<this->x<<std::endl;   
}
int main()
{
    temp t1(5);
    t1.printValue();
    return 0;
}