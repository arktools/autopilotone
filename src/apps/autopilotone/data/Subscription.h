
#include <string.h>

#ifndef _SUBSCRIPTION_H
#define _SUBSCRIPTION_H
class Subscription {
    public:
        Subscription(){} 
        ~Subscription(){}
        virtual void Notify(void* data);
        virtual void* Receive();
};
#endif
