cmake_minimum_required(VERSION 3.22)

# Top level CMake script for building KNOTS project.
# Author: Igor Lesik 2024

project(KNOTS
    VERSION 0.1.0
    DESCRIPTION "Knowledge DB"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(C_WARN_FLAGS  "-Wall -Wextra -Werror")
set(C_BUILD_FLAGS "-fpic -pipe")
set(C_OPT_FLAGS   "-march=native -ftree-vectorize -fprefetch-loop-arrays")

set(CMAKE_CXX_FLAGS                  "-O3 ${C_WARN_FLAGS} ${C_OPT_FLAGS} ${C_BUILD_FLAGS}")
set(CMAKE_CXX_FLAGS_DEBUG            "-O2 -g ${C_WARN_FLAGS} ${C_OPT_FLAGS}${C_BUILD_FLAGS}")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO   "-O3 -g -flto ${C_WARN_FLAGS} ${C_OPT_FLAGS} ${C_BUILD_FLAGS}")
set(CMAKE_CXX_FLAGS_RELEASE          "-O3 -flto -DNDEBUG ${C_WARN_FLAGS}${C_OPT_FLAGS} ${C_BUILD_FLAGS}")

# Install inside the build directory.
set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/install)

include_directories(.)
include_directories(${PROJECT_SOURCE_DIR}/third-party)

include(third-party/cli11.cmake)
include(third-party/inja.cmake)
include(third-party/json.cmake)
#include(third-party/rapidyaml.cmake)
#include(third-party/termcolor.cmake)

add_subdirectory(kno)
