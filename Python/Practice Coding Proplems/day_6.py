"""
Module DocString
"""
#^ Coding Habit Development: Day 6 | 24 Mar 2023

#* Name of the Problem  : Likes vs. Dislikes
#. Link to the Question : https://edabit.com/challenge/egMp3GWyN8TPptbZA
## Problem Description  : YouTube currently displays a like and a dislike button, allowing you to
##                        express your opinions about particular content. It's set up in such a way
##                        that you cannot like and dislike a video at the same time.
##                        Hence create a function that takes in a list of button inputs and returns
##                        the final state.

import code_tester

test_cases = []

test_cases.append(
    {
        "input": {
            "button_inputs": ["Dislike"]
        },
        "output": "Dislike"
    }
)
test_cases.append(
    {
        "input": {
            "button_inputs": ["Like", "Like"]
        },          
        "output": "Nothing"
    }
)
test_cases.append(
    {
        "input": {
            "button_inputs": ["Dislike", "Like"]
        },
        "output": "Like"
    }
)
test_cases.append(
    {
        "input": {
            "button_inputs": ["Like", "Dislike", "Dislike"]
        },
        "output": "Nothing"
    }
)

def like_or_dislike(button_inputs: list[str]) -> str:

    """
    Function DocString
    """
    
    is_like = False
    is_dislike = False

    for _input in button_inputs:
        if _input == "Like":
            is_dislike = False
            is_like = not is_like

        elif _input == "Dislike":
            is_like = False
            is_dislike = not is_dislike
    
    if not is_like and not is_dislike:
        return "Nothing"

    return "Like" if is_like else "Dislike"

code_tester.test(like_or_dislike, test_cases)
