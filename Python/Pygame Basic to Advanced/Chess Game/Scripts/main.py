import pygame
import sys

import game_objects as obj
import game_constants as const

size = 82.5
temp = pygame.transform.scale(pygame.image.load("Python\\Pygame Basic to Advanced\\Snake & Ladders Game\\Assets\\Dice Sprites\\One_dice.jpg").convert_alpha(), (size, size))

def welcomeScreen():
    while True:
        pygame.display.update()
        obj.clock.tick(const.fps_Value)
        obj.game_Window.fill(const.blue)
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
        obj.clock.tick(const.fps_Value)
        obj.game_Window.fill(const.blue)
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_RETURN:
                    gameLoop()

def gameLoop():
    gameOver = False
    obj.Token()
    Game_Board = obj.Board()
    Game_Board.reset_board()

    while not gameOver:
        pygame.display.update() # Updating Display.
        obj.clock.tick(const.fps_Value) # Setting The FPS Value For The Game.
        obj.game_Window.fill(const.background) # Filling The Display With Color.
        obj.game_Window.blit(obj.Board.board, (obj.Board.board_padding/2, obj.Board.board_padding/2))
        Game_Board.render_tokens()
        

        for event in pygame.event.get(): # Getting The Event In Pygame.
            if event.type == pygame.QUIT: # Checking If The Close Button Is Pressed.
                pygame.quit() # Quiting The Game...
                sys.exit() # Exiting All Functions...

            if event.type == pygame.MOUSEBUTTONDOWN: # Checking If Any Mouse Button Is Pressed.
                if event.button == pygame.BUTTON_LEFT: # Checking If The Left Mouse Button Is Pressed.
                    pass
            if event.type == pygame.KEYDOWN: # Checking If Any Key Is Pressed.
                if event.key == pygame.K_RETURN: # Checking If Enter(Return) Key Is Pressed.
                    pass

    if gameOver == True: #Checking If The Game Is Over.
        endScreen() # Calling Ending Screen...

gameLoop() # Calling Welcome Screen...

"""

TOP LEFT:       70, 70
BOTTOM RIGHT:   732, 732


"""