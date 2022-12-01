#include <iostream>
#include "Vistor.cpp"

int main(){
    Element* elementA = new ConcreteElementA();
    Element* elementB = new ConcreteElementB();

    Visitor1 visitor1;
    Visitor2 visitor2;

    elementA->accept(&visitor1);
    elementA->accept(&visitor2);
    elementB->accept(&visitor1);
    elementB->accept(&visitor2);
    return 0;
}
