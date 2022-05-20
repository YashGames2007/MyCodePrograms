def path(relative_path):
    import os, sys
    """ Get absolute path to resource, works for dev and for PyInstaller """
    try:
        # PyInstaller creates a temp folder and stores path in _MEIPASS
        base_path = sys._MEIPASS
    except Exception:
        base_path = os.path.abspath(".")

    return os.path.join(base_path, relative_path)

import sys
import pygame
pygame.init()
pygame.mixer.init()

# Creating Colors:
white = (255, 255, 255)

# Creating Window:
screen_Width = 500
screen_Height = 500
gameWindow = pygame.display.set_mode((screen_Width, screen_Height)) # Creating Window Screen for the Game.

fps = 30
clock = pygame.time.Clock()

# Creating Game Assets:
board = pygame.transform.scale(pygame.image.load(path("Pygame Basic To Advanced\\Tic Tac Toe Game\\board.png")).convert_alpha(), (screen_Width, screen_Height))
x_Token = pygame.transform.scale(pygame.image.load(path("Pygame Basic To Advanced\\Tic Tac Toe Game\\X_Token.jpg")).convert_alpha(), (110, 110))
o_Token = pygame.transform.scale(pygame.image.load(path("Pygame Basic To Advanced\Tic Tac Toe Game\\O_Token.jpg")).convert_alpha(), (110, 110))

# Music Initialization:
xSound = pygame.mixer.Sound(path("Pygame Basic To Advanced\\Tic Tac Toe Game\\xMusic.wav"))
oSound = pygame.mixer.Sound(path("Pygame Basic To Advanced\\Tic Tac Toe Game\\oMusic.wav"))
winSound = pygame.mixer.Sound(path("Pygame Basic To Advanced\\Tic Tac Toe Game\\winSound.wav"))
tieSound = pygame.mixer.Sound(path("Pygame Basic To Advanced\\Tic Tac Toe Game\\tieSound.wav"))

# Creating Values of Co-Ordinates of Cursor:
posX = [25, 146, 175, 311, 339, 475]
posY = [25, 146, 175, 311, 339, 475]

# Creating List for storing tuples of coordinates of X and O's:
token_Positions = [(30, 32), (190, 32), (354, 32), (30, 188), (190, 188), (354, 188),(30, 352), (190, 352), (354, 352)]

def display_Text(text_String, text_Color, text_Position_X, text_Position_Y):
    font = pygame.font.SysFont("cascadia code", 30)
    screen_Text = font.render(text_String, True, text_Color)
    gameWindow.blit(screen_Text, [text_Position_X, text_Position_Y])

def winScreen(winner):
    recursion = 0
    while True:
        pygame.display.update()
        gameWindow.fill(white)
        if winner == 1 or winner == 2:
            if recursion == 0:
                winSound.play()
                recursion = 1
            display_Text("""Congratulations !!!""", (255, 0, 0), 150, 200)
            display_Text(f"Player {winner} Win's The Match.!", (255, 0, 0), 120, 250)
        else:
            if recursion == 0:
                tieSound.play()
                recursion = 1
            display_Text("""!!! OH NO !!!""", (0, 0, 255), 150, 200)
            display_Text("""It's A Tie Match.!""", (0, 0, 255), 130, 250)
        display_Text('Press Enter To Restart The Game.!', (0, 0, 0), 100, 300)
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_RETURN:
                    gameLoop()

