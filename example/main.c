/*
 * C wrapper around the Leap Motion library.
 * Copyright (c) 2013, Camille Troillard. All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an "AS
 * IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
 * express or implied.  See the License for the specific language
 * governing permissions and limitations under the License.
 *
 */

#include <stdio.h>
#include "leap_c.h"

void on_init(leap_controller_ref controller, void *user_info)
{
    printf("init\n");
}

void on_connect(leap_controller_ref controller, void *user_info)
{
    printf("connect\n");
}

void on_disconnect(leap_controller_ref controller, void *user_info)
{
    printf("disconnect\n");
}

void on_exit(leap_controller_ref controller, void *user_info)
{
    printf("exit\n");
}

void on_frame(leap_controller_ref controller, void *user_info)
{
    leap_frame_ref frame = leap_controller_copy_frame(controller, 0);
    printf("frame %llu\n", leap_frame_timestamp(frame));
    leap_frame_delete(frame);
}


int main(int argc, const char * argv[])
{
    leap_controller_ref controller = leap_controller_new();
    struct leap_controller_callbacks callbacks;
    callbacks.on_init = on_init;
    callbacks.on_connect = on_connect;
    callbacks.on_disconnect = on_disconnect;
    callbacks.on_exit = on_exit;
    callbacks.on_frame = on_frame;
    leap_listener_ref listener = leap_listener_new(&callbacks, NULL);
    leap_controller_add_listener(controller, listener);

    do {} while(1);
    return 0;
}
