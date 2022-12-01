#include <iostream>


/**
 * @brief 
 * Invoker
 */
class Reciver{
public:
    void action(){
        std::cout<<"Reciver:excute action!"<<std::endl;
    }
};

class Command{
public:
    virtual ~Command(){};
    virtual void excute()=0;
protected:
    Command(){};
};

class ConcreteCommand : public Command{
public:
    ConcreteCommand(Reciver* r):reciver(r){};
    ~ConcreteCommand(){
        if(reciver){
            delete reciver;
        }
    }

    void excute(){
        reciver->action();
    }
private:
    Reciver* reciver;
};

class Invoker{
public:
    void set(Command* c){
        this->command = c;
    }

    void confirm(){
        if(command){
            command->excute();
        }
    }
private:
    Command* command;
};