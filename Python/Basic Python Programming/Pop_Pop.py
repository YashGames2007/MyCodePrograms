def printBox_PopPop(tokens):  # This Function Will Print The Boxes of The Game.
    print(f'''

    #-----------------------------#
    | {tokens[0]} | {tokens[1]} | {tokens[2]} | {tokens[3]} | {tokens[4]} | {tokens[5]} |
    |----+----+----+----+----+----|
    | {tokens[6]} | {tokens[7]} | {tokens[8]} | {tokens[9]} | {tokens[10]} | {tokens[11]} |
    |----+----+----+----+----+----|
    | {tokens[12]} | {tokens[13]} | {tokens[14]} | {tokens[15]} | {tokens[16]} | {tokens[17]} |
    |----+----+----+----+----+----|
    | {tokens[18]} | {tokens[19]} | {tokens[20]} | {tokens[21]} | {tokens[22]} | {tokens[23]} |
    |----+----+----+----+----+----|
    | {tokens[24]} | {tokens[25]} | {tokens[26]} | {tokens[27]} | {tokens[28]} | {tokens[29]} |
    |----+----+----+----+----+----|
    | {tokens[30]} | {tokens[31]} | {tokens[32]} | {tokens[33]} | {tokens[34]} | {tokens[35]} |
    #-----------------------------#

    ''')

