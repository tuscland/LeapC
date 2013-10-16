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

#ifndef LeapC_leap_hand_h
#define LeapC_leap_hand_h

#include "leap_types.h"
#include "leap_math.h"

#ifdef __cplusplus
extern "C" {
#endif

    void leap_hand_retain(leap_hand_ref hand);
    void leap_hand_release(leap_hand_ref hand);
    int32_t leap_hand_id(leap_hand_ref hand);

    int leap_hand_fingers_count(leap_hand_ref hand);
    leap_pointable_ref leap_hand_finger_at_index(leap_hand_ref hand, int index);
    int leap_hand_tools_count(leap_hand_ref hand);
    leap_pointable_ref leap_hand_tool_at_index(leap_hand_ref hand, int index);
    void leap_hand_palm_position(leap_hand_ref hand, leap_vector *out_result);
    void leap_hand_palm_normal(leap_hand_ref hand, leap_vector *out_result);
    void leap_hand_palm_velocity(leap_hand_ref hand, leap_vector *out_result);
    void leap_hand_direction(leap_hand_ref hand, leap_vector *out_result);
    void leap_hand_sphere_center(leap_hand_ref hand, leap_vector *out_result);
    float leap_hand_sphere_radius(leap_hand_ref hand);
    void leap_hand_translation(leap_hand_ref hand, leap_frame_ref since_frame, leap_vector *out_result);
    void leap_hand_rotation_axis(leap_hand_ref hand, leap_frame_ref since_frame, leap_vector *out_result);
    float leap_hand_rotation_angle(leap_hand_ref hand, leap_frame_ref since_frame);
    float leap_hand_rotation_angle_around_axis(leap_hand_ref hand, leap_frame_ref since_frame, leap_vector *in_axis);
    float leap_hand_scale_factor(leap_hand_ref hand, leap_frame_ref since_frame);
    int leap_hand_is_valid(leap_hand_ref hand);
    int leap_hand_equal(leap_hand_ref hand, leap_hand_ref other);

#ifdef __cplusplus
}
#endif


#endif
