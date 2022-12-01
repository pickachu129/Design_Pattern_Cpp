#include <iostream>


/**
 * @brief 
 * Implementor
 */
class Implementor{
public:
    virtual ~Implementor(){};
    virtual void action()=0;
};

/**
 * @brief 
 * ConcreteImplementorA
 */
class ConcreteImplementorA:public Implementor{
public:
    virtual ~ConcreteImplementorA(){};
    void action(){
        std::cout<<"Concrete ImplementorA"<<std::endl;
    }
};

/**
 * @brief 
 * ConcreteImplementorB
 */
class ConcreteImplementorB:public Implementor{
public:
    virtual ~ConcreteImplementorB(){};
    void action(){
        std::cout<<"Concrete ImplementorB"<<std::endl;
    }
};


/**
 * @brief 
 * Abstract Actions
 */
class AbstractAction{
public:
    virtual ~AbstractAction(){};
    virtual void operation()=0;
};

class RefindedAction:public AbstractAction{
public:
    RefindedAction(Implementor* impl):implementor(impl){};
    virtual ~RefindedAction(){};
    void operation(){
        this->implementor->action();
    }
private:
    Implementor* implementor;
};
