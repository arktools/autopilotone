
#include <string.h>
#include <stdio.h>
#include "Channel.h"
#include "Subscription.h"
//#include <map>

#ifndef DATAMARSHALLER_H
#define DATAMARSHALLER_H
class DataMarshaller {
    public:
        DataMarshaller(){}
        ~DataMarshaller(){}
        Channel* AddChannel(const char* name);
        void DeleteChannel();
        bool RegisterSubscription(const char* channelName, Subscription* s);
        void Test() {
            printf("From data marshaller\n");
        }

    private:
        Channel *c;
        //std::map<int, Channel> Channels;
};

#endif
