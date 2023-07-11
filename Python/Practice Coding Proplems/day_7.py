"""
Module DocString
"""
#^ Coding Habit Development: Day 7 | 25 Mar 2023

#* Name of the Problem  : FizzBuzz Interview Question
#. Link to the Question : https://edabit.com/challenge/WXqH9qvvGkmx4dMvp
## Problem Description  : Create a function that takes a number as an argument and returns "Fizz" if
##                        it's a multiple of 3, "Buzz" if it's a multiple of 5, "FizzBuzz" if it's
##                        multiple of both 3 and 5, and return s the same number in string format if
##                        it's neither a multiple of 3 nor 5.

import code_tester

test_cases = []

test_cases.append(
    {
        "input": {
            "num": 3
        },
        "output": "Fizz"
    }
)
test_cases.append(
    {
        "input": {
            "num": 5
        },
        "output": "Buzz"
    }
)
test_cases.append(
    {
        "input": {
            "num": 15
        },
        "output": "FizzBuzz"
    }
)
test_cases.append(
    {
        "input": {
            "num": 4
        },
        "output": "4"
    }
)

def fizz_buzz(num:int) -> str:

    """
    Function DocString
    """
    
    if num % 15 == 0:
        return "FizzBuzz"
    elif num % 3 == 0:
        return "Fizz"
    elif num % 5 == 0:
        return "Buzz"
    else:
        return str(num)

code_tester.test(fizz_buzz, test_cases)
