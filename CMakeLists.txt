cmake_minimum_required(VERSION 4.2)
project(dsa-c C)

set(CMAKE_C_STANDARD 11)

add_executable(dsa-c src/main.c
        include/constants.h
        src/data_structures/stack.c
        include/stack.h
        src/leetcode/020_valid_parentheses/solution.c
        src/leetcode/1952_three_divisors/solution.c
        src/leetcode/169_majority_element/solution.c
        src/leetcode/067_add_binary/solution.c
        src/leetcode/217_contains_duplicate/solution.c
        src/leetcode/682_baseball_game/solution.c
        src/data_structures/matrix.c
        include/matrix.h
        src/_utils/constants.c
)
