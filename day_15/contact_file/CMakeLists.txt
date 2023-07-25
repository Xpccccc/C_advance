cmake_minimum_required(VERSION 3.25)
project(contact_file C)

set(CMAKE_C_STANDARD 11)

add_executable(contact_file main.c contact.c contact.h)
