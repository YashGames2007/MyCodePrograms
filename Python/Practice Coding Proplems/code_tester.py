 #^ Coding Habit Development: Day 0 | 17 Mar 2023
"""
Python Practice Coding Problem Function Tester
"""

def test(function, test_cases):
    """
    Function Tester Based on Input & Output.
    """
    results = []
    print("\nTesting Function...\n")
    for i, case in enumerate(test_cases):
        _input = ', '.join([str(x) for x in case["input"].values()])
        exp_output = case["output"]
        _output = function(**case["input"])
        result = 'PASSED' if exp_output == _output else 'FAILED'
        results.append(result)

        print(f"Test No. {i+1}:")
        print(f"Function Input  : {_input}")
        print(f"Expected Output : {exp_output}")
        print(f"Actual   Output : {_output}")
        print(f"Test   Result   : {result}")
        print("\n")

    failed_cases = results.count("FAILED")
    result = "PASSED" if failed_cases == 0 else "FAILED"

    for i in range(len(test_cases)):
        print(f"Test Case #{i+1}: {results[i]}")
    print("\n::: Final Result :::")
    print(f"Total   Test Cases  : {len(test_cases)}")
    print(f"Passed  Test Cases  : {len(test_cases) - failed_cases}")
    print(f"Failed  Test Cases  : {failed_cases}")
    print(f"Overall Test Result : {result}")
