"""
Module DocString
"""
#^ Coding Habit Development: Day 3 | 21 Mar 2023

#* Name of the Problem  : Flip the Boolean
#. Link to the Question : https://edabit.com/challenge/NLY7zGMYocsTbeS6n
## Problem Description  : Create a function that reverses a boolean value and returns the
##                        string "boolean expected" if another variable type is given.

import code_tester

test_cases = []

test_cases.append(
    {
        "input": {
            "boolean": False
        },
        "output": True
    }
)
test_cases.append(
    {
        "input": {
            "boolean": True
        },
        "output": False
    }
)
test_cases.append(
    {
        "input": {
            "boolean": 0
        },
        "output": "boolean expected"
    }
)
test_cases.append(
    {
        "input": {
            "boolean": None
        },
        "output": "boolean expected"
    }
)

def reverse(boolean:bool) -> bool | str:

    """
    Function DocString
    """
    result = boolean

    if isinstance(boolean, bool):
        result = not boolean
    else:
        result = "boolean expected"

    return result

code_tester.test(reverse, test_cases)
