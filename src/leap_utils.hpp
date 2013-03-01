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

#ifndef LeapC_leap_utils_hpp
#define LeapC_leap_utils_hpp

#include "leap_types.h"

#define W(o) (o->wrap)

inline
Leap::Vector from_vector(leap_vector const vector)
{
    return Leap::Vector(vector.x, vector.y, vector.z);
}

inline
leap_vector to_vector(Leap::Vector const& vector)
{
    return (leap_vector){
        vector.x,
        vector.y,
        vector.z
    };
}

#endif
