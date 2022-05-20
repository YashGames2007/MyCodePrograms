import pygame
import sys
import random

def path(relative_path):
    import os, sys
    """ Get absolute path to resource, works for dev and for PyInstaller """
    try:
        # PyInstaller creates a temp folder and stores path in _MEIPASS
        base_path = sys._MEIPASS
    except Exception:
        base_path = os.path.abspath(".")

    return os.path.join(base_path, relative_path)
    
# Initializing Pygame Functions and Attributes...
pygame.init()
pygame.display.init()
pygame.mixer.init()

# Creating Global Constant Variables...
screen_Width = 650
screen_Height = 680
token_Width = 45
token_Height = 75
gameOver = False
fps_Value = 30
die_Size = 57

blockX = [10, 73, 136, 199, 260, 320, 380, 441, 502, 561]
blockY = [485, 435, 380, 320, 270, 220, 165, 110, 55, 0]

token_Positions = {1 : [blockX[0], blockY[0]],  2 : [blockX[1], blockY[0]],  3 : [blockX[2], blockY[0]],  4 : [blockX[3], blockY[0]],  5 : [blockX[4], blockY[0]],  6 : [blockX[5], blockY[0]],  7 : [blockX[6], blockY[0]],  8 : [blockX[7], blockY[0]],  9 : [blockX[8], blockY[0]],  10 : [blockX[9], blockY[0]],
                  11 : [blockX[9], blockY[1]], 12 : [blockX[8], blockY[1]], 13 : [blockX[7], blockY[1]], 14 : [blockX[6], blockY[1]], 15 : [blockX[5], blockY[1]], 16 : [blockX[4], blockY[1]], 17 : [blockX[3], blockY[1]], 18 : [blockX[2], blockY[1]], 19 : [blockX[1], blockY[1]],  20 : [blockX[0], blockY[1]],
                  21 : [blockX[0], blockY[2]], 22 : [blockX[1], blockY[2]], 23 : [blockX[2], blockY[2]], 24 : [blockX[3], blockY[2]], 25 : [blockX[4], blockY[2]], 26 : [blockX[5], blockY[2]], 27 : [blockX[6], blockY[2]], 28 : [blockX[7], blockY[2]], 29 : [blockX[8], blockY[2]],  30 : [blockX[9], blockY[2]],
                  31 : [blockX[9], blockY[3]], 32 : [blockX[8], blockY[3]], 33 : [blockX[7], blockY[3]], 34 : [blockX[6], blockY[3]], 35 : [blockX[5], blockY[3]], 36 : [blockX[4], blockY[3]], 37 : [blockX[3], blockY[3]], 38 : [blockX[2], blockY[3]], 39 : [blockX[1], blockY[3]],  40 : [blockX[0], blockY[3]],
                  41 : [blockX[0], blockY[4]], 42 : [blockX[1], blockY[4]], 43 : [blockX[2], blockY[4]], 44 : [blockX[3], blockY[4]], 45 : [blockX[4], blockY[4]], 46 : [blockX[5], blockY[4]], 47 : [blockX[6], blockY[4]], 48 : [blockX[7], blockY[4]], 49 : [blockX[8], blockY[4]],  50 : [blockX[9], blockY[4]],
                  51 : [blockX[9], blockY[5]], 52 : [blockX[8], blockY[5]], 53 : [blockX[7], blockY[5]], 54 : [blockX[6], blockY[5]], 55 : [blockX[5], blockY[5]], 56 : [blockX[4], blockY[5]], 57 : [blockX[3], blockY[5]], 58 : [blockX[2], blockY[5]], 59 : [blockX[1], blockY[5]],  60 : [blockX[0], blockY[5]],
                  61 : [blockX[0], blockY[6]], 62 : [blockX[1], blockY[6]], 63 : [blockX[2], blockY[6]], 64 : [blockX[3], blockY[6]], 65 : [blockX[4], blockY[6]], 66 : [blockX[5], blockY[6]], 67 : [blockX[6], blockY[6]], 68 : [blockX[7], blockY[6]], 69 : [blockX[8], blockY[6]],  70 : [blockX[9], blockY[6]],
                  71 : [blockX[9], blockY[7]], 72 : [blockX[8], blockY[7]], 73 : [blockX[7], blockY[7]], 74 : [blockX[6], blockY[7]], 75 : [blockX[5], blockY[7]], 76 : [blockX[4], blockY[7]], 77 : [blockX[3], blockY[7]], 78 : [blockX[2], blockY[7]], 79 : [blockX[1], blockY[7]],  80 : [blockX[0], blockY[7]],
                  81 : [blockX[0], blockY[8]], 82 : [blockX[1], blockY[8]], 83 : [blockX[2], blockY[8]], 84 : [blockX[3], blockY[8]], 85 : [blockX[4], blockY[8]], 86 : [blockX[5], blockY[8]], 87 : [blockX[6], blockY[8]], 88 : [blockX[7], blockY[8]], 89 : [blockX[8], blockY[8]],  90 : [blockX[9], blockY[8]],
                  91 : [blockX[9], blockY[9]], 92 : [blockX[8], blockY[9]], 93 : [blockX[7], blockY[9]], 94 : [blockX[6], blockY[9]], 95 : [blockX[5], blockY[9]], 96 : [blockX[4], blockY[9]], 97 : [blockX[3], blockY[9]], 98 : [blockX[2], blockY[9]], 99 : [blockX[1], blockY[9]], 100 : [blockX[0], blockY[9]],
                  0 : [-100, -100]
}

