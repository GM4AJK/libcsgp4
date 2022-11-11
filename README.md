
![Build Status](https://github.com/GM4AJK/libcsgp4/actions/workflows/cmake.yml/badge.svg?event=push)

# SGP4 library

This library is derived from/forked off [Danial Warner's sgp4 library](https://github.com/dnwrnr/sgp4).

Changes include:-

* Use of "csgp4" namespace for all objects, methods and functions
* Added the ability to create a TLE from raw args where the Epoch is defined by ISO8601 as used by Celestrak JSON
* Added Unit Test suite
* Added Github Unit Test build actions


## License


    Copyright 2017 Daniel Warner
    Copyright 2022 Andy Kirkham

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
    