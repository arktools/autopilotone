#include "AnonymousPipeSubscription.h"

AnonymousPipeSubscription::AnonymousPipeSubscription() {
    p1_filedes = new int[2];
    p2_filedes = new int[2];
    pipe(p1_filedes);

    p2_filedes[0] = dup(p1_filedes[0]);
    p2_filedes[1] = dup(p1_filedes[1]);

    close(p1_filedes[0]);
    close(p2_filedes[1]);

}

//AnonymousPipeSubscription::~AnonymousPipeSubscription() {
//}

void AnonymousPipeSubscription::Notify(void* data) {
    int* err;
    char* msg = "Test\n";
    int i;

    for(i = 0; i < 1; i++) {

        writeCount = write(p1_filedes[1],msg, strlen(msg)+1);
        
        if(writeCount == -1) {
            err = get_errno_ptr();
            printf("%i bytes written\n", writeCount);
            printf("errno = %i\n", errno);
        }
        
    }

}

void* AnonymousPipeSubscription::Receive() {
    //printf("Receiving\n");
    //return (void*) NULL;
    //printf("read\n");
    char buff[30];
    read(p2_filedes[0], buff, sizeof(buff));
    //printf("read complete\n");
    printf("%s",buff);
    return (void*) NULL;
}

