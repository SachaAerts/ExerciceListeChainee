cmake_minimum_required(VERSION 3.29)
project(Exo2 C)

set(CMAKE_C_STANDARD 90)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c90 -Wpedantic -Wall -Werror")

set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -std=c90 -Wpedantic -Wall -Werror")

set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -std=c90 -Wpedantic -Wall -Werror")

add_executable(Exo2 main.c
        library.c
        library.h)
