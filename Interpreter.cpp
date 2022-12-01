#include <iostream>
#include <map>

class Context{
public:
    void set(const std::string& var,const bool value){
        vars.insert(std::pair<std::string,bool>(var,value));
    }

    bool get(const std::string& exp){
        return vars[exp];
    }
private:
    std::map<std::string,bool> vars;
};


class AbstractExpression{
public:
    virtual ~AbstractExpression(){};
    virtual bool interpret(Context* const){
        return false;
    }
};

class TerminalExpression : public AbstractExpression{
public:
    TerminalExpression(const std::string& val):value(val){};
    ~TerminalExpression(){}

    bool interpret(Context* const context){
        return context->get(value);
    }
private:
    std::string value;
};

class NonterminalExpression : public AbstractExpression{
public:
    NonterminalExpression(AbstractExpression* left,AbstractExpression* right):lop(left),rop(right){};

    ~NonterminalExpression(){
        if(lop){
            delete lop;
        }
        if(rop){
            delete rop;
        }
    }

    bool interpret(Context* const context){
        return lop->interpret(context) && rop->interpret(context);
    }
private:
    AbstractExpression* lop;
    AbstractExpression* rop;
};