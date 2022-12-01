#include <iostream>
#include <string>


//Product
class Product{
public:
    void makeA(const std::string &part){
        partA = part;
    }

    void makeB(const std::string &part){
        partB = part;
    }

    void makeC(const std::string &part){
        partC = part;
    }

    std::string getPart(){
        return partA+"-"+partB+"-"+partC;
    }
private:
    std::string partA;
    std::string partB;
    std::string partC;
};

//Builder
class Builder{
public:
    virtual ~Builder(){};
    Product get(){
        return product;
    }
    virtual void buildPartA() = 0;
    virtual void buildPartB() = 0;
    virtual void buildPartC() = 0;
protected:
    Product product;
};

class BuilderX : public Builder{
public:
    virtual void buildPartA(){
        product.makeA("A-X");
    }

    virtual void buildPartB(){
        product.makeB("B-X");
    }

    virtual void buildPartC(){
        product.makeC("C-X");
    }
};

class BuilderY : public Builder{
public:
    virtual void buildPartA(){
        product.makeA("A-Y");
    }

    virtual void buildPartB(){
        product.makeB("B-Y");
    }

    virtual void buildPartC(){
        product.makeC("C-Y");
    }
};



class Director{
public:
    Director():builder(){};

    ~Director(){
        if(builder){
            delete builder;
        }
    }

    void set(Builder* b){
        this->builder = b;
    }

    Product getProduct(){
        return builder->get();
    }

    void construct(){
        builder->buildPartA();
        builder->buildPartB();
        builder->buildPartC();
    }
private:
    Builder *builder;
};