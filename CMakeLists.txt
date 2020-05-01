cmake_minimum_required(VERSION 3.15)
project(Nameless)

set(CMAKE_CXX_STANDARD 14)

add_executable(Nameless
        main.cpp tools/fixedpool.h)
