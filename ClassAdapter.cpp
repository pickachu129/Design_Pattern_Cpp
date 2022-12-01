#include <iostream>

/**
 * @brief 
 * Target
 */
class Traget{
public:
    virtual ~Traget(){};
    virtual void request()=0;
};


/**
 * @brief 
 * Adaptee
 */

class Adaptee{
public:
    virtual ~Adaptee(){};
    virtual void specificRequest(){
        std::cout<<"specificRequest"<<std::endl;
    }
};


/**
 * @brief 
 * Adapter
 */
class Adapter: public Traget,private Adaptee{
public:
    virtual ~Adapter(){};
    virtual void request(){
        specificRequest();
    }
};