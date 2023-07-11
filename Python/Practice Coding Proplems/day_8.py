"""
Module DocString
"""
#^ Coding Habit Development: Day 8 | 26 Mar 2023

#* Name of the Problem  : Sum of v0w3ls
#. Link to the Question : https://edabit.com/challenge/6NoaFGKJgRW6oXhLC
## Problem Description  : Create a function that takes a string and returns the sum of vowels,
##                        where some vowels are considered numbers.
##                        A - 4, E - 3, I - 1, O - 0, U - 0

import code_tester

test_cases = []

test_cases.append(
    {
        "input": {
            "string": "Let\'s test this function."
        },
        "output": 8
    }
)
test_cases.append(
    {
        "input": {
            "string": "Do I get the correct output?"
        },
        "output": 10
    }
)
test_cases.append(
    {
        "input": {
            "string": "I love edabit!"
        },
        "output": 12
    }
)

def sum_of_vowels(string:str) -> int:

    """
    Function DocString
    """
    
    codes = {
        "A": 4, "a": 4,
        "E": 3, "e": 3,
        "I": 1, "i": 1,
        "O": 0, "o": 0,
        "U": 0, "u": 0
    }
    _sum = 0

    for character in string:
        if character in codes:
            _sum += codes[character]
    
    return _sum

code_tester.test(sum_of_vowels, test_cases)
