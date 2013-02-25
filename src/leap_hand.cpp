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

#include "Leap.h"
#include "leap_utils.hpp"
#include "leap_pointable_private.hpp"
#include "leap_hand_private.hpp"
#include "leap_frame_private.hpp"

typedef std::vector<leap_pointable_ref> leap_pointable_list;

struct leap_hand
{
    leap_hand(Leap::Hand const& hand)
    	: wrap(hand)
    	, retain_count(1)
    {}

    Leap::Hand wrap;
    int retain_count;
    leap_pointable_list fingers;
    leap_pointable_list tools;
};

template <typename ListType>
void add_pointables(ListType const& w_pointables, leap_pointable_list& pointables)
{
    for (typename ListType::const_iterator it = w_pointables.begin();
         it != w_pointables.end();
         ++it) {
        pointables.push_back(leap_pointable_new(*it));
    }
}

void release_pointables(leap_pointable_list& pointables)
{
    for (leap_pointable_list::const_iterator it = pointables.begin();
         it != pointables.end();
         ++it) {
        leap_pointable_release(*it);
    }
}

void leap_hand_initialize(leap_hand_ref hand)
{
    add_pointables(W(hand).fingers(), hand->fingers);
    add_pointables(W(hand).tools(), hand->tools);
}

leap_hand_ref leap_hand_new(Leap::Hand const& hand)
{
    leap_hand_ref result = new leap_hand(hand);
    leap_hand_initialize(result);
    return result;
}

void leap_hand_retain(leap_hand_ref hand)
{
    hand->retain_count++;
}

void leap_hand_delete(leap_hand_ref hand)
{
    release_pointables(hand->fingers);
    release_pointables(hand->tools);
    delete hand;
}

void leap_hand_release(leap_hand_ref hand)
{
    hand->retain_count--;
    if (hand->retain_count == 0) {
        leap_hand_delete(hand);
    }
}

int32_t leap_hand_id(leap_hand_ref hand)
{
    return W(hand).id();
}

int leap_hand_fingers_count(leap_hand_ref hand)
{
    return (int)hand->fingers.size();
}

leap_pointable_ref leap_hand_finger_at_index(leap_hand_ref hand, int index)
{
    return hand->fingers[index];
}

int leap_hand_tools_count(leap_hand_ref hand)
{
    return (int)hand->tools.size();
}

leap_pointable_ref leap_hand_tool_at_index(leap_hand_ref hand, int index)
{
    return hand->tools[index];
}

void leap_hand_palm_position(leap_hand_ref hand, leap_vector *out_result)
{
    *out_result = to_vector(W(hand).palmPosition());
}

void leap_hand_palm_normal(leap_hand_ref hand, leap_vector *out_result)
{
    *out_result = to_vector(W(hand).palmNormal());
}

void leap_hand_palm_velocity(leap_hand_ref hand, leap_vector *out_result)
{
    *out_result = to_vector(W(hand).palmVelocity());
}

void leap_hand_direction(leap_hand_ref hand, leap_vector *out_result)
{
    *out_result = to_vector(W(hand).direction());
}

void leap_hand_sphere_center(leap_hand_ref hand, leap_vector *out_result)
{
    *out_result = to_vector(W(hand).sphereCenter());
}

float leap_hand_sphere_radius(leap_hand_ref hand)
{
    return W(hand).sphereRadius();
}

void leap_hand_translation(leap_hand_ref hand, leap_frame_ref since_frame, leap_vector *out_result)
{
    *out_result = to_vector(W(hand).translation(from_frame(since_frame)));
}

void leap_hand_rotation_axis(leap_hand_ref hand, leap_frame_ref since_frame, leap_vector *out_result)
{
    *out_result = to_vector(W(hand).rotationAxis(from_frame(since_frame)));
}

float leap_hand_rotation_angle(leap_hand_ref hand, leap_frame_ref since_frame)
{
    return W(hand).rotationAngle(from_frame(since_frame));
}

float leap_hand_rotation_angle_around_axis(leap_hand_ref hand, leap_frame_ref since_frame, leap_vector *in_axis)
{
    return W(hand).rotationAngle(from_frame(since_frame), from_vector(*in_axis));
}

float leap_hand_scale_factor(leap_hand_ref hand, leap_frame_ref since_frame)
{
    return W(hand).scaleFactor(from_frame(since_frame));
}

int leap_hand_is_valid(leap_hand_ref hand)
{
    return W(hand).isValid();
}

int leap_hand_equal(leap_hand_ref hand, leap_hand_ref other)
{
    return W(hand) == W(other);
}
