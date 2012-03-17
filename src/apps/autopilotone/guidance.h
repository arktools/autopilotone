
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
#ifdef __cplusplus
}
#endif

#ifndef GUIDANCE_H
#define GUIDANCE_H

#ifdef __cplusplus
extern "C" {
#endif
    extern int guidance_main(int argc, char* argv[]);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
class Guidance
{
    public:
        Guidance(void) {}
        ~Guidance(void) {}

        void HelloWorld(void) {
            printf("Hello from guidance!\n");
        }
};
#endif

#endif
