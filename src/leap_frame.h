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

#ifndef LeapC_leap_frame_h
#define LeapC_leap_frame_h

#include "leap_types.h"

#ifdef __cplusplus
extern "C" {
#endif

    void leap_frame_retain(leap_frame_ref frame);
    void leap_frame_release(leap_frame_ref frame);
    int64_t leap_frame_id(leap_frame_ref frame);

    int64_t leap_frame_timestamp(leap_frame_ref frame);

    int leap_frame_hands_count(leap_frame_ref frame);
    leap_hand_ref leap_frame_hand_at_index(leap_frame_ref frame, int index);

    int leap_frame_gestures_count(leap_frame_ref frame);
    leap_gesture_ref leap_frame_gesture_at_index(leap_frame_ref frame, int index);

    int leap_frame_is_valid(leap_frame_ref frame);
    int leap_frame_equal(leap_frame_ref frame, leap_frame_ref other);

#ifdef __cplusplus
}
#endif

#endif