def conditionCheck(t): # This Function Will Count Total Number Of Points Recieved By Both Players.
    # Let Points Be 0
    points = 0
    # Horizontal Line 1
    if (t[0] == ' P' and t[1] == ' O' and t[2] == ' P'):
        points += 1
    if (t[1] == ' P' and t[2] == ' O' and t[3] == ' P'):
        points += 1
    if (t[2] == ' P' and t[3] == ' O' and t[4] == ' P'):
        points += 1
    if (t[3] == ' P' and t[4] == ' O' and t[5] == ' P'):
        points += 1

    # Horizontal Line 2
    if (t[6] == ' P' and t[7] == ' O' and t[8] == ' P'):
        points += 1
    if (t[7] == ' P' and t[8] == ' O' and t[9] == ' P'):
        points += 1
    if (t[8] == ' P' and t[9] == ' O' and t[10] == ' P'):
        points += 1
    if (t[9] == ' P' and t[10] == ' O' and t[11] == ' P'):
        points += 1

    # Horizontal Line 3
    if (t[12] == ' P' and t[13] == ' O' and t[14] == ' P'):
        points += 1
    if (t[13] == ' P' and t[14] == ' O' and t[15] == ' P'):
        points += 1
    if (t[14] == ' P' and t[15] == ' O' and t[16] == ' P'):
        points += 1
    if (t[15] == ' P' and t[16] == ' O' and t[17] == ' P'):
        points += 1

    # Horizontal Line 4
    if (t[18] == ' P' and t[19] == ' O' and t[20] == ' P'):
        points += 1
    if (t[19] == ' P' and t[20] == ' O' and t[21] == ' P'):
        points += 1
    if (t[20] == ' P' and t[21] == ' O' and t[22] == ' P'):
        points += 1
    if (t[21] == ' P' and t[22] == ' O' and t[23] == ' P'):
        points += 1

    # Horizontal Line 5
    if (t[24] == ' P' and t[25] == ' O' and t[26] == ' P'):
        points += 1
    if (t[25] == ' P' and t[26] == ' O' and t[27] == ' P'):
        points += 1
    if (t[26] == ' P' and t[27] == ' O' and t[28] == ' P'):
        points += 1
    if (t[27] == ' P' and t[28] == ' O' and t[29] == ' P'):
        points += 1

    # Horizontal Line 6
    if (t[30] == ' P' and t[31] == ' O' and t[32] == ' P'):
        points += 1
    if (t[31] == ' P' and t[32] == ' O' and t[33] == ' P'):
        points += 1
    if (t[32] == ' P' and t[33] == ' O' and t[34] == ' P'):
        points += 1
    if (t[33] == ' P' and t[34] == ' O' and t[35] == ' P'):
        points += 1


    # Vertical Line 1
    if (t[0] == ' P' and t[6] == ' O' and t[12] == ' P'):
        points += 1
    if (t[6] == ' P' and t[12] == ' O' and t[18] == ' P'):
        points += 1
    if (t[12] == ' P' and t[18] == ' O' and t[24] == ' P'):
        points += 1
    if (t[18] == ' P' and t[24] == ' O' and t[30] == ' P'):
        points += 1

    # Vertical Line 2
    if (t[1] == ' P' and t[7] == ' O' and t[13] == ' P'):
        points += 1
    if (t[7] == ' P' and t[13] == ' O' and t[19] == ' P'):
        points += 1
    if (t[13] == ' P' and t[19] == ' O' and t[25] == ' P'):
        points += 1
    if (t[19] == ' P' and t[25] == ' O' and t[31] == ' P'):
        points += 1

    # Vertical Line 3
    if (t[2] == ' P' and t[8] == ' O' and t[14] == ' P'):
        points += 1
    if (t[8] == ' P' and t[14] == ' O' and t[20] == ' P'):
        points += 1
    if (t[14] == ' P' and t[20] == ' O' and t[26] == ' P'):
        points += 1
    if (t[20] == ' P' and t[26] == ' O' and t[32] == ' P'):
        points += 1

    # Vertical Line 4
    if (t[3] == ' P' and t[9] == ' O' and t[15] == ' P'):
        points += 1
    if (t[9] == ' P' and t[15] == ' O' and t[21] == ' P'):
        points += 1
    if (t[15] == ' P' and t[21] == ' O' and t[27] == ' P'):
        points += 1
    if (t[21] == ' P' and t[27] == ' O' and t[33] == ' P'):
        points += 1

    # Vertical Line 5
    if (t[4] == ' P' and t[10] == ' O' and t[16] == ' P'):
        points += 1
    if (t[10] == ' P' and t[16] == ' O' and t[22] == ' P'):
        points += 1
    if (t[16] == ' P' and t[22] == ' O' and t[28] == ' P'):
        points += 1
    if (t[22] == ' P' and t[28] == ' O' and t[34] == ' P'):
        points += 1

    # Vertical Line 6
    if (t[5] == ' P' and t[11] == ' O' and t[17] == ' P'):
        points += 1
    if (t[11] == ' P' and t[17] == ' O' and t[23] == ' P'):
        points += 1
    if (t[17] == ' P' and t[23] == ' O' and t[29] == ' P'):
        points += 1
    if (t[23] == ' P' and t[29] == ' O' and t[35] == ' P'):
        points += 1


    # Left to Right Cross Line 1
    if (t[3] == ' P' and t[10] == ' O' and t[17] == ' P'):
        points += 1

    # Left to Right Cross Line 2
    if (t[2] == ' P' and t[9] == ' O' and t[16] == ' P'):
        points += 1
    if (t[9] == ' P' and t[16] == ' O' and t[23] == ' P'):
        points += 1

    # Left to Right Cross Line 3
    if (t[1] == ' P' and t[8] == ' O' and t[15] == ' P'):
        points += 1
    if (t[8] == ' P' and t[15] == ' O' and t[22] == ' P'):
        points += 1
    if (t[15] == ' P' and t[22] == ' O' and t[29] == ' P'):
        points += 1

    # Left to Right Cross Line 4
    if (t[0] == ' P' and t[7] == ' O' and t[14] == ' P'):
        points += 1
    if (t[7] == ' P' and t[14] == ' O' and t[21] == ' P'):
        points += 1
    if (t[14] == ' P' and t[21] == ' O' and t[28] == ' P'):
        points += 1
    if (t[21] == ' P' and t[28] == ' O' and t[35] == ' P'):
        points += 1

    # Left to Right Cross Line 5
    if (t[6] == ' P' and t[13] == ' O' and t[20] == ' P'):
        points += 1
    if (t[13] == ' P' and t[20] == ' O' and t[27] == ' P'):
        points += 1
    if (t[20] == ' P' and t[27] == ' O' and t[34] == ' P'):
        points += 1

    # Left to Right Cross Line 6
    if (t[12] == ' P' and t[19] == ' O' and t[26] == ' P'):
        points += 1
    if (t[19] == ' P' and t[26] == ' O' and t[33] == ' P'):
        points += 1

    # Left to Right Cross Line 7
    if (t[18] == ' P' and t[25] == ' O' and t[32] == ' P'):
        points += 1


    # Right to Left Cross Line 1
    if (t[2] == ' P' and t[7] == ' O' and t[12] == ' P'):
        points += 1

    # Right to Left Cross Line 2
    if (t[3] == ' P' and t[8] == ' O' and t[13] == ' P'):
        points += 1
    if (t[8] == ' P' and t[13] == ' O' and t[18] == ' P'):
        points += 1

    # Right to Left Cross Line 3
    if (t[4] == ' P' and t[9] == ' O' and t[14] == ' P'):
        points += 1
    if (t[9] == ' P' and t[14] == ' O' and t[19] == ' P'):
        points += 1
    if (t[14] == ' P' and t[19] == ' O' and t[24] == ' P'):
        points += 1

    # Right to Left Cross Line 4
    if (t[5] == ' P' and t[10] == ' O' and t[15] == ' P'):
        points += 1
    if (t[10] == ' P' and t[15] == ' O' and t[20] == ' P'):
        points += 1
    if (t[15] == ' P' and t[20] == ' O' and t[25] == ' P'):
        points += 1
    if (t[20] == ' P' and t[25] == ' O' and t[30] == ' P'):
        points += 1

    # Right to Left Cross Line 5
    if (t[11] == ' P' and t[16] == ' O' and t[21] == ' P'):
        points += 1
    if (t[16] == ' P' and t[21] == ' O' and t[26] == ' P'):
        points += 1
    if (t[21] == ' P' and t[26] == ' O' and t[31] == ' P'):
        points += 1

    # Right to Left Cross Line 6
    if (t[17] == ' P' and t[22] == ' O' and t[27] == ' P'):
        points += 1
    if (t[22] == ' P' and t[27] == ' O' and t[32] == ' P'):
        points += 1

    # Right to Left Cross Line 7
    if (t[23] == ' P' and t[28] == ' O' and t[33] == ' P'):
        points += 1
    # Final Count Of the Points are returned
    return points