# Adding Some Colors...
white = (255, 255, 255)
black = (0, 0, 0)
red = (255, 0, 0)
green = (0, 255, 0)
blue = (0, 0, 255)

# Activating Defaults...
clock = pygame.time.Clock()
game_Window = pygame.display.set_mode((screen_Width, screen_Height))
pygame.display.set_caption("Snake And Ladders - YashGames2007")

# Adding Assets...
# Playing Board
game_Board = pygame.transform.scale(pygame.image.load(path("Pygame Basic to Advanced\\Snake & Ladders Game\\Assets\\board.jpg")).convert_alpha(), (screen_Width, screen_Height - 110))
dice_Box = pygame.transform.scale(pygame.image.load(path("Pygame Basic to Advanced\\Snake & Ladders Game\\Assets\\Dice Sprites\\diceBox.png")).convert_alpha(), (75, 75))
# Dice Sprites
dice = [
    pygame.transform.scale(pygame.image.load(path("Pygame Basic to Advanced\\Snake & Ladders Game\Assets\\Dice Sprites\\One_dice.jpg")).convert_alpha(), (die_Size, die_Size)),
    pygame.transform.scale(pygame.image.load(path("Pygame Basic to Advanced\\Snake & Ladders Game\Assets\\Dice Sprites\\Two_dice.jpg")).convert_alpha(), (die_Size, die_Size)),
    pygame.transform.scale(pygame.image.load(path("Pygame Basic to Advanced\\Snake & Ladders Game\Assets\\Dice Sprites\\Three_dice.jpg")).convert_alpha(), (die_Size, die_Size)),
    pygame.transform.scale(pygame.image.load(path("Pygame Basic to Advanced\\Snake & Ladders Game\Assets\\Dice Sprites\\Four_dice.jpg")).convert_alpha(), (die_Size, die_Size)),
    pygame.transform.scale(pygame.image.load(path("Pygame Basic to Advanced\\Snake & Ladders Game\Assets\\Dice Sprites\\Five_dice.jpg")).convert_alpha(), (die_Size, die_Size)),
    pygame.transform.scale(pygame.image.load(path("Pygame Basic to Advanced\\Snake & Ladders Game\Assets\\Dice Sprites\\Six_dice.jpg")).convert_alpha(), (die_Size, die_Size))
]
# Tokens
red_Token = pygame.transform.scale(pygame.image.load(path("Pygame Basic to Advanced\\Snake & Ladders Game\\Assets\\Player Tokens\\RedToken.png")).convert_alpha(), (token_Width, token_Height))
yellow_Token = pygame.transform.scale(pygame.image.load(path("Pygame Basic to Advanced\\Snake & Ladders Game\\Assets\\Player Tokens\\YellowToken.png")).convert_alpha(), (token_Width,token_Height))
blue_Token = pygame.transform.scale(pygame.image.load(path("Pygame Basic to Advanced\\Snake & Ladders Game\\Assets\\Player Tokens\\BlueToken.png")).convert_alpha(), (token_Width, token_Height))
green_Token = pygame.transform.scale(pygame.image.load(path("Pygame Basic to Advanced\\Snake & Ladders Game\\Assets\\Player Tokens\\GreenToken.png")).convert_alpha(), (token_Width, token_Height))

