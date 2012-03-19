
#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <nuttx/config.h>

#include <debug.h>

#include <nuttx/init.h>
#include <nuttx/arch.h>

#include "data/Subscription.h"
#include "data/AnonymousPipeSubscription.h"
#include "data/DataMarshaller.h"

#ifdef __cplusplus
}
#endif

#ifndef NAVIGATOR_H
#define NAVIGATOR_H

#ifdef __cplusplus
extern "C" {
#endif
    extern int navigator_main(int argc, char* argv[]);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
class Navigator
{
    public:
        Navigator(void) {}
        ~Navigator(void) {}

        void HelloWorld(void) {
            printf("Hello from navigator\n");
        }

    private:
        Subscription *s;

};
#endif

#endif