def turn(player, tokenList): # This Function Will Place The P and O according to the player on the tokenlist.
    if (player == 1):
        icon = 'P'
    elif (player == 2):
        icon = 'O'

    print(f"Player{player}'s Turn...")
    printBox_PopPop(tokenList)
    turn = int(input(f"Type The Number of Position Where You Want To Place Your {icon} :- "))

    if (turn >= 1 and turn <= 9):
        tokenList.remove(f"0{turn}")
    else:
        tokenList.remove(f"{turn}")
    tokenList.insert((turn - 1), f" {icon}")

    return tokenList

tokenList = ['01', '02', '03', '04', '05', '06', '07', '08', '09', '10', '11', '12', '13', '14', '15', '16', '17', '18', '19', '20', '21', '22', '23', '24', '25', '26', '27', '28', '29', '30', '31', '32', '33', '34', '35', '36']

p1_Points = 0
p2_Points = 0
totalPoints = 1
r = 36
i = 1

while (i <= r):
    totalPoints = p1_Points + p2_Points
    print(f"The points of player1 are :- {p1_Points}")
    print(f"The points of player2 are :- {p2_Points}")

    if ((i % 2) == 1):
        tokenList = turn(1, tokenList)
        p1_Points += conditionCheck(tokenList) - totalPoints
        printBox_PopPop(tokenList)
        if (conditionCheck(tokenList) == totalPoints):
            i += 1
        else:
            r -= 1
    else:
        tokenList = turn(2, tokenList)
        p2_Points += conditionCheck(tokenList) - totalPoints
        printBox_PopPop(tokenList)
        if (conditionCheck(tokenList) == totalPoints):
            i += 1
        else:
            r -= 1

# Comparision of Both Players Points To Decide The Winner of The Game.
if(p1_Points > p2_Points): # If player1 has more points than player2 then he will win
    print(f'''
    Player1 wins the match by {p1_Points - p2_Points} Points.
       *** CONGRATULATIONS ***
             - For Player1's Victory.
    ''')
elif(p1_Points < p2_Points): # if player2 has more points than player1 then he will win
    print(f'''
    Player2 wins the match by {p2_Points - p1_Points} Points.
       *** CONGRATULATIONS ***
             - For Player2's Victory.
    ''')
else: # If Both players has equal points then the match will be tied.
    print(f'''
    OMG!!! The match is tied.
    Better luck next time.
    Both players have {p1_Points} Points.
    ''')