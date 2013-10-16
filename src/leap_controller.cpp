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

#include <assert.h>

#include "Leap.h"
#include "leap_utils.hpp"
#include "leap_frame_private.hpp"
#include "leap_controller.h"

struct leap_controller
{
    leap_controller() : wrap() {}
    Leap::Controller wrap;
};

class Listener : public Leap::Listener
{
public:
    Listener(struct leap_controller_callbacks const& callbacks, void* user_info)
    	: _callbacks(callbacks)
    	, _user_info(user_info)
    	, _controller(0)
    {}

    leap_controller_ref getController() const {
        return _controller;
    }

    void setController(leap_controller_ref controller) {
        _controller = controller;
    }

    virtual void onInit(Leap::Controller const& controller) {
        if (_callbacks.on_init != NULL) {
            _callbacks.on_init(_controller, _user_info);
        }
    }

    virtual void onConnect(Leap::Controller const& controller) {
        if (_callbacks.on_connect != NULL) {
            _callbacks.on_connect(_controller, _user_info);
        }
    }

    virtual void onDisconnect(Leap::Controller const& controller) {
        if (_callbacks.on_disconnect != NULL) {
            _callbacks.on_disconnect(_controller, _user_info);
        }
    }

    virtual void onExit(Leap::Controller const& controller) {
        if (_callbacks.on_exit != NULL) {
            _callbacks.on_exit(_controller, _user_info);
        }
    }

    virtual void onFrame(Leap::Controller const& controller) {
        if (_callbacks.on_frame != NULL) {
            _callbacks.on_frame(_controller, _user_info);
        }
    }

private:
    struct leap_controller_callbacks _callbacks;
    void* const _user_info;
    leap_controller_ref _controller;
};

struct leap_listener
{
    leap_listener(struct leap_controller_callbacks const& callbacks, void* user_info)
    	: wrap(callbacks, user_info) {}
    Listener wrap;
};

leap_controller_ref leap_controller_new()
{
    return new leap_controller();
}

void leap_controller_delete(leap_controller_ref controller)
{
    delete controller;
}

int leap_controller_is_connected(leap_controller_ref controller)
{
    return W(controller).isConnected();
}

leap_frame_ref leap_controller_copy_frame(leap_controller_ref controller, int history)
{
    Leap::Frame const frame = W(controller).frame(history);
    return leap_frame_copy(frame);
}

leap_controller_policy_flag leap_controller_policy_get_flags(leap_controller_ref controller)
{
    return (leap_controller_policy_flag)W(controller).policyFlags();
}

void leap_controller_policy_set_flags(leap_controller_ref controller, leap_controller_policy_flag flags)
{
    W(controller).setPolicyFlags((Leap::Controller::PolicyFlag)flags);
}

void leap_controller_add_listener(leap_controller_ref controller, leap_listener_ref listener)
{
    assert(W(listener).getController() == 0);
    W(listener).setController(controller);
    W(controller).addListener(W(listener));
}

void leap_controller_remove_listener(leap_controller_ref controller, leap_listener_ref listener)
{
    assert(W(listener).getController() != 0);
    W(controller).removeListener(W(listener));
    W(listener).setController(0);
}

void leap_controller_enable_gesture(leap_controller_ref controller, leap_gesture_type gesture_type, int should_enable)
{
    W(controller).enableGesture(Leap::Gesture::Type(gesture_type), should_enable != 0);
}

int leap_controller_is_gesture_enabled(leap_controller_ref controller, leap_gesture_type gesture_type)
{
    return W(controller).isGestureEnabled(Leap::Gesture::Type(gesture_type));
}

leap_listener_ref leap_listener_new(struct leap_controller_callbacks* callbacks, void *user_data)
{
    return new leap_listener(*callbacks, user_data);
}

void leap_listener_delete(leap_listener_ref listener)
{
    delete listener;
}
