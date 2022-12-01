#include <iostream>
#include <string>

class Prototype{
public:
    virtual ~Prototype(){};
    virtual Prototype* clone() = 0;
    virtual std::string type() = 0;
};

class PrototypeA:public Prototype{
public:
    ~PrototypeA(){};

    Prototype* clone(){
        return new PrototypeA();
    }

    std::string type(){
        return "type A";
    }
};

class PrototypeB:public Prototype{
public:
    ~PrototypeB(){};
    Prototype* clone(){
        return new PrototypeB();
    }

    std::string type(){
        return "type B";
    }
};

class Client{
public:
    static void init(){
        types[0] = new PrototypeA();
        types[1] = new PrototypeB();
    }

    static void remove(){
        delete types[0];
        delete types[1];
    }

    static Prototype* make(const int index){
        if(index >= n_types){
            return nullptr;
        }
        return types[index]->clone();
    }
private:
    static Prototype* types[2];
    static int n_types;
};

Prototype* Client::types[2];
int Client::n_types = 2;

