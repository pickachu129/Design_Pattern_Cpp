#include <iostream>
#include <vector>

class Memento{
public:
    friend class Originator;

    Memento(const int s):state(s){};

    void setState(const int s){
        this->state = s;
    }

    int getState(){
        return state;
    }
private:
    int state;
};

class Originator{
public:
    void setState(const int s){
        std::cout<<"Set state to"<<s<<"."<<std::endl;
        state = s;
    }

    int getState(){
        return state;
    }

    void setMemento(Memento* const m){
        state = m->getState();
    }

    Memento* createMemento(){
        return new Memento(state);
    }

private:
    int state;
};

class CareTaker{
public:
    CareTaker(Originator* const o):originator(o){};

    ~CareTaker(){
        for(unsigned int i=0;i<history.size();i++){
            delete history[i];
        }
        history.clear();
    }

    void save(){
        std::cout<<"Save state."<<std::endl;
        history.push_back(originator->createMemento());
    }

    void undo(){
        if(history.empty()){
            std::cout<<"Unable to undo state."<<std::endl;
            return ;
        }
        Memento *m = history.back();
        originator->setMemento(m);
        std::cout<<"Unable to undo state."<<std::endl;
        history.pop_back();
        delete m;
    }
private:
    Originator *originator;
    std::vector<Memento*> history;
};