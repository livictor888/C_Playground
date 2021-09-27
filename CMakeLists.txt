cmake_minimum_required(VERSION 3.20)
project(C_Playground C)

set(CMAKE_C_STANDARD 99)

add_executable(C_Playground main.c)

add_executable(sept20_check_valid_password ./comp2510/sept20_check_valid_password.c)
add_executable(sept20_get_first_nonrepeated_characte ./comp2510/sept20_get_first_nonrepeated_character.c)
add_executable(sept20_print_string_backwards ./comp2510/sept20_print_string_backwards.c)




add_executable(testFile "comp2510/Week 3 Sept 27 Youtube.c")
add_executable(string_backwards "./comp2510/Week 3 reverse string recursive.c")