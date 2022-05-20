# # Find the gretest number of 4 numbers entered by the user
# a = int(input("type a first number:" ))
# b = int(input("type a second number:" ))
# c = int(input("type a third number:" ))
# d = int(input('type a fourth number:'))

# # if (a>b and a>c and a>d): 
# #     print("The Greatest number is:", a)
# # elif (b>a and b>c and b>d):
# #     print("The Greatest number is:", b)
# # elif (c>a and c>b and c>d):
# #     print("The Greatest number is:", c)
# # elif (d>a and d>b and d>c):
# #     print("The Greatest number is:", d)

# if (a > d):
#     f1 = a
# else:
#     f1 = d

# if (b > c):
#     f2 = b
# else:
#     f2 = c

# if (f1 > f2):
#     print("The Winnner is:", f1)
# else:
#     print("The Winner is:", f2)

# Write a program to find out whether a student is pass or fail, if it requires total 40% and at least 33% in each subject to pass. Assume 3 subjects and take marks as an input from the user

# sub1 = int(input( "type the mark of a subject: "))
# sub2 = int(input( "type the mark of a subject: "))
# sub3 = int(input( "type the mark of a subject: "))


# sub1_Percent = (sub1 / 100) * 100
# sub2_Percent = (sub2 / 100) * 100
# sub3_Percent = (sub3 / 100) * 100
# total_Percent = ((sub1 + sub2 + sub3) / 300) * 100

# if(sub1_Percent < 33 or sub2_Percent < 33 or sub3_Percent < 33):
#     print("Sorry! You Are Failed Due To Less Percentage in each Subject. Better Luck Next Time!")
# elif(total_Percent < 40):
#     print("Sorry! You Are Failed Due To Less Total Percentage in all Subjects. Better Luck Next Time!")
# else:
#     print("Congratulations! You are Passed The Test/Exam!")

# Write a python program to check whether a number taken from the user is less than 30 or not.

# a = int(input("type a number: "))
# if (a<30): 
#     print("The number is less than 30")
# elif (a>30):
#     print("the number is greater than 30")
# else:
#     print("the number is same")

# Write a python program to find the greater number and smaller number from two numbers taken from the user.     
# a = int(input('type a first number: '))
# b = int(input("type a second number: "))
# if(a>b):
#     print( a, 'is greater than', b )
# elif(b>a):
#     print(a,' is smaller than',b)
# else:
#     print('the number is same')

# Bob has a floating point number N. He wants to set the precision for 2 digits after the decimal point for the number. He is not good at coding, hence looking for your help.

# '''
# 1
# 713.166

# 713.17
# '''

# precition = int(input("Type The Precition: "))
# number = int(input("Type The Floating Point Number: "))

# def manthan(name):
#     print(f'Good Morning,\n \t     {name}')
# manthan("yash")

# class raj():
#     def __init__(self, name, hobby, passion, age) -> None:
#         self.name = name
#         self.hobby = hobby
#         self.passion = passion
#         self.age = age

# def example(name= "manthan"):
#     print('Good Morning, ', name)

# example('yash')

# def my_Name(name = 'manthan'):
#     print('Hello,' + name)

# my_Name()
# my_Name('yash') 


# 3=3*(3 - 1)
# f = 1, 2, 6, 24, 120, .......

# factorial (3) = 3 * factorial (3 - 1)

# def fact(n):
#     return n = n*(n-1)
 
# Write a programm to find the greatest of three numbers.

# def number(num1,num2,num3):
#     if(num1>num2):
#         if(num1>num3): 
#             return num1 
#         else:
#             return num3
#     if (num2>num3):
#         return num2
#     else:
#         return num3
# num = number(64,97,39)
# print("this number is greatest : " + str(num))

# Write a python programm using function to convert celsius to fahrenheit.

# def cell_to_Fahr(temp):
#     return (temp * (9 / 5)) + 32

# print(cell_to_Fahr(37))

# import random

# def isWin(comp, player):
#     if (player == comp):
#         print("*** It's A Tie, Better Luck Next Time. ***")
#     else:
#         if (player == 's'):
#             if (comp == 'w'):
#                 print('*** Congratulations ... You Won The Game.***')
#             else:
#                 print('You Lose ... Better Luck Next Time.')
#         elif (player == 'w'):
#             if (comp == 'g'):
#                 print('*** Congratulations ... You Won The Game.***')
#             else:
#                 print('You Lose ... Better Luck Next Time.')
#         else:
#             if (comp == 's'):
#                 print('*** Congratulations ... You Won The Game.***')
#             else:
#                 print('You Lose ... Better Luck Next Time.')

# game = True

# while game == True:
#     rannumber = random.randint(1,3)

#     if(rannumber == 1):
#         bot = 's'
#     elif(rannumber == 2):
#         bot = 'w'
#     else:
#         bot = 'g'

#     you = input("type snake(s), water(w), gun(g): ")

#     isWin(bot, you)

#     choices = (input("Type 1 if you don't want to play further."))

#     if choices == '1':
#         game = False

a = open('Basic Python Programming\\man.txt', 'r')
print (a.read())
a.close() 