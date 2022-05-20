def printBox (characters):
  print (f'''
      {characters [0]} | {characters [1]} | {characters [2]}
     ———+———+———
      {characters [3]} | {characters [4]} | {characters [5]}
     ———+———+———
      {characters [6]} | {characters [7]} | {characters [8]}
    ''')

def basicConditions (l):
  if ((l[1] == 'O' and l[2] == 'O') or (l[4] == 'O' and l[8] == 'O') or (l[3] == 'O' and l[6] == 'O')):
    return 1
  elif ((l[0] == 'O' and l[2] == 'O') or (l[4]) == 'O' and l[7] == 'O'):
    return 2
  elif ((l[0] == 'O' and l[1] == 'O') or (l[5] == 'O' and l[8] == 'O') or (l[4] == 'O' and l[6] == 'O')):
    return 3
  elif ((l[0] == 'O' and l[6] == 'O') or (l[4] == 'O' and l[5] == 'O')):
    return 4
  elif ((l[0] == 'O' and l[8] == 'O') or (l[2] == 'O' and l[6] == 'O') or (l[1] == 'O' and l[7] == 'O') or (l[3] == 'X' and l[5] == 'X')):
    return 5
  elif ((l[3] == 'O' and l[4] == 'O') or (l[2] == 'O' and l[8] == 'O')):
    return 6
  elif ((l[0] == 'O' and l[3] == 'O') or (l[2] == 'O' and l[4] == 'O') or (l[7] == 'O' and l[8] == 'O')):
    return 7
  elif ((l[1] == 'O' and l[4] == 'O') or (l[6] == 'O' and l[8] == 'O')):
    return 8
  elif ((l[0] == 'O' and l[4] == 'O') or (l[2] == 'O' and l[5] == 'O') or (l[6] == 'O' and l[7] == 'O')):
    return 9
  else:
    if ((l[1] == 'X' and l[2] == 'X') or (l[4] == 'X' and l[8] == 'X') or (l[3] == 'X' and l[6] == 'X')):
        return 1
    elif ((l[0] == 'X' and l[2] == 'X') or (l[4]) == 'X' and l[7] == 'X'):
        return 2
    elif ((l[0] == 'X' and l[1] == 'X') or (l[5] == 'X' and l[8] == 'X') or (l[4] == 'X' and l[6] == 'X')):
        return 3
    elif ((l[0] == 'X' and l[6] == 'X') or (l[4] == 'X' and l[5] == 'X')):
        return 4
    elif ((l[0] == 'X' and l[8] == 'X') or (l[2] == 'X' and l[6] == 'X') or (l[1] == 'X' and l[7] == 'X') or (l[3] == 'X' and l[5] == 'X')):
        return 5
    elif ((l[3] == 'X' and l[4] == 'X') or (l[2] == 'X' and l[8] == 'X')):
        return 6
    elif ((l[0] == 'X' and l[3] == 'X') or (l[2] == 'X' and l[4] == 'X') or (l[7] == 'X' and l[8] == 'X')):
        return 7
    elif ((l[1] == 'X' and l[4] == 'X') or (l[6] == 'X' and l[8] == 'X')):
        return 8
    elif ((l[0] == 'X' and l[4] == 'X') or (l[2] == 'X' and l[5] == 'X') or (l[6] == 'X' and l[7] == 'X')):
        return 9
    else :
      return 0

def conditionTurn1 (turn):
  if (turn == 5):
    pc =  1
  else :
    pc =  5
  return pc

