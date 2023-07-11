"""
Module DocString
"""
#^ Coding Habit Development: Day 13 | 04 Apr 2023

#* Name of the Problem  : Mini Sudoku
#. Link to the Question : https://edabit.com/challenge/hC6yGEPvtN2izt3c9
## Problem Description  : Create a function that checks to make sure that a 3x3 square contains each
##                        number from 1-9 exactly once. Make sure these are no duplicates, and no
##                        numbers outside this range.

import code_tester

test_cases = []

test_cases.append(
    {
        "input": {
            "lst": [[1, 3, 2], [9, 7, 8], [4, 5, 6]]
        },
        "output": True
    }
)
test_cases.append(
    {
        "input": {
            "lst": [[1, 1, 3], [6, 5, 4], [8, 7, 9]]
        },
        "output": False
    }
)
test_cases.append(
    {
        "input": {
            "lst": [[0, 1, 2], [6, 4, 5], [9, 8, 7]]
        },
        "output": False
    }
)
test_cases.append(
    {
        "input": {
            "lst": [[8, 9, 2], [5, 6, 1], [3, 7, 4]]
        },
        "output": True
    }
)

def is_mini_sudoku(lst:list) -> bool:

    """
    Function DocString
    """
    possible_values = [i for i in range(1, 10)]
    
    for row in lst:
        for no in row:
            if no in possible_values:
                possible_values.remove(no)
            else:
                return False
    
    return True
    

code_tester.test(is_mini_sudoku, test_cases)
