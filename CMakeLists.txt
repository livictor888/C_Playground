cmake_minimum_required(VERSION 3.20)
project(C_Playground C)

set(CMAKE_C_STANDARD 99)

add_executable(C_Playground main.c)

add_executable(lab1 comp2510/Lab_Week_2.c)
add_executable(lab3 comp2510/Lab_Week_3.c)

add_executable(check_valid_password comp2510/Week_2_sept20_check_valid_password.c)
add_executable(get_first_nonrepeated_characte comp2510/Week_2_sept20_get_first_nonrepeated_character.c)
add_executable(print_string_backwards comp2510/Week_2_sept20_print_string_backwards.c)
add_executable(Week_3_Youtube "comp2510/Week_3_Sept 27_Youtube.c")
add_executable(GCD "comp2510/Week_3_GCD.c")
add_executable(remove_A "comp2510/Week_3_remove_A_recursive.c")
add_executable(double_A "comp2510/Week_3_Double_A_Recursive.c")
add_executable(string_backwards "comp2510/Week_3_reverse_string_recursive.c")