def conditionTurn2 (turn, turn2) :

  if (turn == 1):

    if (turn2 == 2):
      pc =  3
    elif (turn2 == 3):
      pc =  2
    elif (turn2 == 4):
      pc =  7
    elif (turn2 == 6):
      pc =  3
    elif (turn2 == 7):
      pc =  4
    elif (turn2 == 8):
      pc =  7  
    elif (turn2 == 9):
      pc =  4
    else :
      pass

  elif (turn == 2):

    if (turn2 == 1):
      pc =  3
    elif (turn2 == 3):
      pc =  1
    elif (turn2 == 4):
      pc =  1
    elif (turn2 == 6):
      pc =  3
    elif (turn2 == 7):
      pc =  1
    elif (turn2 == 8):
      pc =  7  
    elif (turn2 == 9):
      pc =  3
    else :
      pass

  elif (turn == 3):

    if (turn2 == 1):
      
      pc =  2
    elif (turn2 == 2):
      pc =  1
    elif (turn2 == 4):
      pc =  1
    elif (turn2 == 6):
      pc =  9
    elif (turn2 == 7):
      pc =  6
    elif (turn2 == 8):
      pc =  9  
    elif (turn2 == 9):
      pc =  6
    else :
      pass

  elif (turn == 4):

    if (turn2 == 1):
      pc =  7
    elif (turn2 == 2):
      pc =  1
    elif (turn2 == 3):
      pc =  1
    elif (turn2 == 6):
      pc =  3
    elif (turn2 == 7):
      pc =  1
    elif (turn2 == 8):
      pc =  7  
    elif (turn2 == 9):
      pc =  7
    else :
      pass

  elif (turn == 5):

    if (turn2 == 2):
      pc =  8
    elif (turn2 == 3):
      pc =  7
    elif (turn2 == 4):
      pc =  6
    elif (turn2 == 6):
      pc =  4
    elif (turn2 == 7):
      pc =  3
    elif (turn2 == 8):
      pc =  2  
    elif (turn2 == 9):
      pc =  3
    else :
      pass

  elif (turn == 6):

    if (turn2 == 1):
      pc =  2
    elif (turn2 == 2):
      pc =  1
    elif (turn2 == 3):
      pc =  9
    elif (turn2 == 4):
      pc =  8
    elif (turn2 == 7):
      pc =  8
    elif (turn2 == 8):
      pc =  7  
    elif (turn2 == 9):
      pc =  3
    else :
      pass

  elif (turn == 7):

    if (turn2 == 1):
      pc =  4
    elif (turn2 == 2):
      pc =  4
    elif (turn2 == 3):
      pc =  8
    elif (turn2 == 4):
      pc =  1
    elif (turn2 == 6):
      pc =  8
    elif (turn2 == 8):
      pc =  9  
    elif (turn2 == 9):
      pc =  8 
    else :
      pass

  elif (turn == 8):

    if (turn2 == 1):
      pc =  4
    elif (turn2 == 2):
      pc =  6
    elif (turn2 == 3):
      pc =  6
    elif (turn2 == 4):
      pc =  9
    elif (turn2 == 6):
      pc =  7
    elif (turn2 == 7):
      pc =  9  
    elif (turn2 == 9):
      pc =  7 
    else :
      pass

  elif (turn == 9):

    if (turn2 == 1):
      pc =  8
    elif (turn2 == 2):
      pc =  6
    elif (turn2 == 3):
      pc =  6
    elif (turn2 == 4):
      pc =  8
    elif (turn2 == 6):
      pc =  3
    elif (turn2 == 7):
      pc =  8  
    elif (turn2 == 8):
      pc =  7  
    else :
      pass   

  else :
    pass
  return pc

l = [1, 2, 3, 4, 5, 6, 7, 8, 9]
printBox(l)
print("Player's Turn...")
turn = int(input("Type the number of position that you want to place your 'x'."))
l.remove(turn)
l.insert(turn - 1 , 'X')
printBox(l)

print("AI is Thinking...")
computerTurn = conditionTurn1 (turn)
l.remove(computerTurn)
l.insert(computerTurn - 1, "O")
printBox(l)

print("Player's Turn...")
turn2 = int(input("Type the number of position that you want to place your 'x'."))
l.remove(turn2)
l.insert(turn2 - 1 , 'X')
printBox(l)

print("AI is Thinking...")
computerTurn = conditionTurn2(turn, turn2)
l.remove(computerTurn)
l.insert(computerTurn - 1, "O")
printBox(l)


print("Player's Turn...")
turn3 = int(input("Type the number of position that you want to place your 'x'."))
l.remove(turn3)
l.insert(turn3 - 1 , 'X')
printBox(l)

print("AI is Thinking...")
pc = basicConditions(l)
l.remove(pc)
l.insert(pc - 1, 'O')
printBox(l)