def victory(pos):
    if pos[1] == 'X' and pos[2] == 'X' and pos[3] == 'X':
        return 1
    elif pos[4] == 'X' and pos[5] == 'X' and pos[6] == 'X':
        return 1
    elif pos[7] == 'X' and pos[8] == 'X' and pos[9] == 'X':
        return 1
    elif pos[1] == 'X' and pos[4] == 'X' and pos[7] == 'X':
        return 1
    elif pos[2] == 'X' and pos[5] == 'X' and pos[8] == 'X':
        return 1
    elif pos[3] == 'X' and pos[6] == 'X' and pos[9] == 'X':
        return 1
    elif pos[1] == 'X' and pos[5] == 'X' and pos[9] == 'X':
        return 1
    elif pos[3] == 'X' and pos[5] == 'X' and pos[7] == 'X':
        return 1
    elif pos[1] == 'O' and pos[2] == 'O' and pos[3] == 'O':
        return 2
    elif pos[4] == 'O' and pos[5] == 'O' and pos[6] == 'O':
        return 2
    elif pos[7] == 'O' and pos[8] == 'O' and pos[9] == 'O':
        return 2
    elif pos[1] == 'O' and pos[4] == 'O' and pos[7] == 'O':
        return 2
    elif pos[2] == 'O' and pos[5] == 'O' and pos[8] == 'O':
        return 2
    elif pos[3] == 'O' and pos[6] == 'O' and pos[9] == 'O':
        return 2
    elif pos[1] == 'O' and pos[5] == 'O' and pos[9] == 'O':
        return 2
    elif pos[3] == 'O' and pos[5] == 'O' and pos[7] == 'O':
        return 2
    elif pos[1] == None and pos[2] == None and pos[3] == None and pos[4] == None and pos[5] == None and pos[6] == None and pos[7] == None and pos[8] == None and pos[9] == None:
        return 0
    elif pos[1] != None and pos[2] != None and pos[3] != None and pos[4] != None and pos[5] != None and pos[6] != None and pos[7] != None and pos[8] != None and pos[9] != None:
        return 3
    
def getBlock(mouseX, mouseY):
    if posX[0] < mouseX < posX[1]:
        if posY[0] < mouseY < posY[1]:
            return 1
        elif posY[2] < mouseY < posY[3]:
            return 4
        elif posY[4] < mouseY < posY[5]:
            return 7
    elif posX[2] < mouseX < posX[4]:
        if posY[0] < mouseY < posY[1]:
            return 2
        elif posY[2] < mouseY < posY[3]:
            return 5
        elif posY[4] < mouseY < posY[5]:
            return 8
    elif posX[4] < mouseX < posX[5]:
        if posY[0] < mouseY < posY[1]:
            return 3
        elif posY[2] < mouseY < posY[3]:
            return 6
        elif posY[4] < mouseY < posY[5]:
            return 9
    else:
        return 0

def setPlayer(positions_Dictionary):
    for i in range(1, 10):
        if positions_Dictionary[i] != None:
            if positions_Dictionary[i] == 'X':
                gameWindow.blit(x_Token, token_Positions[i - 1])
            elif positions_Dictionary[i] == 'O':
                gameWindow.blit(o_Token, token_Positions[i - 1])

def gameLoop():
    positions_Dictionary = {
    1 : None,
    2 : None,
    3 : None,
    4 : None,
    5 : None,
    6 : None,
    7 : None,
    8 : None,
    9 : None
}

    while True:
        pygame.display.update()
        gameWindow.fill(white)
        gameWindow.blit(board, (0, 0))
        setPlayer(positions_Dictionary)
        clock.tick(fps)

        if victory(positions_Dictionary) == 1:
            winner = 1
            winScreen(winner)
        elif victory(positions_Dictionary) == 2:
            winner = 2
            winScreen(winner)
        elif victory(positions_Dictionary) == 3:
            winner = 3
            winScreen(winner)
        elif victory(positions_Dictionary) == 0:
            player_Turn = 1
        
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()
            if event.type == pygame.MOUSEBUTTONDOWN:
                x, y = pygame.mouse.get_pos()
                block = getBlock(x, y)
                if block != 0 and block != None:
                    if positions_Dictionary[block] == None:
                        if player_Turn == 1:
                            xSound.play()
                            positions_Dictionary[block] = 'X'
                            player_Turn = 2
                        elif player_Turn == 2:
                            oSound.play()
                            positions_Dictionary[block] = 'O'
                            player_Turn = 1

gameLoop()    