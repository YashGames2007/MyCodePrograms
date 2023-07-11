"""
Module DocString
"""
#^ Coding Habit Development: Day 2 | 19 Mar 2023

#* Name of the Problem  : Convert a Number to Base-2
#. Link to the Question : https://edabit.com/challenge/2hsyXkzDRewGSPpPE
## Problem Description  : Create a function that returns a base-2 (binary) representation of a
##                        base-10 (decimal) string number. To convert is simple: ((2) means base-2
## and (10) means base-10) 010101001(2) = 1 + 8 + 32 + 128. Going from right to left, the value
## of the most right bit is 1, now from that every bit to the left will be x2 the value of an 8 bit
## binary numbers are (256, 128, 64, 32, 16, 8, 4, 2, 1).

import code_tester

test_cases = []

test_cases.append(
    {
        "input": {
            "decimal": 1
        },
        "output": "1"
    }
)
test_cases.append(
    {
        "input": {
            "decimal": 5
        },
        "output": "101"
    }
)
test_cases.append(
    {
        "input": {
            "decimal": 10
        },
        "output": "1010"
    }
)

def binary(decimal:int) -> str:

    """
    Function DocString
    """

    _binary = ""
    num = decimal

    while num != 0:
        _binary += str(num % 2)
        num = int(num / 2)
    return _binary[::-1]

code_tester.test(binary, test_cases)
