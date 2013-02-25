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
#include <unistd.h>
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

    for (int i = 0; i < leap_frame_hands_count(frame); i++) {
        leap_hand_ref hand = leap_frame_hand_at_index(frame, i);
        printf("\thand %i: fingers=%i\n", leap_hand_id(hand), leap_hand_fingers_count(hand));

        for (int p = 0; p < leap_hand_fingers_count(hand); p++) {
            leap_pointable_ref pointable = leap_hand_finger_at_index(hand, p);
            leap_vector tip_position;
            leap_pointable_tip_position(pointable, &tip_position);
            printf("\t\tfinger %i: tip-pos={%0.2f, %0.2f, %0.2f}\n",
                   leap_pointable_id(pointable), tip_position.x, tip_position.y, tip_position.z);
        }

        for (int p = 0; p < leap_hand_tools_count(hand); p++) {
            leap_pointable_ref pointable = leap_hand_tool_at_index(hand, p);
            leap_vector tip_position;
            leap_pointable_tip_position(pointable, &tip_position);
            printf("\t\ttool   %i: tip-pos={%0.2f, %0.2f, %0.2f}\n",
                   leap_pointable_id(pointable), tip_position.x, tip_position.y, tip_position.z);
        }
    }
    leap_frame_release(frame);
}


int main(int argc, const char * argv[])
{
    struct leap_controller_callbacks callbacks;
    callbacks.on_init = on_init;
    callbacks.on_connect = on_connect;
    callbacks.on_disconnect = on_disconnect;
    callbacks.on_exit = on_exit;
    callbacks.on_frame = on_frame;

    leap_listener_ref listener = leap_listener_new(&callbacks, NULL);
    leap_controller_ref controller = leap_controller_new();
    leap_controller_add_listener(controller, listener);

    do { sleep(1); } while(1);
    return 0;
}
