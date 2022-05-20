def func1 (a, b = 0):
    if (a == 1):
        a = 2
    if (b == 1):
        print(f'{(a * a) - (b * b)}, {2 * a * b}, {(a * a) + (b * b)}')    
    elif (b == 0):
        b = a - 1
        func1(a, b)
    else:
        print(f'{(a * a) - (b * b)}, {2 * a * b}, {(a * a) + (b * b)}')
        b = b - 1
        func1(a, b)

a = int(input("Type a Natural number for pythagorian triplet :- "))
func1 (a)

# print(f'Your Pythagorian triplet is {(a * a) - (b * b)}, {2 * a * b}, {(a * a) + (b * b)}.')