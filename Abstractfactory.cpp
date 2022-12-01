/**
 * @file Abstractfactory.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>


/**
 * ProductA
 * 
 */
class ProductA{
public:
    virtual ~ProductA(){};
    virtual const char* getname()=0;
};


/**
 * ConcreteProductAX 
 * 
 */
class ConcreteProductAX : public ProductA{
public:
    virtual ~ConcreteProductAX(){};
    const char* getname(){
        return "ConcreteProductAX";
    }
};

/**
 * ConcreteProductAY 
 * 
 */
class ConcreteProductAY : public ProductA{
public:
    virtual ~ConcreteProductAY(){};
    const char* getname(){
        return "ConcreteProductAX";
    }
};

/**
 * @brief 
 * 
 */
class ProductB{
public:
    virtual ~ProductB(){};
    virtual const char* getname()=0;
};

/**
 * @brief 
 * 
 */
class ConcreteProductBX:public ProductB{
public:
    virtual ~ConcreteProductBX(){};
    virtual const char* getname(){
        return "ConcreteProductBX";
    }
};

/**
 * @brief 
 * 
 */
class ConcreteProductBY:public ProductB{
public:
    virtual ~ConcreteProductBY(){};
    virtual const char* getname(){
        return "ConcreteProductBY";
    }
};

/**
 * @brief 
 * AbstractFactory
 */
class AbstractFactory{
public:
    virtual ~AbstractFactory(){};
    virtual ProductA* CreateProductA()=0;
    virtual ProductB* CreateProductB()=0;
};

/**
 * @brief 
 * 
 */
class ConcreteFactoryX:public AbstractFactory{
public:
    virtual ~ConcreteFactoryX(){};
    virtual ProductA* CreateProductA(){
        return new ConcreteProductAX();
    }
    virtual ProductB* CreateProductB(){
        return new ConcreteProductBX();
    }
};

/**
 * @brief 
 * 
 */
class ConcreteFactoryY:public AbstractFactory{
public:
    virtual ~ConcreteFactoryY(){};
    virtual ProductA* CreateProductA(){
        return new ConcreteProductAY();
    }
    virtual ProductB* CreateProductB(){
        return new ConcreteProductBY();
    }
};