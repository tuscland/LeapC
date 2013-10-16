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

#ifndef LeapC_leap_types_h
#define LeapC_leap_types_h

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct leap_pointable* leap_pointable_ref;
    typedef struct leap_hand* leap_hand_ref;
    typedef struct leap_gesture* leap_gesture_ref;
    typedef struct leap_frame* leap_frame_ref;
    typedef struct leap_controller* leap_controller_ref;
    typedef struct leap_listener* leap_listener_ref;

    struct _leap_vector {
        float x;
        float y;
        float z;
    };
    typedef struct _leap_vector leap_vector;

    enum _leap_controller_policy_flag {
        LEAP_CONTROLLER_POLICY_DEFAULT = 0,
        LEAP_CONTROLLER_POLICY_BACKGROUND_FRAMES = (1 << 0)
    };
    typedef _leap_controller_policy_flag leap_controller_policy_flag;

    enum _leap_gesture_type {
        LEAP_GESTURE_TYPE_INVALID    = -1,
        LEAP_GESTURE_TYPE_SWIPE      =  1,
        LEAP_GESTURE_TYPE_CIRCLE     =  4,
        LEAP_GESTURE_TYPE_SCREEN_TAP =  5,
        LEAP_GESTURE_TYPE_KEY_TAP    =  6
    };
    typedef enum _leap_gesture_type leap_gesture_type;

    enum _leap_gesture_state {
        LEAP_GESTURE_STATE_INVALID = -1,
        LEAP_GESTURE_STATE_START   =  1,
        LEAP_GESTURE_STATE_UPDATE  =  2,
        LEAP_GESTURE_STATE_STOP    =  3
    };
    typedef enum _leap_gesture_state leap_gesture_state;

    typedef void (*leap_controller_callback)(leap_controller_ref, void*);
    struct leap_controller_callbacks {
        leap_controller_callback on_init;
        leap_controller_callback on_connect;
        leap_controller_callback on_disconnect;
        leap_controller_callback on_exit;
        leap_controller_callback on_frame;
    };

#ifdef __cplusplus
}
#endif

#endif
