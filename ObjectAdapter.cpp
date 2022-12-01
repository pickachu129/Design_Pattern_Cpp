#include <iostream>


/**
 * @brief 
 * Traget
 */
class Target{
public:
    virtual ~Target(){};
    virtual void request()=0;
};

/**
 * @brief 
 * Adaptee
 */
class Adaptee{
public:
    virtual ~Adaptee(){};
    virtual void specificRequest(){
        std::cout<<"Objetc specificRequest"<<std::endl;
    }
};

/**
 * @brief 
 * Adapter
 */
class ObjectAdapter: public Target{
public:
    ObjectAdapter(){
        this->adaptee = new Adaptee();
    }
    virtual ~ObjectAdapter(){
        delete adaptee;
    };
    virtual void request(){
        adaptee->specificRequest();
    }
private:
    Adaptee* adaptee;
};