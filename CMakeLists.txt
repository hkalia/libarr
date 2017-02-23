cmake_minimum_required(VERSION 3.6)
project(libarr)

set(CMAKE_C_STANDARD 90)

include_directories(includes)
file(GLOB SOURCE_FILES "srcs/*")
add_library(libarr ${SOURCE_FILES})
add_executable(libtest libtest.c)
target_link_libraries(libtest libarr)