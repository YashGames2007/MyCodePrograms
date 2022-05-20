# classic/Static Method:
def canSum_Static(targetSum, numbers):
    if targetSum == 0:
        return True
    if targetSum < 0:
        return False
    if 1 in numbers:
        return True
    
    for n in numbers:
        if canSum_Static((targetSum - n), numbers):
            return True
    return False

# Advanced/Dynamic Method:
def canSum_Dynamic(targetSum, numbers, memo = {}, recursion = 0):
    if recursion == 0:
        memo = {}
        recursion = 1
    if targetSum in memo:
        return memo[targetSum]
    if targetSum == 0:
        return True
    if targetSum < 0:
        return False
    if 1 in numbers:
        return True
    
    for n in range(len(numbers)):
        if (canSum_Dynamic((targetSum - numbers[n]), numbers, memo, recursion) == True):
            memo[targetSum] = True
            return True
    memo[targetSum] = False
    return False

                                       # Answers
print(canSum_Dynamic(7, [2, 3]))       # True
print(canSum_Dynamic(7, [5, 3, 4, 7])) # True
print(canSum_Dynamic(7, [2, 4]))       # False
print(canSum_Dynamic(8, [2, 3, 5]))    # True
print(canSum_Dynamic(300, [7, 14]))    # False