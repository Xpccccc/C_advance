cmake_minimum_required(VERSION 3.25)
project(demo_01 C)

set(CMAKE_C_STANDARD 11)

add_executable(demo_01 main.c Heap.h Heap.c)
