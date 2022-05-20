import math
import string

def getConstants(equation):
  if (equation[0] == "x"):
    equation = f"1{equation}"
  position = equation.find("x", 2)
  digit = equation[position - 1]
    
  equation = equation.replace(" ","")
  equation = equation.replace('x²',"")
  equation = equation.replace('x',"")
  equation = equation.replace('=0','')
  equation = equation.replace("-"," -")
  equation = equation.replace("+"," +")

  list1 = equation.split(" ")

  if list1[0] == "":
    list1.pop(0)
    
  if digit.isdigit():
    pass
  else:
    list1[1] = '1'
  print(list1)
  return list1

qdEq = input("""Type an Quadratic Equation
In The Format,
ax² + bx + c = 0
::: """)

constants = getConstants(qdEq)
a = int(constants[0])
b = int(constants[1])
c = int(constants[2])

print(f"a = {a}\nb = {b}\nc = {c}")

delta = (b * b) - 4 * a * c

alpha = ((-1 * b) + pow(delta, 0.5)) / (2 * a)
beta = ((-1 * b) - pow(delta, 0.5)) / (2 * a)

print(f"The Roots of The Given Quadratic\nEquation are {alpha} and {beta} Respectively.")

