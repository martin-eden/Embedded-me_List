# What

(2024-05 .. 2024-06)

Stack and queue implementation via singly linked list. Arduino (AVR).

## Requirements

  * arduino-cli
  * bash


## Install

Run [Install.sh](Install.sh).


## Remove

Run [Remove.sh](Remove.sh).


# Compile

Zero-warnings compilation:

```bash
arduino-cli compile --fqbn arduino:avr:uno --quiet --warnings all . --build-property compiler.cpp.extra_flags="-std=c++1z"
```

# Code

* [Example](examples/me_List/me_List.ino)
* [Interface](src/me_List.h)
* [Implementation](src/me_List.cpp)


# See also

* [My other repositories](https://github.com/martin-eden/contents)
