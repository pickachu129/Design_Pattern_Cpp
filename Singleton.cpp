#include <iostream>
#include <pthread.h>
#include <mutex>

class Singleton{
public:
    Singleton(Singleton const&)=delete;
    Singleton& operator = (Singleton const&) = delete;

    static Singleton* get(){
        if(!instance){
            pthread_mutex_lock(&mutex);
            if(!instance){
                instance = new Singleton();
            }
            pthread_mutex_unlock(&mutex);
        }
    }

    static void restart(){
        if(instance){
            pthread_mutex_lock(&mutex);
            if(instance){
                delete instance;
            }
            pthread_mutex_unlock(&mutex);
        }
    }
private:
    Singleton(){};
    static Singleton* instance;
    static pthread_mutex_t mutex;
};

Singleton* Singleton::instance=nullptr; 