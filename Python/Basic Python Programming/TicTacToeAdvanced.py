def printBox (characters):
  print (f'''
      {characters [0]} | {characters [1]} | {characters [2]}
     ———+———+———
      {characters [3]} | {characters [4]} | {characters [5]}
     ———+———+———
      {characters [6]} | {characters [7]} | {characters [8]}
    ''')

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
def conditionTurn3 (turn, turn2, turn3):

  if (turn == 1):

    if (turn2 == 2):
      if (turn3 == 4):
        pc =  7
      elif (turn3 == 6):
        pc = 7
      elif (turn3 == 7):
        pc = 4
      elif (turn3 == 8):
        pc = 7
      elif (turn3 == 9):
        pc = 7
      else :
        pass
    
    elif (turn2 == 3):

      if (turn3 == 4):
        pc =  8
      elif (turn3 == 6):
        pc =  8
      elif (turn3 == 7):
        pc =  8
      elif (turn3 == 8):
        pc =  4
      elif (turn3 == 9):
        pc = 8
      else :
        pass

    elif (turn2 == 4):

      if (turn3 == 2):
        pc =  3
      elif (turn3 == 3):
        pc = 2
      elif (turn3 == 6):
        pc = 3
      elif (turn3 == 8):
        pc = 3
      elif (turn3 == 9):
        pc = 3
      else :
        pass

    elif (turn2 == 6):

      if (turn3 == 2):
        pc =  7
      elif (turn3 == 4):
        pc = 0
      elif (turn3 == 7):
        pc = 0
      elif (turn3 == 8):
        pc = 0
      elif (turn3 == 9):
        pc = 0
      else :
        pass
    elif (turn2 == 7):
      if (turn3 == 2):
        pc =  0
      elif (turn3 == 3):
        pc = 0
      elif (turn3 == 6):
        pc = 0
      elif (turn3 == 8):
        pc = 0
      elif (turn3 == 9):
        pc = 0
      else :
        pass
    elif (turn2 == 8):
      if (turn3 == 2):
        pc =  0
      elif (turn3 == 3):
        pc = 0
      elif (turn3 == 4):
        pc = 0
      elif (turn3 == 6):
        pc = 0
      elif (turn3 == 9):
        pc = 0
      else :
        pass
    elif (turn2 == 9):
      if (turn3 == 2):
        pc =  0
      elif (turn3 == 3):
        pc = 0
      elif (turn3 == 6):
        pc = 0
      elif (turn3 == 7):
        pc = 0
      elif (turn3 == 8):
        pc = 0
      else :
        pass
    else :
      pass
    
  elif (turn == 2):
    if (turn2 == 1):
      if (turn3 == 4):
        pc =  0
      elif (turn3 == 6):
        pc = 0
      elif (turn3 == 7):
        pc = 0
      elif (turn3 == 8):
        pc = 0
      elif (turn3 == 9):
        pc = 0
      else :
        pass
    
    elif (turn2 == 3):
      if (turn3 == 4):
        pc =  0
      elif (turn3 == 6):
        pc = 0
      elif (turn3 == 7):
        pc = 0
      elif (turn3 == 8):
        pc = 0
      elif (turn3 == 9):
        pc = 0
      else :
        pass
    elif (turn2 == 4):
      if (turn3 == 3):
        pc =  0
      elif (turn3 == 6):
        pc = 0
      elif (turn3 == 7):
        pc = 0
      elif (turn3 == 8):
        pc = 0
      elif (turn3 == 9):
        pc = 0
      else :
        pass
    elif (turn2 == 6):
      if (turn3 == 1):
        pc =  0
      elif (turn3 == 4):
        pc = 0
      elif (turn3 == 7):
        pc = 0
      elif (turn3 == 8):
        pc = 0
      elif (turn3 == 9):
        pc = 0
      else :
        pass
    elif (turn2 == 7):
      if (turn3 == 3):
        pc =  0
      elif (turn3 == 4):
        pc = 0
      elif (turn3 == 6):
        pc = 0
      elif (turn3 == 8):
        pc = 0
      elif (turn3 == 9):
        pc = 0
      else :
        pass
    elif (turn2 == 8):
      if (turn3 == 1):
        pc =  0
      elif (turn3 == 3):
        pc = 0
      elif (turn3 == 4):
        pc = 0
      elif (turn3 == 6):
        pc = 0
      elif (turn3 == 9):
        pc = 0
      else :
        pass
    elif (turn2 == 9):
      if (turn3 == 1):
        pc =  0
      elif (turn3 == 4):
        pc = 0
      elif (turn3 == 6):
        pc = 0
      elif (turn3 == 7):
        pc = 0
      elif (turn3 == 8):
        pc = 0
      else :
        pass
    else :
      pass

  elif (turn == 3):
    if (turn2 == 1):
      if (turn3 == 4):
        pc =  0
      elif (turn3 == 6):
        pc = 0
      elif (turn3 == 7):
        pc = 0
      elif (turn3 == 8):
        pc = 0
      elif (turn3 == 9):
        pc = 0
      else :
        pass
    
    elif (turn2 == 2):
      if (turn3 == 4):
        pc =  0
      elif (turn3 == 6):
        pc = 0
      elif (turn3 == 7):
        pc = 0
      elif (turn3 == 8):
        pc = 0
      elif (turn3 == 9):
        pc = 0
      else :
        pass
    elif (turn2 == 4):
      if (turn3 == 2):
        pc =  0
      elif (turn3 == 6):
        pc = 0
      elif (turn3 == 7):
        pc = 0
      elif (turn3 == 8):
        pc = 0
      elif (turn3 == 9):
        pc = 0
      else :
        pass
    elif (turn2 == 6):
      if (turn3 == 1):
        pc =  0
      elif (turn3 == 2):
        pc = 0
      elif (turn3 == 4):
        pc = 0
      elif (turn3 == 7):
        pc = 0
      elif (turn3 == 8):
        pc = 0
      else :
        pass
    elif (turn2 == 7):
      if (turn3 == 1):
        pc =  0
      elif (turn3 == 2):
        pc = 0
      elif (turn3 == 4):
        pc = 0
      elif (turn3 == 8):
        pc = 0
      elif (turn3 == 9):
        pc = 0
      else :
        pass
    elif (turn2 == 8):
      if (turn3 == 1):
        pc =  0
      elif (turn3 == 2):
        pc = 0
      elif (turn3 == 4):
        pc = 0
      elif (turn3 == 6):
        pc = 0
      elif (turn3 == 7):
        pc = 0
      else :
        pass
    elif (turn2 == 9):
      if (turn3 == 1):
        pc =  0
      elif (turn3 == 2):
        pc = 0
      elif (turn3 == 4):
        pc = 0
      elif (turn3 == 7):
        pc = 0
      elif (turn3 == 8):
        pc = 0
      else :
        pass
    else :
      pass

  elif (turn == 4):
    if (turn2 == 1):
      if (turn3 == 2):
        pc =  0
      elif (turn3 == 3):
        pc = 0
      elif (turn3 == 6):
        pc = 0
      elif (turn3 == 8):
        pc = 0
      elif (turn3 == 9):
        pc = 0
      else :
        pass
    
    elif (turn2 == 2):
      if (turn3 == 3):
        pc =  0
      elif (turn3 == 6):
        pc = 0
      elif (turn3 == 7):
        pc = 0
      elif (turn3 == 8):
        pc = 0
      elif (turn3 == 9):
        pc = 0
      else :
        pass
    elif (turn2 == 3):
      if (turn3 == 2):
        pc =  0
      elif (turn3 == 6):
        pc = 0
      elif (turn3 == 7):
        pc = 0
      elif (turn3 == 8):
        pc = 0
      elif (turn3 == 9):
        pc = 0
      else :
        pass
    elif (turn2 == 6):
      if (turn3 == 1):
        pc =  0
      elif (turn3 == 2):
        pc = 0
      elif (turn3 == 7):
        pc = 0
      elif (turn3 == 8):
        pc = 0
      elif (turn3 == 9):
        pc = 0
      else :
        pass
    elif (turn2 == 7):
      if (turn3 == 2):
        pc =  0
      elif (turn3 == 3):
        pc = 0
      elif (turn3 == 6):
        pc = 0
      elif (turn3 == 8):
        pc = 0
      elif (turn3 == 9):
        pc = 0
      else :
        pass
    elif (turn2 == 8):
      if (turn3 == 1):
        pc =  0
      elif (turn3 == 2):
        pc = 0
      elif (turn3 == 3):
        pc = 0
      elif (turn3 == 6):
        pc = 0
      elif (turn3 == 9):
        pc = 0
      else :
        pass
    elif (turn2 == 9):
      if (turn3 == 1):
        pc =  0
      elif (turn3 == 2):
        pc = 0
      elif (turn3 == 3):
        pc = 0
      elif (turn3 == 6):
        pc = 0
      elif (turn3 == 8):
        pc = 0
      else :
        pass
    else :
      pass

  elif (turn == 5):
    if (turn2 == 2):
      if (turn3 == 3):
        pc =  0
      elif (turn3 == 4):
        pc = 0
      elif (turn3 == 6):
        pc = 0
      elif (turn3 == 7):
        pc = 0
      elif (turn3 == 9):
        pc = 0
      else :
        pass
    
    elif (turn2 == 3):
      if (turn3 == 2):
        pc =  0
      elif (turn3 == 4):
        pc = 0
      elif (turn3 == 6):
        pc = 0
      elif (turn3 == 8):
        pc = 0
      elif (turn3 == 9):
        pc = 0
      else :
        pass
    elif (turn2 == 4):
      if (turn3 == 2):
        pc =  0
      elif (turn3 == 3):
        pc = 0
      elif (turn3 == 7):
        pc = 0
      elif (turn3 == 8):
        pc = 0
      elif (turn3 == 9):
        pc = 0
      else :
        pass
    elif (turn2 == 6):
      if (turn3 == 2):
        pc =  0
      elif (turn3 == 3):
        pc = 0
      elif (turn3 == 7):
        pc = 0
      elif (turn3 == 8):
        pc = 0
      elif (turn3 == 9):
        pc = 0
      else :
        pass
    elif (turn2 == 7):

      if (turn3 == 2):
        pc =  0
      elif (turn3 == 4):
        pc = 0
      elif (turn3 == 6):
        pc = 0
      elif (turn3 == 8):
        pc = 0
      elif (turn3 == 9):
        pc = 0
      else :
        pass
    elif (turn2 == 8):
      if (turn3 == 3):
        pc =  0
      elif (turn3 == 4):
        pc = 0
      elif (turn3 == 7):
        pc = 0
      elif (turn3 == 6):
        pc = 0
      elif (turn3 == 9):
        pc = 0
      else :
        pass
    elif (turn2 == 9):
      if (turn3 == 2):
        pc =  0
      elif (turn3 == 4):
        pc = 0
      elif (turn3 == 6):
        pc = 0
      elif (turn3 == 7):
        pc = 0
      elif (turn3 == 8):
        pc = 0
      else :
        pass
    else :
      pass

  elif (turn == 6):
    if (turn2 == 1):
      if (turn3 == 3):
        pc =  0
      elif (turn3 == 4):
        pc = 0
      elif (turn3 == 7):
        pc = 0
      elif (turn3 == 8):
        pc = 0
      elif (turn3 == 9):
        pc = 0
      else :
        pass
    
    elif (turn2 == 2):
      if (turn3 == 3):
        pc =  0
      elif (turn3 == 4):
        pc = 0
      elif (turn3 == 7):
        pc = 0
      elif (turn3 == 8):
        pc = 0
      elif (turn3 == 9):
        pc = 0
      else :
        pass
    elif (turn2 == 3):
      if (turn3 == 1):
        pc =  0
      elif (turn3 == 2):
        pc = 0
      elif (turn3 == 4):
        pc = 0
      elif (turn3 == 7):
        pc = 0
      elif (turn3 == 8):
        pc = 0
      else :
        pass
    elif (turn2 == 4):
      if (turn3 == 1):
        pc =  0
      elif (turn3 == 2):
        pc = 0
      elif (turn3 == 3):
        pc = 0
      elif (turn3 == 7):
        pc = 0
      elif (turn3 == 9):
        pc = 0
      else :
        pass
    elif (turn2 == 7):
      if (turn3 == 1):
        pc =  0
      elif (turn3 == 2):
        pc = 0
      elif (turn3 == 3):
        pc = 0
      elif (turn3 == 4):
        pc = 0
      elif (turn3 == 9):
        pc = 0
      else :
        pass
    elif (turn2 == 8):
      if (turn3 == 1):
        pc =  0
      elif (turn3 == 2):
        pc = 0
      elif (turn3 == 3):
        pc = 0
      elif (turn3 == 4):
        pc = 0
      elif (turn3 == 9):
        pc = 0
      else :
        pass
    elif (turn2 == 9):
      if (turn3 == 1):
        pc =  0
      elif (turn3 == 2):
        pc = 0
      elif (turn3 == 4):
        pc = 0
      elif (turn3 == 7):
        pc = 0
      elif (turn3 == 8):
        pc = 0
      else :
        pass
    else :
      pass

  elif (turn == 7):
    if (turn2 == 1):
      if (turn3 == 2):
        pc =  0
      elif (turn3 == 3):
        pc = 0
      elif (turn3 == 6):
        pc = 0
      elif (turn3 == 8):
        pc = 0
      elif (turn3 == 9):
        pc = 0
      else :
        pass
    
    elif (turn2 == 2):
      if (turn3 == 1):
        pc =  0
      elif (turn3 == 3):
        pc = 0
      elif (turn3 == 6):
        pc = 0
      elif (turn3 == 8):
        pc = 0
      elif (turn3 == 9):
        pc = 0
      else :
        pass
    elif (turn2 == 3):
      if (turn3 == 1):
        pc =  0
      elif (turn3 == 2):
        pc = 0
      elif (turn3 == 4):
        pc = 0
      elif (turn3 == 6):
        pc = 0
      elif (turn3 == 9):
        pc = 0
      else :
        pass
    elif (turn2 == 4):
      if (turn3 == 2):
        pc =  0
      elif (turn3 == 3):
        pc = 0
      elif (turn3 == 6):
        pc = 0
      elif (turn3 == 8):
        pc = 0
      elif (turn3 == 9):
        pc = 0
      else :
        pass
    elif (turn2 == 6):
      if (turn3 == 1):
        pc =  0
      elif (turn3 == 2):
        pc = 0
      elif (turn3 == 3):
        pc = 0
      elif (turn3 == 4):
        pc = 0
      elif (turn3 == 9):
        pc = 0
      else :
        pass
    elif (turn2 == 8):
      if (turn3 == 1):
        pc =  0
      elif (turn3 == 2):
        pc = 0
      elif (turn3 == 3):
        pc = 0
      elif (turn3 == 4):
        pc = 0
      elif (turn3 == 6):
        pc = 0
      else :
        pass
    elif (turn2 == 9):
      if (turn3 == 1):
        pc =  0
      elif (turn3 == 2):
        pc = 0
      elif (turn3 == 3):
        pc = 0
      elif (turn3 == 4):
        pc = 0
      elif (turn3 == 6):
        pc = 0
      else :
        pass
    else :
      pass

  elif (turn == 8):
    if (turn2 == 1):
      if (turn3 == 2):
        pc =  0
      elif (turn3 == 3):
        pc = 0
      elif (turn3 == 6):
        pc = 0
      elif (turn3 == 7):
        pc = 0
      elif (turn3 == 9):
        pc = 0
      else :
        pass
    
    elif (turn2 == 2):
      if (turn3 == 1):
        pc =  0
      elif (turn3 == 3):
        pc = 0
      elif (turn3 == 4):
        pc = 0
      elif (turn3 == 7):
        pc = 0
      elif (turn3 == 9):
        pc = 0
      else :
        pass
    elif (turn2 == 3):
      if (turn3 == 1):
        pc =  0
      elif (turn3 == 2):
        pc = 0
      elif (turn3 == 4):
        pc = 0
      elif (turn3 == 7):
        pc = 0
      elif (turn3 == 9):
        pc = 0
      else :
        pass
    elif (turn2 == 4):
      if (turn3 == 1):
        pc =  0
      elif (turn3 == 2):
        pc = 0
      elif (turn3 == 3):
        pc = 0
      elif (turn3 == 6):
        pc = 0
      elif (turn3 == 7):
        pc = 0
      else :
        pass
    elif (turn2 == 6):
      if (turn3 == 1):
        pc =  0
      elif (turn3 == 2):
        pc = 0
      elif (turn3 == 3):
        pc = 0
      elif (turn3 == 4):
        pc = 0
      elif (turn3 == 9):
        pc = 0
      else :
        pass
    elif (turn2 == 7):
      if (turn3 == 1):
        pc =  0
      elif (turn3 == 2):
        pc = 0
      elif (turn3 == 3):
        pc = 0
      elif (turn3 == 4):
        pc = 0
      elif (turn3 == 6):
        pc = 0
      else :
        pass
    elif (turn2 == 9):
      if (turn3 == 1):
        pc =  0
      elif (turn3 == 2):
        pc = 0
      elif (turn3 == 3):
        pc = 0
      elif (turn3 == 4):
        pc = 0
      elif (turn3 == 6):
        pc = 0
      else :
        pass
    else :
      pass

  elif (turn == 9):
    if (turn2 == 1):
      if (turn3 == 2):
        pc =  0
      elif (turn3 == 3):
        pc = 0
      elif (turn3 == 4):
        pc = 0
      elif (turn3 == 6):
        pc = 0
      elif (turn3 == 7):
        pc = 0
      else :
        pass
    
    elif (turn2 == 2):
      if (turn3 == 1):
        pc =  0
      elif (turn3 == 3):
        pc = 0
      elif (turn3 == 4):
        pc = 0
      elif (turn3 == 7):
        pc = 0
      elif (turn3 == 8):
        pc = 0
      else :
        pass
    elif (turn2 == 3):
      if (turn3 == 1):
        pc =  0
      elif (turn3 == 2):
        pc = 0
      elif (turn3 == 4):
        pc = 0
      elif (turn3 == 7):
        pc = 0
      elif (turn3 == 8):
        pc = 0
      else :
        pass
    elif (turn2 == 4):
      if (turn3 == 1):
        pc =  0
      elif (turn3 == 2):
        pc = 0
      elif (turn3 == 3):
        pc = 0
      elif (turn3 == 6):
        pc = 0
      elif (turn3 == 9):
        pc = 0
      else :
        pass
    elif (turn2 == 6):
      if (turn3 == 1):
        pc =  0
      elif (turn3 == 2):
        pc = 0
      elif (turn3 == 4):
        pc = 0
      elif (turn3 == 7):
        pc = 0
      elif (turn3 == 8):
        pc = 0
      else :
        pass
    elif (turn2 == 7):
      if (turn3 == 1):
        pc =  0
      elif (turn3 == 2):
        pc = 0
      elif (turn3 == 3):
        pc = 0
      elif (turn3 == 4):
        pc = 0
      elif (turn3 == 6):
        pc = 0
      else :
        pass
    elif (turn2 == 8):
      if (turn3 == 1):
        pc =  0
      elif (turn3 == 2):
        pc = 0
      elif (turn3 == 3):
        pc = 0
      elif (turn3 == 4):
        pc = 0
      elif (turn3 == 6):
        pc = 0
      else :
        pass
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

'''
print("Player's Turn...")
turn3 = int(input("Type the number of position that you want to place your 'x'."))
l.remove(turn3)
l.insert(turn3 - 1 , 'X')
printBox(l)

print("AI is Thinking...")
'''