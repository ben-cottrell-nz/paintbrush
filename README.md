# Paintbrush
A painting app written for fun and learning.
Written by Ben Cottrell.

## Dependancies
Qt 5/6 installation, CMake 3.21

## Building
Change `CMAKE_PREFIX_PATH` in CMakeLists.txt to the path 
of your Qt installation, and either use an IDE with CMake
invocation support, or build it yourself using:
```
cmake -B build .
cmake --build build -- -j6
```