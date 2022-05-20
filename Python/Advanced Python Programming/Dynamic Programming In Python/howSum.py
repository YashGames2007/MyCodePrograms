# Classic/Static Method:
def howSum_Static(targetSum, numbers):
    if targetSum == 0:
        return []
    if targetSum < 0:
        return None
    for number in numbers:
        remainder = targetSum - number
        remainder_Result = howSum_Static(remainder, numbers)
        if remainder_Result != None:
            remainder_Result.append(number)
            return remainder_Result
    return None
  
# Advanced/Dynamic Method:
def howSum_Dynamic(targetSum, numbers, memo = {}, recursion = 0):
    if recursion == 0:
        memo = {}
        recursion = 1
    if targetSum in memo:
        return memo[targetSum]
    if targetSum == 0:
        return []
    if targetSum < 0:
        return None
    for number in numbers:
        remainder = targetSum - number
        remainder_Result = howSum_Dynamic(remainder, numbers, memo, recursion)
        if remainder_Result != None:
            remainder_Result.append(number)
            memo[targetSum] = remainder_Result
            return memo[targetSum]
    memo[targetSum] = None
    return None
    
                                       # Answers
print(howSum_Dynamic(7, [2, 3]))       # [3, 2, 2]
print(howSum_Dynamic(7, [5, 3, 4, 7])) # [4, 3]
print(howSum_Dynamic(7, [2, 4]))       # None
print(howSum_Dynamic(8, [2, 3, 5]))    # [2, 2, 2, 2]
print(howSum_Dynamic(300, [7, 14]))    # None