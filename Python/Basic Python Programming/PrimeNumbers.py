From = int(input("Type the list of the prime numbers starts from :- "))
To   = int(input("Type the list of the prime numbers ends to :- "))

primenumbers = []
primes = 0
isprime = True
number = From
itteretion = 1

file = open("primeNumbers.txt", "w")

while number <= To:

  factor = 2
  isprime = True

  while factor <= int(number/2):

    multiple = 1

    while (multiple * factor) < number:

      multiple += 1

    if ((multiple * factor) == number):

      isprime = False
      break 

    else :

      factor += 1

  if isprime and number >= factor :

    primenumbers.append(number)
    print (f'{number} :- prime')

    if itteretion == 1:
      file.write(f"{itteretion}st Prime Number is :- {number}\n")

    elif itteretion == 2:
      file.write(f"{itteretion}nd Prime Number is :- {number}\n")

    elif itteretion == 3:
      file.write(f"{itteretion}rd Prime Number is :- {number}\n")

    else:
      file.write(f"{itteretion}th Prime Number is :- {number}\n")

    number += 1
    primes += 1
    itteretion += 1

  else :
    
    print (f"{number} :- composite")
    number += 1
   
  
print (f'number of primes :- {primes}')    
print (f'Prime Numbers are :- {primenumbers}')
file.close()