cmake_minimum_required(VERSION 3.22)

project(the_universe
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(C_WARN_FLAGS  "-Wall -Wextra -Werror")
set(C_BUILD_FLAGS "-fpic")
set(C_OPT_FLAGS   "-march=native -ftree-vectorize")

set(CMAKE_CXX_FLAGS  "-O3 ${C_WARN_FLAGS} ${C_OPT_FLAGS} ${C_BUILD_FLAGS}")

include_directories(.)
include_directories(/home/lesikigor/prj/knots/build/../knots)

add_library(kb_the_universe SHARED
    the_universe.cpp
)
