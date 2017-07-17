cmake_minimum_required(VERSION 2.8)
project(cpp-smart-pointers)

find_package(Threads)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)
set(CMAKE_BUILD_TYPE Release)

add_compile_options(-std=c++14 -Wall)

file(
    GLOB
    sources
    src/*
)

include_directories(includes)

add_executable(
    cpp-smart-pointers
    ${sources}
)

target_link_libraries(cpp-smart-pointers ${CMAKE_THREAD_LIBS_INIT})
