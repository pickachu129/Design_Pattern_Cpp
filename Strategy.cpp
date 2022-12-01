#include <iostream>

class Strategy{
public:
    virtual ~Strategy(){};
    virtual void algorithmInterface() = 0;
};

class ConcreteStrategyA : public Strategy{
    ~ConcreteStrategyA(){};
    void algorithmInterface(){
        std::cout<<"algorithmA"<<std::endl;
    }
};

class ConcreteStrategyB : public Strategy{
    ~ConcreteStrategyB(){};
    void algorithmInterface(){
        std::cout<<"algorithmB"<<std::endl;
    }
};

class ConcreteStrategyC : public Strategy{
    ~ConcreteStrategyC(){};
    void algorithmInterface(){
        std::cout<<"algorithmC"<<std::endl;
    }
};

class Context{
public:
    Context(Strategy* const s):strategy(s){};
    ~Context(){
        if(strategy){
            delete strategy;
        }
    }

    void action(){
        strategy->algorithmInterface();
    }
private:
    Strategy* strategy;
};