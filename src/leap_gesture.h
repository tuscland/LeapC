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
#ifndef LeapC_leap_gesture_h
#define LeapC_leap_gesture_h

#include "leap_types.h"

#ifdef __cplusplus
extern "C" {
#endif

    void leap_gesture_retain(leap_gesture_ref gesture);
    void leap_gesture_release(leap_gesture_ref gesture);
    int32_t leap_gesture_id(leap_gesture_ref gesture);

    leap_gesture_type leap_gesture_gesture_type(leap_gesture_ref gesture);
    leap_gesture_state leap_gesture_gesture_state(leap_gesture_ref gesture);
    int64_t leap_gesture_duration(leap_gesture_ref gesture);
    float leap_gesture_duration_seconds(leap_gesture_ref gesture);

    int leap_gesture_is_valid(leap_gesture_ref gesture);
    int leap_gesture_equal(leap_gesture_ref gesture, leap_gesture_ref other);

    /* SwipeGesture */
    void leap_gesture_swipe_start_position(leap_gesture_ref gesture, leap_vector *out_result);
    void leap_gesture_swipe_position(leap_gesture_ref gesture, leap_vector *out_result);
    void leap_gesture_swipe_direction(leap_gesture_ref gesture, leap_vector *out_result);
    float leap_gesture_swipe_speed(leap_gesture_ref gesture);
    leap_pointable_ref leap_gesture_swipe_copy_pointable(leap_gesture_ref gesture);

    /* CircleGesture */
    void leap_gesture_circle_center(leap_gesture_ref gesture, leap_vector *out_result);
    void leap_gesture_circle_normal(leap_gesture_ref gesture, leap_vector *out_result);
    float leap_gesture_circle_progress(leap_gesture_ref gesture);
    float leap_gesture_circle_radius(leap_gesture_ref gesture);
    leap_pointable_ref leap_gesture_circle_copy_pointable(leap_gesture_ref gesture);

    /* ScreenTapGesture */
    void leap_gesture_screen_tap_position(leap_gesture_ref gesture, leap_vector *out_result);
    void leap_gesture_screen_tap_direction(leap_gesture_ref gesture, leap_vector *out_result);
    leap_pointable_ref leap_gesture_screen_tap_copy_pointable(leap_gesture_ref gesture);

    /* KeyTapGesture */
    void leap_gesture_key_tap_position(leap_gesture_ref gesture, leap_vector *out_result);
    void leap_gesture_key_tap_direction(leap_gesture_ref gesture, leap_vector *out_result);
    leap_pointable_ref leap_gesture_key_tap_copy_pointable(leap_gesture_ref gesture);

#ifdef __cplusplus
}
#endif

#endif /* defined(LeapC_leap_gesture_h) */
