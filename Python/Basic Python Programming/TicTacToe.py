board = [1, 2, 3, 4, 5, 6, 7, 8, 9]
tokens = ['X', 'O']

def printBoard():
    print(f'''
      {board [0]} | {board [1]} | {board [2]}
     ———+———+———
      {board [3]} | {board [4]} | {board [5]}
     ———+———+———
      {board [6]} | {board [7]} | {board [8]}
    
  
  ''')


def conditionCheck():
    conditions = [
        [0, 1, 2], [3, 4, 5], [6, 7, 8],    # Horizontal Checks
        [0, 3, 6], [1, 4, 7], [2, 5, 8],    # Vertical Checks
        [0, 4, 8], [2, 4, 6]                # DIagonal Checks
    ]
    win = False
    for i, j, k in conditions:
        if ((board[i]) == (board[j]) and (board[j]) == (board[k])):
            win = True
    return win

def isFull():
    for token in board:
        if token not in tokens:
            return False
    return True

def makeTurn(pos, token):
    if 0 <= pos <= 8:
        if board[pos] not in tokens:
            board[pos] = token
            return True
    return False

def game():
    player = 2
    print("***   Tic Tac Toe   ***   ")

    while not isFull():
        player = 1 if player == 2 else 2
        token = tokens[player-1]
        print(f"Player{player}'s turn...")
        printBoard()
        turn = int(input(f'''Type the number of position\nwhere you have to place your '{token}' : '''))

        if not makeTurn(turn-1, token):
            print("\nInvalid Move, Try again!!!\n\n")
            player = 1 if player == 2 else 2
            continue

        printBoard()
        print(f"Player{player} placed his {token} at {turn} No. place.")

        if conditionCheck():
            print(f'''Player{player} wins  match\n*** congratulations ***\n\t-for player{player}'s victory.''')
            break

    if not conditionCheck():
        print('''\n\nIt's a tie match\nWell played...\nBetter luck next time!''')

if __name__ == "__main__":
    game()
