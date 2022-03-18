
class Integer{
    private:
    int *ptr;
    public:
    Integer(){
        std::cout<<"Integer()"<<std::endl;
    }
    Integer(int var){
        std::cout<<"Integer(int)"<<std::endl;
        ptr = new int{var};
    }
    Integer(const Integer &obj){
        std::cout<<"Integer(const Integer &)"<<std::endl;
        ptr = new int(*obj.ptr);
    }
    Integer(Integer &&obj){
        std::cout<<"Integer(Integer &&)"<<std::endl;
        ptr = obj.ptr;
        obj.ptr = nullptr;
    }
    ~Integer(){
        std::cout<<"Destructor()"<<std::endl;
    }

    Integer & operator=(const Integer &obj){
        std::cout<<"Integer=(const Integer &)"<<std::endl;
        if(this == &obj)
            return *this;
        delete ptr;
        ptr = new int (*obj.ptr);
        return *this;
    }
    Integer & operator=(Integer &&obj){
        std::cout<<"Integer=(Integer &&)"<<std::endl;
        if(this == &obj)
            return *this;
        delete ptr;
        ptr = obj.ptr;
        obj.ptr = nullptr;
        return *this;
    }
    int getValue()const{
        return *this->ptr;
    }
    void setValue(int value){
        *this->ptr = value;
    }
};
