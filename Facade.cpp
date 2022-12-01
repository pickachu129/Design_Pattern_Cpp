#include <iostream>

class SubsystemA{
public:
    void suboperation(){
        std::cout<<"Subsystem A method"<<std::endl;
    }
};

class SubsystemB{
public:
    void suboperation(){
        std::cout<<"Subsystem B method"<<std::endl;
    }
};

class SubsystemC{
public:
    void suboperation(){
        std::cout<<"Subsystem C method"<<std::endl;
    }
};

class Facade{
public:
    Facade():subsystemA(),subsystemB(),subsystemC(){};

    void operation1(){
        subsystemA->suboperation();
    }

    void operation2(){
        subsystemB->suboperation();
    }

    void operation3(){
        subsystemC->suboperation();
    }
private:
    SubsystemA* subsystemA;
    SubsystemB* subsystemB;
    SubsystemC* subsystemC;
};