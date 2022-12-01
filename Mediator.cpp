#include <iostream>
#include <vector>
#include <string>

class Mediator;

class Colleague{
public:
    Colleague(Mediator* const m,const unsigned int i):mediator(m),id(i){};
    virtual ~Colleague(){};
    unsigned int getID(){
        return this->id;
    }

    virtual void send(std::string) = 0;
    virtual void receive(std::string) = 0;
protected:
    Mediator* mediator;
    unsigned int id;
};

class ConcreteColleage : public Colleague{
public:
    ConcreteColleage(Mediator* const m,const unsigned int i):Colleague(m,i){};
    ~ConcreteColleage(){};

    void send(std::string msg);

    void receive(std::string msg){
        std::cout<<"Message '"<<msg<<"' received by Colleague"<<id<<std::endl;
    }
};

class Mediator{
public:
    virtual ~Mediator(){}
    virtual void add(Colleague* const c) = 0;
    virtual void distribute(Colleague* const sender,std::string msg)=0;
protected:
    Mediator(){};
};

class ConcreteMediator : public Mediator{
public:
    ~ConcreteMediator(){
        for(unsigned int i = 0; i< colleagues.size() ;i++){
            delete colleagues[i];
        }
        colleagues.clear();
    }

    void add(Colleague* const c){
        colleagues.push_back(c);
    }

    void distribute(Colleague* const sender,std::string msg){
        for(unsigned int i = 0;i<colleagues.size();i++){
            if(colleagues.at(i)->getID() != sender->getID()){
                colleagues.at(i)->receive(msg);
            }
        }
    }
private:
    std::vector<Colleague*> colleagues;
};


void ConcreteColleage::send(std::string msg){
    std::cout<<"Message '"<<msg<<"' sent by Collage "<<id<<std::endl;
    mediator->distribute(this,msg);
}

