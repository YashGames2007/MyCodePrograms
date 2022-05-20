# classic/Static Method:
def fib_Static(n):
    if (n == 1 or n == 2):
        return 1
    else:
        return fib_Static(n - 1) + fib_Static(n - 2)

# Advanced/Dynamic Method:
def fib_Dynamic(n, memo = {}):
   if (n in memo):
       return memo[n]
   elif (n <= 2):
       return 1
   else :
       memo[n] = fib_Dynamic((n - 1), memo) + fib_Dynamic((n - 2), memo)
       return memo[n]
       
                        # Answers
print(fib_Dynamic(2))   # 1
print(fib_Dynamic(8))   # 21
print(fib_Dynamic(118)) # 2046711111473984623691759
