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

#ifndef LeapC_leap_pointable_h
#define LeapC_leap_pointable_h

#include "leap_types.h"
#include "leap_math.h"

#ifdef __cplusplus
extern "C" {
#endif

    void leap_pointable_retain(leap_pointable_ref pointable);
    void leap_pointable_release(leap_pointable_ref pointable);
    int32_t leap_pointable_id(leap_pointable_ref pointable);

    void leap_pointable_tip_position(leap_pointable_ref pointable, leap_vector *out_result);
    void leap_pointable_tip_velocity(leap_pointable_ref pointable, leap_vector *out_result);
    void leap_pointable_direction(leap_pointable_ref pointable, leap_vector *out_result);
    float leap_pointable_width(leap_pointable_ref pointable);
    float leap_pointable_length(leap_pointable_ref pointable);
    int leap_pointable_is_tool(leap_pointable_ref pointable);
    int leap_pointable_is_finger(leap_pointable_ref pointable);
    int leap_pointable_is_valid(leap_pointable_ref pointable);
    int leap_pointable_equal(leap_pointable_ref pointable, leap_pointable_ref other);

#ifdef __cplusplus
}
#endif

#endif
