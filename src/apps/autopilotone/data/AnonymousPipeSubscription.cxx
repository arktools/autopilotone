#include "AnonymousPipeSubscription.h"

AnonymousPipeSubscription::AnonymousPipeSubscription() {
    pipe(filedes);

}

//AnonymousPipeSubscription::~AnonymousPipeSubscription() {
//}

void AnonymousPipeSubscription::Notify(void* data) {
    //printf("write\n");
    write(filedes[1],"Test\n", 6);

}

void* AnonymousPipeSubscription::Receive() {
    //printf("Receiving\n");
    //return (void*) NULL;
    printf("read\n");
    char buff[5];
    read(filedes[0], buff, sizeof(buff));
    printf("%s",buff);
}

