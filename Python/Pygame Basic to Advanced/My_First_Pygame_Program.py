from traceback import print_tb
import pygame

pygame.init()
window = pygame.display.set_mode((1200, 500)) # Creating a New Window for Game.

pygame.display.set_caption("*** My First Game In Pygame. ***") # Setting the name of the window.

# Adding specific variables of the Game.
exit_Game = False
game_Over = False

# Creating a Game Loop:
while not exit_Game:
    for event in pygame.event.get():
        if event.type == pygame.QUIT :
            print("Pressed Close !!!")
            exit_Game = True
        
        if event.type == pygame.KEYDOWN :
            if event.key == pygame.K_RIGHT :
                print("Right Arrow Key is Pressed !!!")
            elif event.key == pygame.K_LEFT :
                print("Left Arrow Key is Pressed !!!")
            elif event.key == pygame.K_DOWN :
                print("Down Arrow Key is Pressed !!!")
            elif event.key == pygame.K_UP :
                print("Up Arrow Key is Pressed !!!")
            else:
                print("Unknown Key is Pressed !!!")

print('''*** HOPE YOU ENJOYED THE GAME ***
!!! BYE BYE !!!
Shutting Down...''')
pygame.quit()
quit()