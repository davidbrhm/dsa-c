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
        src/data_structures/array.c
        include/array.h
        src/data_structures/regular_queue.c
        include/regular_queue.h
        src/leetcode/1700_number_of_students_unable_to_eat_lunch/solution.c
        src/data_structures/circular_queue.c
        include/circular_queue.h
        src/leetcode/622_design_circular_queue/solution.c
        src/data_structures/singly_linked_list.c
        include/singly_linked_list.h
        src/data_structures/doubly_linked_list.c
        include/doubly_linked_list.h
        src/leetcode/21_merge_two_sorted_lists/solution.c
        src/leetcode/206_reverse_linked_list/solution.c
        src/leetcode/234_palindrome_linked_list/solution.c
        include/list_node.h
)
