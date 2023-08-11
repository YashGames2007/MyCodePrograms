import pygame
import sys

# Initializing Pygame Functions and Attributes...
pygame.init()
pygame.display.init()
# pygame.mixer.init()

# Creating Global Constant Variables...
screen_Width = 800
screen_Height = 800
gameOver = False
fps_Value = 30

# Adding Some Colors...
white = (255, 255, 255)
black = (0, 0, 0)
red = (255, 0, 0)
green = (0, 255, 0)
blue = (0, 0, 255)
background = (255, 191, 141)


size = 82.5
# Activating Defaults...
clock = pygame.time.Clock()
game_Window = pygame.display.set_mode((screen_Width, screen_Height))
pygame.display.set_caption("Chess - YashGames2007")
temp = pygame.transform.scale(pygame.image.load("Python\\Pygame Basic to Advanced\\Snake & Ladders Game\\Assets\\Dice Sprites\\One_dice.jpg").convert_alpha(), (size, size))

# TODO: Change these values
block = [68.5, 151, 235.5, 317, 401.5, 484, 567.5, 651]

board_positions = [[(x, y) for y in block] for x in block]
print(board_positions[7][7])
token_size_ratio = 6.52174 # Increase size of every game object by this ratio

class Token:
    # TODO: Add relational size to all tokens
    white_tokens = {
        "pawn": pygame.transform.scale(pygame.image.load("Python/Pygame Basic to Advanced/Chess Game/Assets/white tokens/pawn.png").convert_alpha(), (9*token_size_ratio, 24.9*token_size_ratio)),
        "rock": pygame.transform.scale(pygame.image.load("Python/Pygame Basic to Advanced/Chess Game/Assets/white tokens/rock.png").convert_alpha(), (9.1*token_size_ratio, 23.1*token_size_ratio)),
        "knight": pygame.transform.scale(pygame.image.load("Python/Pygame Basic to Advanced/Chess Game/Assets/white tokens/knight.png").convert_alpha(), (9.7*token_size_ratio, 24.8*token_size_ratio)),
        "bishop": pygame.transform.scale(pygame.image.load("Python/Pygame Basic to Advanced/Chess Game/Assets/white tokens/bishop.png").convert_alpha(), (9.7*token_size_ratio, 22*token_size_ratio)),
        "queen": pygame.transform.scale(pygame.image.load("Python/Pygame Basic to Advanced/Chess Game/Assets/white tokens/queen.png").convert_alpha(), (9.9*token_size_ratio, 19.4*token_size_ratio)),
        "king": pygame.transform.scale(pygame.image.load("Python/Pygame Basic to Advanced/Chess Game/Assets/white tokens/king.png").convert_alpha(), (9.7*token_size_ratio, 18.8*token_size_ratio))
    }
    black_tokens = {
        "pawn": pygame.transform.scale(pygame.image.load("Python/Pygame Basic to Advanced/Chess Game/Assets/black tokens/pawn.png").convert_alpha(), (9*token_size_ratio, 24.9*token_size_ratio)),
        "rock": pygame.transform.scale(pygame.image.load("Python/Pygame Basic to Advanced/Chess Game/Assets/black tokens/rock.png").convert_alpha(), (9.1*token_size_ratio, 23.1*token_size_ratio)),
        "knight": pygame.transform.scale(pygame.image.load("Python/Pygame Basic to Advanced/Chess Game/Assets/black tokens/knight.png").convert_alpha(), (9.7*token_size_ratio, 24.8*token_size_ratio)),
        "bishop": pygame.transform.scale(pygame.image.load("Python/Pygame Basic to Advanced/Chess Game/Assets/black tokens/bishop.png").convert_alpha(), (9.7*token_size_ratio, 22*token_size_ratio)),
        "queen": pygame.transform.scale(pygame.image.load("Python/Pygame Basic to Advanced/Chess Game/Assets/black tokens/queen.png").convert_alpha(), (9.9*token_size_ratio, 19.4*token_size_ratio)),
        "king": pygame.transform.scale(pygame.image.load("Python/Pygame Basic to Advanced/Chess Game/Assets/black tokens/king.png").convert_alpha(), (9.7*token_size_ratio, 18.8*token_size_ratio))
    }

    token_ofset = {
        "pawn": (10, -100)
    }

    @classmethod
    def render(cls, token_name:str, pos_x, pos_y) -> None:
        tokens = cls.white_tokens if "white" in token_name else cls.black_tokens
        token_name = token_name.replace("white", "").replace("black", "").replace(" ", "")

        position = board_positions[pos_x][pos_y]
        ofset = cls.token_ofset[token_name]
        game_Window.blit(tokens[token_name], (position[0]+ofset[0], position[1]+ofset[1]))

class Board:
    board_padding = 50  #Making the board 50 pixel smaller than game_Window
    board = pygame.transform.scale(pygame.image.load("Python/Pygame Basic to Advanced/Chess Game/Assets/board.jpg").convert_alpha(), (115*token_size_ratio, 115*token_size_ratio))

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
    x_ofset = 10
    y_ofset = -100
    while not gameOver:
        pygame.display.update() # Updating Display.
        clock.tick(fps_Value) # Setting The FPS Value For The Game.
        game_Window.fill(background) # Filling The Display With Color.
        game_Window.blit(Board.board, (Board.board_padding/2, Board.board_padding/2))
        # game_Window.blit(Token.white_tokens["pawn"], (board_positions[0][6][0]+x_ofset, board_positions[0][6][1]+y_ofset))
        Token.render("black pawn", 0, 0)
        Token.render("white pawn", 0, 1)


        # print(pygame.mouse.get_pos())

        for event in pygame.event.get(): # Getting The Event In Pygame.
            if event.type == pygame.QUIT: # Checking If The Close Button Is Pressed.
                pygame.quit() # Quiting The Game...
                sys.exit() # Exiting All Functions...

            if event.type == pygame.MOUSEBUTTONDOWN: # Checking If Any Mouse Button Is Pressed.
                if event.button == pygame.BUTTON_LEFT: # Checking If The Left Mouse Button Is Pressed.
                    print(f"{pygame.mouse.get_pos()} CLICKED")
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