cmake_minimum_required(VERSION 4.2)
project(dsa-c C)

set(CMAKE_C_STANDARD 11)

add_executable(dsa-c src/main.c
        include/constants.h
        src/data_structures/stack.c
        include/stack.h
        src/leetcode/020_valid_parentheses/solution.c
)
