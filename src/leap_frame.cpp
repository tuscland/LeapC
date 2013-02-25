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

#include <vector>

#include "Leap.h"
#include "leap_utils.hpp"
#include "leap_frame_private.hpp"
#include "leap_hand_private.hpp"
#include "leap_gesture_private.hpp"

typedef std::vector<leap_hand_ref> leap_hand_list;
typedef std::vector<leap_gesture_ref> leap_gesture_list;

struct leap_frame
{
    leap_frame(Leap::Frame const& frame)
    	: wrap(frame)
    	, retain_count(1)
    {}

    Leap::Frame wrap;
    int retain_count;
    leap_hand_list hands;
    leap_gesture_list gestures;
};

void leap_frame_initialize(leap_frame_ref frame)
{
    Leap::HandList const& w_hands = W(frame).hands();
    for (Leap::HandList::const_iterator it = w_hands.begin();
         it != w_hands.end();
         ++it) {
        frame->hands.push_back(leap_hand_new(*it));
    }

    Leap::GestureList const& w_gestures = W(frame).gestures();
    for (Leap::GestureList::const_iterator it = w_gestures.begin();
         it != w_gestures.end();
         ++it) {
        frame->gestures.push_back(leap_gesture_new(*it));
    }
}

leap_frame_ref leap_frame_copy(Leap::Frame const& frame)
{
    leap_frame_ref result = new leap_frame(frame);
    leap_frame_initialize(result);
    return result;
}

void leap_frame_retain(leap_frame_ref frame)
{
    frame->retain_count++;
}

void leap_frame_delete(leap_frame_ref frame)
{
    for (leap_hand_list::const_iterator it = frame->hands.begin();
         it != frame->hands.end();
         ++it) {
        leap_hand_release(*it);
    }
    delete frame;
}

void leap_frame_release(leap_frame_ref frame)
{
    frame->retain_count--;
    if (frame->retain_count == 0) {
        leap_frame_delete(frame);
    }
}

int64_t leap_frame_id(leap_frame_ref frame)
{
    return W(frame).id();
}

int64_t leap_frame_timestamp(leap_frame_ref frame)
{
    return W(frame).timestamp();
}

int leap_frame_hands_count(leap_frame_ref frame)
{
    return frame->hands.size();
}

leap_hand_ref leap_frame_hand_at_index(leap_frame_ref frame, int index)
{
    return frame->hands[index];
}

int leap_frame_gestures_count(leap_frame_ref frame)
{
    return frame->gestures.size();
}

leap_gesture_ref leap_frame_gesture_at_index(leap_frame_ref frame, int index)
{
    return frame->gestures[index];
}

int leap_frame_is_valid(leap_frame_ref frame)
{
    return W(frame).isValid();
}

int leap_frame_equal(leap_frame_ref frame, leap_frame_ref other)
{
    return W(frame) == W(other);
}

Leap::Frame const& from_frame(leap_frame_ref frame)
{
    return W(frame);
}
