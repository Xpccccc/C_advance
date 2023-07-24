cmake_minimum_required(VERSION 3.25)
project(contact_dynamic C)

set(CMAKE_C_STANDARD 11)

add_executable(contact_dynamic main.c contact.c contact.h)
