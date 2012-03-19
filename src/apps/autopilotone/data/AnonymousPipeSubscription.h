#include "Subscription.h"
#include <stdio.h>

#include <unistd.h>

#ifndef _ANON_PIPE_SUB_H
#define _ANON_PIPE_SUB_H
class AnonymousPipeSubscription : public Subscription {
    public:
        AnonymousPipeSubscription();
        ~AnonymousPipeSubscription(){}
        void Notify(void* data);
        void* Receive();

    private:
        int filedes[2];
};
#endif


