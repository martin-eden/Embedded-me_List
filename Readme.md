# What

(2024-05 .. 2024-06)

Stack and queue implementation via singly linked list. Arduino (AVR).

## Requirements

  * arduino-cli
  * bash


## Install/remove

Easy way is to clone [GetLibs][GetLibs] repo and run it's code.


# Compile

Zero-warnings compilation:

```bash
arduino-cli compile --fqbn arduino:avr:uno --quiet --warnings all . --build-property compiler.cpp.extra_flags="-std=c++1z"
```

## Code

* [Example][Example]
* [Interface][Interface]
* [Implementation][Implementation]


# See also

* [My other repositories](https://github.com/martin-eden/contents)

[Example]: examples/me_List/me_List.ino
[Interface]: src/me_List.h
[Implementation]: src/me_List.cpp

[GetLibs]: https://github.com/martin-eden/Embedded-Framework-GetLibs

[Embedded]: https://github.com/martin-eden/Embedded_Crafts/tree/master/Parts
[Repos]: https://github.com/martin-eden/contents
