"""
Module DocString
"""
#^ Coding Habit Development: Day 5 | 23 Mar 2023

#* Name of the Problem  : Travelling Salesman Problem
#. Link to the Question : https://edabit.com/challenge/TcJXTPJBsfJ2Wgkk4
## Problem Description  : A salesman has a number of n to visit. He want to calculate the total
##                        number of possible paths he could take, visiting each city once before
##                        returning home. Return the total number of possible paths a salesman can
##                        travel, given n cities.

import code_tester

test_cases = []

test_cases.append(
    {
        "input": {
            "n": 4
        },
        "output": 24
    }
)
test_cases.append(
    {
        "input": {
            "n": 1
        },
        "output": 1
    }
)
test_cases.append(
    {
        "input": {
            "n": 9
        },
        "output": 362880
    }
)

def paths(n:int) -> int:

    """
    Function DocString
    """
    result = 1
    for i in range(1, n+1):
        result *= i
    
    return result

code_tester.test(paths, test_cases)
