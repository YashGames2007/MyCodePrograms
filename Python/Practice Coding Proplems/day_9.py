"""
Module DocString
"""
#^ Coding Habit Development: Day 9 | 30 Mar 2023

#* Name of the Problem  : Robot Path
#. Link to the Question : https://edabit.com/challenge/towwrEJ7z8xKGSr5
## Problem Description  : Someone created a simple robot that is navigated by a series of North,
##                        East, South, and West [n, e, s, w] commands. Each command moves the robot
##                        one step in the given direction. The robot is designed for only two
##                        destinations: 1: [e, n, e, e, n], 2: [w, n, w, n, w, w, n]
##                        Create a function that takes a list of commands and returns True if the
##                        robot reaches any of the destinations, False otherwise.

import code_tester

test_cases = []

test_cases.append(
    {
        "input": {
            "commands": ["s", "e", "e", "n", "n", "e", "n"]
        },
        "output": True
    }
)
test_cases.append(
    {
        "input": {
            "commands": ["n", "e", "s", "w", "n", "e", "s", "w", "w", "s", "n", "e"]
        },
        "output": False
    }
)
test_cases.append(
    {
        "input": {
            "commands": ["n", "s", "n", "n", "e", "n", "w", "w", "s", "w", "w", "w", "n"]
        },
        "output": True
    }
)

#    N
# W  +  E
#    S

def robot_path(commands: list[str]) -> bool:

    """
    Function DocString
    """
    required_dest = [[3, 2], [-4, 3]]
    x_pos, y_pos = 0, 0      # Position of the robot

    for command in commands:
        if command == "n":
            y_pos += 1
        elif command == "e":
            x_pos += 1
        elif command == "s":
            y_pos -= 1
        elif command == "w":
            x_pos -= 1

    if [x_pos, y_pos] in required_dest:
        return True
    return False

code_tester.test(robot_path, test_cases)
