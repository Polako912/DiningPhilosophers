cmake_minimum_required(VERSION 3.13)
project(Projket1)

set(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_FLAGS "-pthread")

find_package(Threads REQUIRED)

add_executable(Projket1 main.cpp Philosopher.cpp Philosopher.h Fork.cpp Fork.h)

target_link_libraries (Projket1 ${CMAKE_THREAD_LIBS_INIT})