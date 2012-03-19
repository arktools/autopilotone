
#include <string.h>
#include "Subscription.h"

#ifndef CHANNEL_H
#define CHANNEL_H
class Channel {
    public:
        Channel(const char* name) {
            strcpy(_name, name);
        }
        ~Channel() {}

        bool RegisterSubscription(Subscription *s){
            sub = s;
            return true;
        }

        void Update(void* data) {
            sub->Notify(data);
        }

    private:
        char _name[17];
        Subscription *sub;

};

#endif
