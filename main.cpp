#include <iostream>
#include "Prototype.cpp"
#include "Proxy.cpp"

int main(){
    Proxy* proxy = new Proxy();
    proxy->request();
    delete proxy;
    return 0;








    // Mediator* mediator = new ConcreteMediator();

    // Colleague* c1 = new ConcreteColleage(mediator,1);
    // Colleague* c2 = new ConcreteColleage(mediator,2);
    // Colleague* c3 = new ConcreteColleage(mediator,3);

    // mediator->add(c1);
    // mediator->add(c2);
    // mediator->add(c3);
    // c1->send("Hi!");
    // c2->send("Hello!");

    // delete mediator;
    // return 0;


    // Originator* originator = new Originator();
    // CareTaker* careTaker = new CareTaker(originator);
    // originator->setState(1);
    // careTaker->save();
    // originator->setState(2);
    // careTaker->save();
    // originator->setState(3);
    // careTaker->undo();
    // std::cout<<"Actual state is "<<originator->getState() <<"."<<std::endl;
    // delete originator;
    // delete careTaker;
    // return 0;
}
