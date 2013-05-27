# C wrapper around the Leap Motion library


## Overview

This is a work in progress, although well advanced and stable enough to be used in any application.

The LeapC library is a C wrapper around the C++ Leap Motion library.  This wrapper is made so that integration with other languages is compatible, efficient, and easy to understand.  It is written "manually" in contrast to automatically generated wrappers like SWIG, hence the readable and concise result.

It does not cover the entire Leap Motion API, limitations are:

- At this moment, there is no distinction between `Fingers` and `Tools`, therefore only `Pointables` are implemented.
- "find by id" methods are not implemented yet.
- `Pointables` are available only through their associated `Hands` (not through their `Frame`).
- Xcode project only, though it should be fairly easy to port the project to Visual Studio and the code is vanilla C, let me know if you need it.
- Utilities from the LeapMath library are not implemented, and might never be.


## Installation and Usage

1. Clone the repository.
2. Copy or make a symbolic link from your LeapSDK directory into the `./vendor/` sub-directory so that you have ./vendor/LeapSDK/ (a symlink is preferred to deal with updates to the Leap library).
3. Take a look at the example, it should be fairly easy to understand how to set-up the callbacks.


## Feedback and suggestions

Feel free to open a ticket or to send me an email <camille@osculator.net>.


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
