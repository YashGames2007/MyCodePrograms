import pygame, random, sys

pygame.display.init()
pygame.mixer.init()
pygame.init() # Initializing Pygame Engine...

fps = 30
clock = pygame.time.Clock() 

def path(relative_path):
    import os, sys
    """ Get absolute path to resource, works for dev and for PyInstaller """
    try:
        # PyInstaller creates a temp folder and stores path in _MEIPASS
        base_path = sys._MEIPASS
    except Exception:
        base_path = os.path.abspath(".")

    return os.path.join(base_path, relative_path)

# Adding Some Sound Effects
bg_Sound = pygame.mixer.Sound(path('Pygame Basic to Advanced\\Snake And The Food Game\\backGround.mp3'))
eat_Sound = pygame.mixer.Sound(path('Pygame Basic to Advanced\\Snake And The Food Game\\EatFood.mp3'))
start_Sound = pygame.mixer.Sound(path('Pygame Basic to Advanced\\Snake And The Food Game\\StartGame.mp3'))
gameOver_Sound = pygame.mixer.Sound(path('Pygame Basic to Advanced\\Snake And The Food Game\\GameOver.mp3'))
highScore_Sound = pygame.mixer.Sound(path('Pygame Basic to Advanced\\Snake And The Food Game\\NewHighScore.mp3'))
cheatCodeOn_Sound = pygame.mixer.Sound(path('Pygame Basic to Advanced\\Snake And The Food Game\\ActivateCheatCode.mp3'))
cheatCodeOff_Sound = pygame.mixer.Sound(path('Pygame Basic to Advanced\\Snake And The Food Game\\DeactivateCheatCode.mp3'))

# Creating Window:
screen_Width = 900
screen_Height = 600
gameWindow = pygame.display.set_mode((screen_Width, screen_Height)) # Creating Window Screen for the Game.

# Adding Background Image
bg_Image = pygame.image.load(path('Pygame Basic to Advanced\\Snake And The Food Game\\background.png'))
bg_Image = pygame.transform.scale(bg_Image, (screen_Width, screen_Height)).convert_alpha()

# Core Initialization. 
pygame.display.set_caption("Snake & The Food Game - YashGames2007") # Adding Text on Title Bar
pygame.display.update()


def display_Text(text_String, text_Color, text_Position_X, text_Position_Y):
    font = pygame.font.SysFont("cascadia code", 55)
    screen_Text = font.render(text_String, True, text_Color)
    gameWindow.blit(screen_Text, [text_Position_X, text_Position_Y])

def plot_Snake(gameWindow, color, snake_List, snake_Size, head):
    # print(snake_List)
    pink = (255, 10, 250)
    pygame.draw.rect(gameWindow, pink, [head[0], head[1], snake_Size, snake_Size])
    for x, y in snake_List[: -1]:
        pygame.draw.rect(gameWindow, color, [x, y, snake_Size, snake_Size]) # Drawing Snake.

def welcome():
    exit_Game = False
     # Adding Some Colors:
    white = (255, 255, 255)
    red = (255, 0, 0)
    orange = (255, 150, 10)
    
    while not exit_Game:
        gameWindow.fill(white)
        gameWindow.blit(bg_Image, (0, 0))
        display_Text("!!! Welcome To Snake And The Food Game !!!", red, ((screen_Width/2) - 420), ((screen_Height/2) - 100))
        display_Text("Press Any Key To Start.", orange, ((screen_Width/2) - 220), ((screen_Height/2) - 50))

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                exit_Game = True
            if event.type == pygame.KEYDOWN:
                start_Sound.play(0)
                pygame.time.wait(int(start_Sound.get_length() * 1000))
                bg_Sound.play(-1)
                game_Loop()

        pygame.display.update()
        clock.tick(fps)

