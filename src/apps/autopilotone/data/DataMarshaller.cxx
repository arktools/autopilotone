
#include "DataMarshaller.h"

Channel* DataMarshaller::AddChannel(const char* name) {

    c = new Channel(name);
    return c;
}

void DataMarshaller::DeleteChannel() {
    // Not implemented
}

bool DataMarshaller::RegisterSubscription(const char* channelName, Subscription *s) {
    c->RegisterSubscription(s);
    return true;
}


