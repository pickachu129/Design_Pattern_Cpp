#include <iostream>


class Element;
class ConcreteElementA;
class ConcreteElementB;

class Visitor{
public:
    virtual ~Visitor(){};
    virtual void visiteElementA(ConcreteElementA* const element)=0;
    virtual void visiteElementB(ConcreteElementB* const element)=0;
};

class Visitor1 : public Visitor{
public:
    ~Visitor1(){};

    void visiteElementA(ConcreteElementA* const element){
        std::cout<<"Visited 1: Element A visited!"<<std::endl;
    }

    void visiteElementB(ConcreteElementB* const element){
        std::cout<<"Visited 1: Element B visited!"<<std::endl;
    }
};

class Visitor2 : public Visitor{
public:
    ~Visitor2(){};

    void visiteElementA(ConcreteElementA* const element){
        std::cout<<"Visited 2: Element A visited!"<<std::endl;
    }

    void visiteElementB(ConcreteElementB* const element){
        std::cout<<"Visited 2: Element B visited!"<<std::endl;
    }
};

class Element{
public:
    virtual ~Element(){};
    virtual void accept(Visitor* visitor)=0;
};

class ConcreteElementA : public Element{
public:
    ~ConcreteElementA(){};

    void accept(Visitor* visitor){
        visitor->visiteElementA(this);
    }
};

class ConcreteElementB : public Element{
public:
    ~ConcreteElementB(){};

    void accept(Visitor* visitor){
        visitor->visiteElementB(this);
    }
};