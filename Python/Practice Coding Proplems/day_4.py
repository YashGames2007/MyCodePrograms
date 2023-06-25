"""
Module DocString
"""
#^ Coding Habit Development: Day 4 | 22 Mar 2023

#* Name of the Problem  : Is the String in Order?
#. Link to the Question : https://edabit.com/challenge/EFwDXErjDywXp56WG
## Problem Description  : Create a function that takes a string and return True or False, depending
##                        on the whether the characters are in order or not.

import code_tester

test_cases = []

test_cases.append(
    {
        "input": {
            "string": "abc"
        },
        "output": True
    }
)
test_cases.append(
    {
        "input": {
            "string": "edabit"
        },
        "output": False
    }
)
test_cases.append(
    {
        "input": {
            "string": "123"
        },
        "output": True
    }
)
test_cases.append(
    {
        "input": {
            "string": "xyzz"
        },
        "output": True
    }
)

def is_in_order(string:str) -> bool:

    """
    Function DocString
    """
    result = True
    previous = ord(string[0])

    for i in range(1, (len(string) - 1)):
        if ord(string[i]) < previous:
            result = False
            break
        else:
            previous = ord(string[i])
    return result
    

code_tester.test(is_in_order, test_cases)
