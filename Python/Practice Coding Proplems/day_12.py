"""
Module DocString
"""
#^ Coding Habit Development: Day 12 | 02 Apr 2023

#* Name of the Problem  : Let's Talk Like a Monkey
#. Link to the Question : https://edabit.com/challenge/TAhuay457cw5AekBe
## Problem Description  : Create a function that takes a string txt and returns the string in monkey
##                        language. You have to figure out their language from test cases.

import code_tester

test_cases = []

test_cases.append(
    {
        "input": {
            "txt": "Mubashir Hassan"
        },
        "output": "Ook ook."
    }
)
test_cases.append(
    {
        "input": {
            "txt": "Hello"
        },
        "output": "Ook."
    }
)
test_cases.append(
    {
        "input": {
            "txt": "Matt"
        },
        "output": "Ook."
    }
)
test_cases.append(
    {
        "input": {
            "txt": "Everyone"
        },
        "output": "Eek."
    }
)
test_cases.append(
    {
        "input": {
            "txt": "Edabit is Amazing"
        },
        "output": "Eek eek eek."
    }
)

def monkey_talk(txt):

    """
    Function DocString
    """
    result = ""
    lst = txt.split(' ')
    vowels = ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']

    for word in lst:
        if word[0] in vowels:
            result += " eek"
        else:
            result += " ook"
    result += '.'
    result = result[1:]
    char = 'E' if result[0] == 'e' else 'O'
    result = char + result[1:]
    
    return result


code_tester.test(monkey_talk, test_cases)
