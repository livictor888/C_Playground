cmake_minimum_required(VERSION 3.20)
project(C_Playground C)

set(CMAKE_C_STANDARD 99)

include_directories(includes/2510Nhan)

add_executable(C_Playground main.c)
add_executable(A1 comp2510/Assignment_1.c comp2510/Assignment_4v2.c)
add_executable(A2 comp2510/Assignment_2.c)
add_executable(A3 comp2510/Assignment_3.c)
add_executable(A4 comp2510/Assignment_4.c)
add_executable(A4v2 comp2510/Assignment_4v2.c)

add_executable(lab1 comp2510/Lab_Week_2.c)
add_executable(lab3 comp2510/Lab_Week_3.c)
add_executable(lab4 comp2510/Lab_Week_4.c)
add_executable(lab4_r comp2510/Lab_Week_4_Recursive.c)
add_executable(lab5 comp2510/Lab_Week_5.c)
add_executable(lab6 comp2510/Lab_Week_6.c)
add_executable(lab8 comp2510/Lab_Week_8.c)
add_executable(lab10 comp2510/Lab_Week_10.c)
add_executable(lab11 comp2510/Lab_Week_11.c)
add_executable(lab12 comp2510/Lab_Week_12.c)
add_executable(lab13 comp2510/Lab_Week_13.c)

add_executable(check_valid_password comp2510/Week_2_sept20_check_valid_password.c)
add_executable(get_first_nonrepeated_character comp2510/Week_2_sept20_get_first_nonrepeated_character.c)
add_executable(print_string_backwards comp2510/Week_2_sept20_print_string_backwards.c)
add_executable(Week_3_Youtube "comp2510/Week_3_Sept 27_Youtube.c")
add_executable(GCD "comp2510/Week_3_GCD.c")
add_executable(remove_A "comp2510/Week_3_remove_A_recursive.c")
add_executable(double_A "comp2510/Week_3_Double_A_Recursive.c")
add_executable(string_backwards "comp2510/Week_3_reverse_string_recursive.c")
add_executable(recursive "comp2510/Week_3_Recursive_Functions.c")
add_executable(odd_Numbers "comp2510/Week_3_Get_Odd_Numbers_Recursive.c")
add_executable(max_element "comp2510/Week_3_max_element_recursive.c")
add_executable(Error_handling comp2510/Week_4_Error_Handling.c)
add_executable(week_6_anagram comp2510/Week_6_Anagrams.c)
add_executable(week_8_max_struc comp2510/Week_8_Max_Struc.c)
add_executable(week_8_arrow comp2510/Week_8_Arrow_Notation.c)
add_executable(week_8_date comp2510/Week_8_Date_Exercise.c)
add_executable(week_8_macro comp2510/Week_8_Macro.c)
add_executable(week_8_macro_p comp2510/Week_8_Macro_Parenthesis.c)
add_executable(week_8_dynamic_memory comp2510/Week_8_Dynamic_Memory_Allocation.c)
add_executable(week_11_function_pointer comp2510/Week_11_Function_Pointer_Easy.c)
add_executable(week_11_generic_function comp2510/Week_11_Generic_Function_Medium.c)
add_executable(week_12_linked_list comp2510/Week_12_Linked_Lists.c)
add_executable(week_12_LL_Complete comp2510/Week_12_Linked_List_Complete.c)
add_executable(week_12_filter comp2510/Week_12_Lecture.c)
add_executable(week_12_split comp2510/Week_12_Linked_List_Split.c)
add_executable(week_13_BST comp2510/Week_13_Binary_Search_Tree.c)


add_executable(quiz1 comp2510/Q1.c)
add_executable(quiz1x comp2510/Q1X.c)
add_executable(quiz1y comp2510/Q1Y.c)
add_executable(quiz1z comp2510/Q1Z.c)
add_executable(quiz_1 comp2510/Quiz_1.c)
add_executable(quiz2a comp2510/Q2a.c)
add_executable(quiz2 comp2510/Q2.c)
add_executable(q3 comp2510/Q3.c)
add_executable(quiz3 comp2510/Quiz_3.c)
add_executable(quiz4 comp2510/Quiz_4.c)

add_executable(reverse_string comp2510/Interview_Reverse_String.c)
add_executable(optimize_code comp2510/Interview_Optimize_Code.c)

add_executable(append comp2510/Extra_Append.c)