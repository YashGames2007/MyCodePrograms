# classic/Static Method
def grid_Traveler(m, n):
    if m <= 0 or n <= 0:
        return 0
    elif m == 1 and n == 1:
        return 1
    else:
        return grid_Traveler((m - 1), n) + grid_Traveler(m, (n - 1))

# Advanced/Dynamic Method:
def grid_Traveler_Dynamic(m, n, memo = {}):
    if ((f"{m},{n}") in memo):
        return memo[(f"{m},{n}")]
    elif ((f"{n},{m}") in memo):
        return memo[(f"{n},{m}")]
    elif (m <= 0 or n <= 0):
        return 0
    elif (m == 1 and n == 1):
        return 1
    else :
        memo[(f"{m},{n}")] = grid_Traveler_Dynamic((m - 1), n, memo) + grid_Traveler_Dynamic(m, (n - 1), memo)
        return memo[(f"{m},{n}")]


print(grid_Traveler_Dynamic(1, 1))
print(grid_Traveler_Dynamic(7, 5))
print(grid_Traveler_Dynamic(100, 100))