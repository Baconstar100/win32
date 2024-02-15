cmake_minimum_required(VERSION 3.6.2)
project(testing C)

set(CMAKE_C_STANDARD 11)

add_executable(testing WIN32 main.c
        src/x_window.h
        src/colors.h
        src/standard.h
        src/resource.h)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT testing)