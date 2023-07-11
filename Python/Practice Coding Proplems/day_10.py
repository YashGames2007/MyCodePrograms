"""
Module DocString
"""
#^ Coding Habit Development: Day 10 | 31 Mar 2023

#* Name of the Problem  : Three Lists!
#. Link to the Question : https://edabit.com/challenge/GQjKJtG6dqeyBSCqX
## Problem Description  : Given three lists of integers: lst1, lst2, lst3, return the sum of
##                        integers which are common in all three lists.

import code_tester

test_cases = []

test_cases.append(
    {
        "input": {
            "lst1": [1, 2, 3],
            "lst2": [5, 3, 2],
            "lst3": [7, 3, 2]
        },
        "output": 5
    }
)
test_cases.append(
    {
        "input": {
            "lst1": [1, 2, 2, 3],
            "lst2": [5, 3, 2, 2],
            "lst3": [7, 3, 2, 2]
        },
        "output": 7
    }
)
test_cases.append(
    {
        "input": {
            "lst1": [1],
            "lst2": [1],
            "lst3": [2]
        },
        "output": 0
    }
)

def sum_common(lst1:list, lst2:list, lst3:list) -> int:

    """
    Function DocString
    """
    _sum = 0
    for element in lst1:
        if element in lst2 and element in lst3:
            _sum += element
            lst2.remove(element)
            lst3.remove(element)
    return _sum
    

code_tester.test(sum_common, test_cases)
