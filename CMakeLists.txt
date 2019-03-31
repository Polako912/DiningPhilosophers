cmake_minimum_required(VERSION 3.13)
project(Projekt1)

set(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_FLAGS "-pthread")

find_package(Threads REQUIRED)

add_executable(Projekt1 main.cpp Philosopher.cpp Philosopher.h)

target_link_libraries (Projekt1 ${CMAKE_THREAD_LIBS_INIT})