def snake_And_Ladders(current_Positions, token):
    ladder_Positions = {
        9 : 31,
        16 : 45,
        18 : 64,
        48 : 66,
        50 : 93,
        63 : 81
    }
    snake_Positions = {
        32 : 6,
        74 : 22,
        86 : 51,
        99 : 39
    }
    
    if current_Positions[token - 1] in ladder_Positions:
        for i in range(3):
            temp = current_Positions[token - 1]
            current_Positions[token - 1] = 0
            game_Window.fill(green)
            game_Window.blit(game_Board, (0, 35))
            setTokens(current_Positions)
            pygame.display.update()
            clock.tick(fps_Value)
            pygame.time.delay(50)
            current_Positions[token - 1] = temp
            game_Window.fill(green)
            game_Window.blit(game_Board, (0, 35))
            setTokens(current_Positions)
            pygame.display.update()
            clock.tick(fps_Value)
        current = current_Positions[token - 1]
        current_Positions[token - 1] = ladder_Positions[current_Positions[token - 1]]
        game_Window.fill(green)
        game_Window.blit(game_Board, (0, 35))
        setTokens(current_Positions)
        pygame.display.update()
        clock.tick(fps_Value)
        return current_Positions[token - 1] - current
    elif current_Positions[token - 1] in snake_Positions:
        for i in range(3):
            temp = current_Positions[token - 1]
            current_Positions[token - 1] = 0
            game_Window.fill(green)
            game_Window.blit(game_Board, (0, 35))
            setTokens(current_Positions)
            pygame.display.update()
            clock.tick(fps_Value)
            pygame.time.delay(50)
            current_Positions[token - 1] = temp
            game_Window.fill(green)
            game_Window.blit(game_Board, (0, 35))
            setTokens(current_Positions)
            pygame.display.update()
            clock.tick(fps_Value)
        current = current_Positions[token - 1]
        current_Positions[token - 1] = snake_Positions[current_Positions[token - 1]]
        game_Window.fill(green)
        game_Window.blit(game_Board, (0, 35))
        setTokens(current_Positions)
        pygame.display.update()
        clock.tick(fps_Value)
        return current_Positions[token - 1] - current
    else:
        return None


def setTokens(current_Positions, token = 0, throw = 0):
    if token == 0:
        game_Window.blit(red_Token, ((token_Positions[current_Positions[0]][0]), (token_Positions[current_Positions[0]][1])))
        game_Window.blit(yellow_Token, ((token_Positions[current_Positions[1]][0] + 30), (token_Positions[current_Positions[1]][1])))
        game_Window.blit(green_Token, ((token_Positions[current_Positions[3]][0] + 30), (token_Positions[current_Positions[3]][1] + 20)))
        game_Window.blit(blue_Token, ((token_Positions[current_Positions[2]][0]), (token_Positions[current_Positions[2]][1] + 20)))
        pygame.display.update()
        pygame.time.delay(500)
    elif token == 1:
        if current_Positions[0] == 1:
            for i in range(throw - 1):
                current_Positions[0] += 1
                pygame.display.update()
                game_Window.fill(green)
                game_Window.blit(game_Board, (0, 35))
                setTokens(current_Positions)
            return throw - 1
        else:
            for i in range(throw):
                current_Positions[0] += 1
                pygame.display.update()
                game_Window.fill(green)
                game_Window.blit(game_Board, (0, 35))
                setTokens(current_Positions)
            result = snake_And_Ladders(current_Positions, 1)
            if result != None:
                return result + throw
            return throw

    elif token == 2:
        if current_Positions[1] == 1:
            for i in range(throw - 1):
                current_Positions[1] += 1
                pygame.display.update()
                clock.tick(fps_Value)
                game_Window.fill(green)
                game_Window.blit(game_Board, (0, 35))
                setTokens(current_Positions)
            return throw - 1
        else:
            for i in range(throw):
                current_Positions[1] += 1
                pygame.display.update()
                clock.tick(fps_Value)
                game_Window.fill(green)
                game_Window.blit(game_Board, (0, 35))
                setTokens(current_Positions)
            result = snake_And_Ladders(current_Positions, 2)
            if result != None:
                return result + throw
            return throw
    elif token == 3:
        if current_Positions[2] == 1:
            for i in range(throw - 1):
                current_Positions[2] += 1
                pygame.display.update()
                clock.tick(fps_Value)
                game_Window.fill(green)
                game_Window.blit(game_Board, (0, 35))
                setTokens(current_Positions)
            return throw - 1
        else:
            for i in range(throw):
                current_Positions[2] += 1
                pygame.display.update()
                clock.tick(fps_Value)
                game_Window.fill(green)
                game_Window.blit(game_Board, (0, 35))
                setTokens(current_Positions)
            result = snake_And_Ladders(current_Positions, 3)
            if result != None:
                return result + throw
            return throw
    elif token == 4:
        if current_Positions[3] == 1:
            for i in range(throw - 1):
                current_Positions[3] += 1
                pygame.display.update()
                clock.tick(fps_Value)
                game_Window.fill(green)
                game_Window.blit(game_Board, (0, 35))
                setTokens(current_Positions)
            return throw - 1
        else:
            for i in range(throw):
                current_Positions[3] += 1
                pygame.display.update()
                clock.tick(fps_Value)
                game_Window.fill(green)
                game_Window.blit(game_Board, (0, 35))
                setTokens(current_Positions)
            result = snake_And_Ladders(current_Positions, 4)
            if result != None:
                return result + throw
            return throw

