#include "Subscription.h"
#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>

#ifndef _SEMAPHORE_SUB_H
#define _SEMAPHORE_SUB_H
class SemaphoreSubscription : public Subscription {
    public:
        SemaphoreSubscription();
        ~SemaphoreSubscription(){}
        void Notify(void* data);
        void* Receive();

    private:
        sem_t sem;
        int count;
};
#endif


