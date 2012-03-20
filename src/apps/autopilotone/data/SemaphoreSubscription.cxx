#include "SemaphoreSubscription.h"

SemaphoreSubscription::SemaphoreSubscription() {

    count = 0;
    int retVal;

    // Initialize semaphore with value 1. pshared parameter (#2) is ignored.
    retVal = sem_init(&sem, 0, 1);
    if(retVal == 0) {
        printf("Semaphore successfully initiliazed\n");
    } else {
        printf("Failed to initialize semaphore\n");
    }
}

//AnonymousPipeSubscription::~AnonymousPipeSubscription() {
//}

void SemaphoreSubscription::Notify(void* data) {

    printf("Notify\n");
    
    sem_wait(&sem);
    count++;
    usleep(2000000);
    printf("End Notify\n");
    sem_post(&sem);

}

void* SemaphoreSubscription::Receive() {

    int* ret = new int;

    printf("Waiting on Semaphore\n");
    sem_wait(&sem);
    *ret = count;
    sem_post(&sem);
    return (void*) ret;
}

