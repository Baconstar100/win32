cmake_minimum_required(VERSION 3.26)
project(testing C)

set(CMAKE_C_STANDARD 11)

add_executable(testing WIN32 main.c
        x_window.h
        colors.h
        standard.h
        resource.h
        colors.rc)