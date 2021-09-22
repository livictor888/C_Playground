cmake_minimum_required(VERSION 3.20)
project(C_Playground C)

set(CMAKE_C_STANDARD 99)

add_executable(C_Playground main.c)
add_executable(comp2510_test2 ./comp2510/test2.c)
add_executable(comp2510_test1 ./comp2510/test.c)

add_executable(comp2510_lab3 ./comp2510/lab3.c)