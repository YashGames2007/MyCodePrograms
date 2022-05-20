def printBox(characters):
    print(f'''
      {characters [0]} | {characters [1]} | {characters [2]}
     ———+———+———
      {characters [3]} | {characters [4]} | {characters [5]}
     ———+———+———
      {characters [6]} | {characters [7]} | {characters [8]}
    
  
  ''')


def conditioncheck(list):
    if ((list[0]) == (list[1]) and (list[1]) == (list[2])):
        win = True
    elif ((list[3]) == (list[4]) and (list[4]) == (list[5])):
        win = True
    elif ((list[6]) == (list[7]) and (list[7]) == (list[8])):
        win = True
    elif ((list[0]) == (list[3]) and (list[3]) == (list[6])):
        win = True
    elif ((list[1]) == (list[4]) and (list[4]) == (list[7])):
        win = True
    elif ((list[2]) == (list[5]) and (list[5]) == (list[8])):
        win = True
    elif ((list[0]) == (list[4]) and (list[4]) == (list[8])):
        win = True
    elif ((list[2]) == (list[4]) and (list[4]) == (list[6])):
        win = True
    else:
        win = False
    return win


list = [1, 2, 3, 4, 5, 6, 7, 8, 9]
print("   ***   Tic Tac Toe   ***   ")
print("Player1's turn...")
printBox(list)
turn = int(input('''Type the number of position
that you have to place your 'X' :-'''))
list.remove(turn)
list.insert((turn - 1), 'X')
printBox(list)
print(f"Player1 placed his X at {turn} No. place.")


for i in range(4):
    print("Player2's turn...")
    printBox(list)
    turn = int(input('''Type the number of position
  that you have to place your 'O' :-'''))
    list.remove(turn)
    list.insert((turn - 1), 'O')
    printBox(list)
    print(f"Player1 placed his O at {turn} No. place.")
    if conditioncheck(list):
        print('''Player2 wins  match
       *** congratulations ***   
         -for player2's victory.''')
        break
    else:
        print("Player1's turn...")
    printBox(list)
    turn = int(input('''Type the number of position
  that you have to place your 'X :-'''))
    list.remove(turn)
    list.insert((turn - 1), 'X')
    printBox(list)
    print(f"Player1 placed his X at {turn} No. place.")
    if conditioncheck(list):
        print('''Player1 wins  match
       *** congratulations ***   
         -for player1's victory.''')
        break
    else:
        pass

if (conditioncheck(list) == False):
    print('''it's a tie match
  well played...
  better luck next time!''')
elif (conditioncheck(list) == True):
    pass
else:
    pass