def throwDice():
    diceBoxPosition = (290, 605)
    dicePosition = (299, 614)
    game_Window.blit(dice_Box, diceBoxPosition)
    for j in range (3):
        for i in range (6):
            game_Window.blit(dice[i], dicePosition)
            pygame.display.update()
            pygame.time.delay(100)
    current = random.randint(0, 5)
    game_Window.blit(dice[current], dicePosition)
    pygame.display.update()
    pygame.time.delay(1500)
    return current + 1

def welcomeScreen():
    while True:
        pygame.display.update()
        clock.tick(fps_Value)
        game_Window.fill(blue)
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_RETURN:
                    gameLoop()

def endScreen():
    while True:
        pygame.display.update()
        clock.tick(fps_Value)
        game_Window.fill(blue)
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_RETURN:
                    gameLoop()

def gameLoop():
    red_Turn = 1
    yellow_Turn = 1
    green_Turn = 1
    blue_Turn = 1
    turn = 1
    while not gameOver:
        current_Positions = [red_Turn, yellow_Turn, green_Turn, blue_Turn]
        pygame.display.update() # Updating Display.
        clock.tick(fps_Value) # Setting The FPS Value For The Game.
        game_Window.fill(green) # Filling The Display With Color.
        game_Window.blit(game_Board, (0, 35))
        setTokens(current_Positions)

        for event in pygame.event.get(): # Getting The Event In Pygame.
            if event.type == pygame.QUIT: # Checking If The Close Button Is Pressed.
                pygame.quit() # Quiting The Game...
                sys.exit() # Exiting All Functions...

            if event.type == pygame.MOUSEBUTTONDOWN: # Checking If Any Mouse Button Is Pressed.
                if event.button == pygame.BUTTON_LEFT: # Checking If The Left Mouse Button Is Pressed.
                    pass
            if event.type == pygame.KEYDOWN: # Checking If Any Key Is Pressed.
                if event.key == pygame.K_0: # Checking If Enter(Return) Key Is Pressed.
                    pass
                if event.key == pygame.K_1:
                    pass
                if event.key == pygame.K_RETURN:
                    throw = throwDice()
                    # Checking The Turn...
                    if turn == 1:
                        red_Turn += setTokens(current_Positions, 1, throw)
                    elif turn == 2:
                        yellow_Turn += setTokens(current_Positions, 2, throw)
                    elif turn == 3:
                        green_Turn += setTokens(current_Positions, 3, throw)
                    elif turn == 4:
                        blue_Turn += setTokens(current_Positions, 4, throw)
                    turn += 1
                    if turn == 5:
                        turn = 1
                    
    if gameOver == True: #Checking If The Game Is Over.
        endScreen() # Calling Ending Screen...

# welcomeScreen() # Calling Welcome Screen...
gameLoop()