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

    typedef enum {
        LEAP_GESTURE_TYPE_INVALID    = -1,
        LEAP_GESTURE_TYPE_SWIPE      =  1,
        LEAP_GESTURE_TYPE_CIRCLE     =  4,
        LEAP_GESTURE_TYPE_SCREEN_TAP =  5,
        LEAP_GESTURE_TYPE_KEY_TAP    =  6
    } leap_gesture_type;

#ifdef __cplusplus
} /* closing brace for extern "C" */
#endif

#endif
