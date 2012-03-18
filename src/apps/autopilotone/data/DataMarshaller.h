
#include <string.h>
#include "Channel.h"
#include "Subscription.h"
//#include <map>

#ifndef DATAMARSHALLER_H
#define DATAMARSHALLER_H
class DataMarshaller {
    public:
        DataMarshaller();
        ~DataMarshaller();
        void AddChannel();
        void DeleteChannel();
        bool RegisterSubscription(Subscription* s);

    private:
        //std::map<int, Channel> Channels;
};

#endif
