/****************************************************************************
 * hello/hello.c
 *
 *   Copyright (C) 2011 Uros Platise. All rights reserved.
 *   Author: Uros Platise <uros.platise@isotel.eu>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/


#include "autopilotone.h"

DataMarshaller dataMarsh;

int autopilotone_main(int argc, char *argv[])
{
    int i = 0;

    Channel *c = dataMarsh.AddChannel("dummy");  
    dataMarsh.RegisterSubscription("dummy", new AnonymousPipeSubscription());

    printf("Application started!\n");
    fflush(stdout);

    i = task_create("navigator", SCHED_PRIORITY_DEFAULT, 768, (main_t) navigator_main,
            (const char**) NULL);

    if(i > 0) {
        printf("Task created\n");

        struct sched_param param;
        sched_getparam(0, &param);
        sched_setscheduler(i, SCHED_RR, &param);
    } else {
        printf("Task not created");
    }

/*
    i = task_create("guidance", SCHED_PRIORITY_DEFAULT, 768, (main_t) guidance_main,
            (const char**)NULL);

    if(i > 0) {
        printf("Task created\n");

        struct sched_param param;
        sched_getparam(0, &param);
        sched_setscheduler(i, SCHED_RR, &param);
    } else {
        printf("Task not created");
    }
    */

    while(1) {
        c->Update((void*) NULL);
        usleep(500000);
    }
    return 0;
}