def game_Loop():
    # Computing Some Variables & Constants:
    snake_X = 45
    snake_Y = 55
    block_Size = 14
    velocity_X = 0
    velocity_Y = 0
    snake_Speed = 6
    food_X = random.randint(100, screen_Width- 100)
    food_Y = random.randint(100, screen_Height- 100)
    score = 0
    cheat_Code = False
    snake_List = []
    snake_Lenght = 1

    # Adding Some Colors:
    white = (255, 255, 255)
    pink = (255, 10, 250)
    red = (255, 0, 0)
    green = (50, 255, 50)
    orange = (255, 150, 10)

    # Initializing Game Specific Variables...
    exit_Game = False
    game_Over = False
    game_Sound_Check = 0 #Taking an variable to run the end sound once
    # Reading High Score File
    with open(path("Pygame Basic to Advanced\\Snake And The Food Game\\highScore.txt"), "r") as f:
        high_Score = f.read()
    
    # Creating Game Loop:
    while not exit_Game :
        if game_Over:

            bg_Sound.stop()
            with open(path("Pygame Basic to Advanced\\Snake And The Food Game\\highScore.txt"), "w") as f:
                f.write(high_Score)

            gameWindow.fill(white)
            gameWindow.blit(bg_Image, (0, 0))
            if score != 0:
                if (score) >= (int(high_Score)):
                    if game_Sound_Check == 0:
                        highScore_Sound.play(0)
                        game_Sound_Check += 1
                    display_Text("Congratulations !!! You Broke The High Score.", pink, ((screen_Width/2) - 400), ((screen_Height/2) + 150))
            
            else:
                if game_Sound_Check == 0:
                        gameOver_Sound.play(0)
                        game_Sound_Check += 1
                display_Text(f"Target Score: {high_Score}.", green, ((screen_Width/2) - 150), ((screen_Height/2) + 100))

            display_Text("!!! Game Over !!!", pink, ((screen_Width/2) - 150), ((screen_Height/2) - 200))
            display_Text("Better Luck Next Time.", red, ((screen_Width/2) - 200), ((screen_Height/2) - 150))
            display_Text(f"Total Score In This Round: {score}", orange, ((screen_Width/2) - 250), ((screen_Height/2) - 100))
            display_Text("Press Enter To Restart The Game.", green, ((screen_Width/2) - 300), ((screen_Height/2) + 50))


            for event in pygame.event.get():
                # print(event)
                if event.type == pygame.QUIT : # Initializing Close.
                    
                    with open(path("Pygame Basic to Advanced\Snake And The Food Game\highScore.txt"), "w") as f:
                        f.write("00")

                    exit_Game = True
                
                if event.type == pygame.KEYDOWN :
                    # If Any Key is Pressed:
                    if event.key == pygame.K_RETURN :
                        start_Sound.play(0)
                        pygame.time.wait(int(start_Sound.get_length() * 1000))
                        bg_Sound.play(-1)
                        game_Loop()
        else:
            for event in pygame.event.get():
                # print(event)
                
                if event.type == pygame.QUIT : # Initializing Close.
                    exit_Game = True

                if event.type == pygame.KEYDOWN :
                    # If Any Key is Pressed:
                    if event.key == pygame.K_RIGHT :
                        velocity_X = snake_Speed
                        velocity_Y = 0
                    
                    if event.key == pygame.K_LEFT :
                        velocity_X = - snake_Speed
                        velocity_Y = 0
                    
                    if event.key == pygame.K_UP :
                        velocity_Y = - snake_Speed
                        velocity_X = 0
                    
                    if event.key == pygame.K_DOWN :
                        velocity_Y = snake_Speed
                        velocity_X = 0

                    if event.key == pygame.K_q:
                        score += 10

                    if event.key == pygame.K_t:
                        cheatCodeOn_Sound.play(0)
                        cheat_Code = True
                    
                    if event.key == pygame.K_f:
                        cheatCodeOff_Sound.play(0)
                        cheat_Code = False

            snake_X += velocity_X
            snake_Y += velocity_Y

            if abs(snake_X - food_X) < 15 and abs(snake_Y - food_Y) < 15 :
                score += 10
                snake_Lenght += 5

                eat_Sound.play(0)

                if score > int(high_Score) :
                    high_Score = str(score)

                food_X = random.randint(100, screen_Width-100)
                food_Y = random.randint(100, screen_Height-100)

            gameWindow.fill(white)
            gameWindow.blit(bg_Image, (0, 0))
            display_Text(f"Score: {score}, High Score: {high_Score}", orange, 5, 5)
            pygame.draw.rect(gameWindow, red, [food_X, food_Y, block_Size, block_Size]) # Drawing Food.
            # pygame.draw.rect(gameWindow, green, [snake_X, snake_Y, block_Size, block_Size]) # Drawing Snake.

            head = []
            head.append(snake_X)
            head.append(snake_Y)
            snake_List.append(head)

            if len(snake_List) > snake_Lenght :
                del snake_List[0]

            if cheat_Code:

                if snake_X <= 0:
                    snake_X = screen_Width
                elif snake_X >= screen_Width:
                    snake_X = 0

                if snake_Y <= 0:
                    snake_Y = screen_Height
                elif snake_Y >= screen_Height:
                    snake_Y = 0

            else:
                if head in snake_List[: -1]:
                    game_Over = True
                    # gameOver_Sound.play(0)

                if snake_X <= 0 or snake_Y <= 0 or snake_X >= screen_Width or snake_Y >= screen_Height:
                    game_Over = True
                    # print("Game Over !!!")
                    # gameOver_Sound.play(0)

            plot_Snake(gameWindow, green, snake_List, block_Size, head)

        pygame.display.update() # Upadating The Screen.
        clock.tick(fps)
            
    pygame.quit()
    sys.exit()

welcome()