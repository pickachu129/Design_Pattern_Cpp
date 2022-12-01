#include <iostream>

class Subject{
public:
    virtual ~Subject(){};
    virtual void request() = 0;
};



class RealSubject : public Subject{
public:
    void request(){
        std::cout<<"Real Subject request"<<std::endl;
    }
};

class Proxy:public Subject{
public:
    Proxy(){
        subject = new RealSubject();
    }

    ~Proxy(){
        if(subject){
            delete subject;
        }
    }

    void request(){
        subject->request();
    }
private:
    RealSubject* subject;
};

