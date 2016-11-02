CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

PROJECT(TeaGame CXX)

#Sets which kind of windows target you want.
#x32 or x64 for the different architectures.
#e.g SET(WINDOWS_TARGET "x32")
SET(WINDOWS_TARGET "x64")

ADD_SUBDIRECTORY("tea")
ADD_SUBDIRECTORY("game")

