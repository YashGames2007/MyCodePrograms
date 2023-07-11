"""
Module DocString
"""
#^ Coding Habit Development: Day 11 | 01 Apr 2023

#* Name of the Problem  : Crowded Carriage Capacity
#. Link to the Question : https://edabit.com/challenge/XfSvKco6KZFRfgQyj
## Problem Description  : A train has a maximum capacity of n passengers overall, which means each
##                        carriage's capacity will share an equal proportion of the maximum capacity
##                        Create a function which returns the index of the first carriage which
##                        holds 50% or less of it's maximum capacity. If no such carriage exists,
##                        return -1.

import code_tester

test_cases = []

test_cases.append(
    {
        "input": {
            "n": 200,
            "lst": [35, 23, 18, 10, 40]
        },
        "output": 2
    }
)
test_cases.append(
    {
        "input": {
            "n": 20,
            "lst": [3, 5, 4, 2]
        },
        "output": 3
    }
)
test_cases.append(
    {
        "input": {
            "n": 1000,
            "lst": [50, 20, 80, 90, 100, 60, 30, 50, 80, 60]
        },
        "output": 0
    }
)
test_cases.append(
    {
        "input": {
            "n": 200,
            "lst": [35, 23, 40, 21, 38]
        },
        "output": -1
    }
)

def find_a_seat(n:int, lst:list) -> int:

    """
    Function DocString
    """
    max_cap = n // len(lst)

    for index, carriage in enumerate(lst):
        if carriage <= max_cap / 2:
            return index
    return -1

code_tester.test(find_a_seat, test_cases)
