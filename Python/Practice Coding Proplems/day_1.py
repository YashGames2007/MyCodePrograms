"""
Module DocString
"""
#^ Coding Habit Development: Day 1 | 18 Mar 2023

#* Name of the Problem  : Radians to Degrees
#. Link to the Question : https://edabit.com/challenge/2X2uZysLJ3CpsxLDD
## Problem Description  : Create a function that takes an angle in radians and returns the
##                        corresponding angle in degrees rounded to one decimal place.

import code_tester

test_cases = []

test_cases.append(
    {
        "input": {
            "radians": 1
        },
        "output": 57.3
    }
)
test_cases.append(
    {
        "input": {
            "radians": 20
        },
        "output": 1145.9
    }
)
test_cases.append(
    {
        "input": {
            "radians": 50
        },
        "output": 2864.8
    }
)
def radians_to_degrees(radians:float) -> float:

    """
    Function DocString
    """
    import math

    return round(radians * (180/math.pi), 1)

code_tester.test(radians_to_degrees, test_cases)
