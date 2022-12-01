#include <iostream>

class AbstractClass{
public:
    virtual ~AbstractClass(){};
    void templateMethod(){
        primitiveOperation1();
        primitiveOperation2();
    }

    virtual void primitiveOperation1()=0;
    virtual void primitiveOperation2()=0;

};

class ConcreteClass : public AbstractClass{
public:
    ~ConcreteClass(){};

    virtual void primitiveOperation1(){
        std::cout<<"primitiveOperation1"<<std::endl;
    }
    virtual void primitiveOperation2(){
        std::cout<<"primitiveOperation2"<<std::endl;
    }
private:
};