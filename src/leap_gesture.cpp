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

#include <cstring>
#include <string>
#include <assert.h>

#include "Leap.h"
#include "leap_utils.hpp"
#include "leap_pointable_private.hpp"
#include "leap_gesture.h"

struct leap_gesture {
    leap_gesture(Leap::Gesture const& gesture)
    : wrap(gesture)
    , retain_count(1)
    {}

    Leap::Gesture wrap;
    int retain_count;
};


void leap_gesture_initialize(leap_gesture_ref gesture)
{
}

leap_gesture_ref leap_gesture_new(Leap::Gesture const& gesture)
{
    leap_gesture_ref result = new leap_gesture(gesture);
    leap_gesture_initialize(result);
    return result;
}

void leap_gesture_retain(leap_gesture_ref gesture)
{
    gesture->retain_count++;
}

void leap_gesture_delete(leap_gesture_ref gesture)
{
    delete gesture;
}

void leap_gesture_release(leap_gesture_ref gesture)
{
    gesture->retain_count--;
    if (gesture->retain_count == 0) {
        leap_gesture_delete(gesture);
    }
}

int32_t leap_gesture_id(leap_gesture_ref gesture)
{
    return W(gesture).id();
}

leap_gesture_type leap_gesture_gesture_type(leap_gesture_ref gesture)
{
    return leap_gesture_type(W(gesture).type());
}

leap_gesture_state leap_gesture_gesture_state(leap_gesture_ref gesture)
{
    return leap_gesture_state(W(gesture).state());
}

int64_t leap_gesture_duration(leap_gesture_ref gesture)
{
    return W(gesture).duration();
}

float leap_gesture_duration_seconds(leap_gesture_ref gesture)
{
    return W(gesture).durationSeconds();
}

int leap_gesture_is_valid(leap_gesture_ref gesture)
{
    return W(gesture).isValid();
}

int leap_gesture_equal(leap_gesture_ref gesture, leap_gesture_ref other)
{
    return W(gesture) == W(other);
}

#pragma mark -
#pragma mark SwipeGesture
#define WC(gesture) Leap::SwipeGesture(W(gesture))

void leap_gesture_swipe_start_position(leap_gesture_ref gesture, leap_vector *out_result)
{
    *out_result = to_vector(WC(gesture).startPosition());
}

void leap_gesture_swipe_position(leap_gesture_ref gesture, leap_vector *out_result)
{
    *out_result = to_vector(WC(gesture).position());
}

void leap_gesture_swipe_direction(leap_gesture_ref gesture, leap_vector *out_result)
{
    *out_result = to_vector(WC(gesture).direction());
}

float leap_gesture_swipe_speed(leap_gesture_ref gesture)
{
    return WC(gesture).speed();
}

leap_pointable_ref leap_gesture_swipe_copy_pointable(leap_gesture_ref gesture)
{
    return leap_pointable_new(WC(gesture).pointable());
}

#undef WC

#pragma mark -
#pragma mark CircleGesture
#define WC(gesture) Leap::CircleGesture(W(gesture))

void leap_gesture_circle_center(leap_gesture_ref gesture, leap_vector *out_result)
{
    *out_result = to_vector(WC(gesture).center());
}

void leap_gesture_circle_normal(leap_gesture_ref gesture, leap_vector *out_result)
{
    *out_result = to_vector(WC(gesture).normal());
}

float leap_gesture_circle_progress(leap_gesture_ref gesture)
{
    return WC(gesture).progress();
}

float leap_gesture_circle_radius(leap_gesture_ref gesture)
{
    return WC(gesture).radius();
}

leap_pointable_ref leap_gesture_circle_copy_pointable(leap_gesture_ref gesture)
{
    return leap_pointable_new(WC(gesture).pointable());
}

#undef WC

#pragma mark -
#pragma mark ScreenTap
#define WC(gesture) Leap::ScreenTapGesture(W(gesture))

void leap_gesture_screen_tap_position(leap_gesture_ref gesture, leap_vector *out_result)
{
    *out_result = to_vector(WC(gesture).position());
}

void leap_gesture_screen_tap_direction(leap_gesture_ref gesture, leap_vector *out_result)
{
    *out_result = to_vector(WC(gesture).direction());
}

leap_pointable_ref leap_gesture_screen_tap_copy_pointable(leap_gesture_ref gesture)
{
    return leap_pointable_new(WC(gesture).pointable());
}

#undef WC


#pragma mark -
#pragma mark KeyTap
#define WC(gesture) Leap::KeyTapGesture(W(gesture))

void leap_gesture_key_tap_position(leap_gesture_ref gesture, leap_vector *out_result)
{
    *out_result = to_vector(WC(gesture).position());
}

void leap_gesture_key_tap_direction(leap_gesture_ref gesture, leap_vector *out_result)
{
    *out_result = to_vector(WC(gesture).direction());
}

leap_pointable_ref leap_gesture_key_tap_copy_pointable(leap_gesture_ref gesture)
{
    return leap_pointable_new(WC(gesture).pointable());
}

#undef WC
