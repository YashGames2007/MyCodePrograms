import pygame, random, sys, os
from pygame.locals import *

def path(relative_path):
    """ Get absolute path to resource, works for dev and for PyInstaller """
    try:
        # PyInstaller creates a temp folder and stores path in _MEIPASS
        base_path = sys._MEIPASS
    except Exception:
        base_path = os.path.abspath(".")

    return os.path.join(base_path, relative_path)

def display_Text(text_String, text_Color, text_Position_X, text_Position_Y):
    font = pygame.font.SysFont("cascadia code", 55)
    screen_Text = font.render(text_String, True, text_Color)
    game_Screen.blit(screen_Text, [text_Position_X, text_Position_Y])

def is_Collide(player_X, player_Y, upper_Pipes, lower_Pipes):
    if player_Y > (ground_Y - (game_Sprites['player'].get_height() * 1.2)) or player_Y < 0:
        game_Sounds['hit'].play()
        return True
    for pipe in upper_Pipes:
        pipe_Height = game_Sprites['pipe'][0].get_height()

        if player_Y < (pipe_Height + pipe['Y']) and (abs(player_X - pipe['X'])) < (game_Sprites['pipe'][0].get_width() / 2):
            game_Sounds['hit'].play()
            return True

    for pipe in lower_Pipes:
        if (player_Y + game_Sprites['player'].get_height()) > pipe['Y'] and (abs(player_X - pipe['X'])) < (game_Sprites['pipe'][0].get_width() / 2):
            game_Sounds['hit'].play()
            return True
    
    return False

def random_Pipe_Generator():
    pipe_Height = game_Sprites['pipe'][0].get_height()
    offset = screen_Height / 2.5
    pipe2_Y = offset + random.randrange(0, int(screen_Height - game_Sprites['base'].get_height() - 1.2 * offset))
    pipe_X = screen_Width + 10
    pipe1_Y = pipe_Height - pipe2_Y + offset
    pipe = [
        {'X' : pipe_X, 'Y' : - pipe1_Y},
        {'X' : pipe_X, 'Y' : + pipe2_Y}
    ]
    return pipe

def welcome_Screen(score = 0):
    
    player_X = int(screen_Width / 5)
    player_Y = int((screen_Height - game_Sprites['player'].get_height()) / 2)

    logo_X = int((screen_Width - game_Sprites['logo'].get_width()) / 2) - 15
    logo_Y = 0

    base_X = 0

    while True:
        for event in pygame.event.get():
            if event.type == QUIT or (event.type == KEYDOWN and event.key == K_ESCAPE):
                pygame.quit()
                sys.exit()

            elif event.type == KEYDOWN and (event.key == K_SPACE or event.key == K_UP):
                backGround_Music.play(-1)
                return

            
        pygame.display.update()
        fps_Clock.tick(FPS)
        game_Screen.blit(game_Sprites['backGround'], (0, 0))
        game_Screen.blit(game_Sprites['player'], (player_X, player_Y))
        game_Screen.blit(game_Sprites['logo'], (logo_X, logo_Y))
        game_Screen.blit(game_Sprites['base'], (base_X, ground_Y))
        display_Text(f"Score: {score}", (255, 0, 0), (screen_Width / 2) - 95, (screen_Height / 2) + 250)
        pygame.display.update()
        fps_Clock.tick(FPS)

def main_Game():
    score = 0
    player_X = int(screen_Width / 5)
    player_Y = int(screen_Height / 2)
    base_X = 0
    
    new_Pipe_1 = random_Pipe_Generator()
    new_Pipe_2 = random_Pipe_Generator()

    upper_Pipes = [
        {'X' : screen_Width + 200, 'Y' : new_Pipe_1[0]['Y']},
        {'X' : screen_Width + 200 + (screen_Width / 2), 'Y' : new_Pipe_1[0]['Y']}
    ]

    lower_Pipes = [
        {'X' : screen_Width + 200, 'Y' : new_Pipe_2[1]['Y']},
        {'X' : screen_Width + 200 + (screen_Width / 2), 'Y' : new_Pipe_2[1]['Y']}
    ]

    pipe_Velocity_X = -6
    negetive_Limit = 0
    positive_Limit = 10

    player_Velocity_Y = -9
    player_MAX_Velocity_Y = 10
    player_Acceleration_Velocity_Y = 1
    player_Flapping_Velocity = -8

    player_Flapped = False

    while True:
        for event in pygame.event.get():
            if event.type == QUIT or (event.type == KEYDOWN and event.key == K_ESCAPE):
                pygame.quit()
                sys.exit()
            if event.type == KEYDOWN and (event.key == K_SPACE or event.key == K_UP):
                if player_Y > 0:
                    player_Velocity_Y = player_Flapping_Velocity
                    player_Flapped = True
                    game_Sounds['wing'].play()

        crashTest = is_Collide(player_X, player_Y, upper_Pipes, lower_Pipes)

        if crashTest:
            backGround_Music.stop()
            return score
        
        player_Mid_Position = player_X + (game_Sprites['player'].get_width() / 2)

        for pipe in upper_Pipes:
            pipe_Mid_Position = pipe['X'] + (game_Sprites['pipe'][0].get_width() / 2)

            if score < 50:
                mode = 3
            else:
                mode = 5

            if (pipe_Mid_Position - mode) <= abs(player_Mid_Position) < (pipe_Mid_Position + mode):
                score += 1
                print(f'Score: {score}')
                game_Sounds['point'].play()
            
        if player_Velocity_Y < player_MAX_Velocity_Y and not player_Flapped:
            player_Velocity_Y += player_Acceleration_Velocity_Y
        if player_Flapped:
            player_Flapped = False

        player_Height = game_Sprites['player'].get_height()
        player_Y += min(player_Velocity_Y, ground_Y - player_Y - player_Height)

        for upper_Pipe, lower_Pipe in zip(upper_Pipes, lower_Pipes):
            upper_Pipe['X'] += pipe_Velocity_X
            lower_Pipe['X'] += pipe_Velocity_X

        if (score == 100):
            pipe_Velocity_X = -20
            negetive_Limit = -15
            positive_Limit = 10

        elif (score == 75):
            game_Sounds['upgrade'].play()
            pipe_Velocity_X = -15
            negetive_Limit = -10
            positive_Limit = 10

        elif (score == 50):
            game_Sounds['upgrade'].play()
            pipe_Velocity_X = -10
            negetive_Limit = -10
            positive_Limit = 10

        elif (score == 25):
            game_Sounds['upgrade'].play()
            pipe_Velocity_X = -8
            negetive_Limit = 0
            positive_Limit = 10



        if negetive_Limit < upper_Pipes[0]['X'] < positive_Limit:
            new_Pipe =random_Pipe_Generator()
            upper_Pipes.append(new_Pipe[0])
            lower_Pipes.append(new_Pipe[1])

        if upper_Pipes[0]['X'] <- game_Sprites['pipe'][0].get_width():
            upper_Pipes.pop(0)
            lower_Pipes.pop(0)

        game_Screen.blit(game_Sprites['backGround'], (0, 0))
        
        for upper_Pipe, lower_Pipe in zip(upper_Pipes, lower_Pipes):
            game_Screen.blit(game_Sprites['pipe'][0], (upper_Pipe['X'], upper_Pipe['Y']))
            game_Screen.blit(game_Sprites['pipe'][1], (lower_Pipe['X'], lower_Pipe['Y']))
        
        game_Screen.blit(game_Sprites['base'], (base_X, ground_Y))
        game_Screen.blit(game_Sprites['player'], (player_X, player_Y))
        
        my_Digits = [int(x) for x in list(str(score))]
        width = 0

        for digit in my_Digits:
                width += game_Sprites['numbers'][digit].get_width()

        X_Offset = (screen_Width - width) / 2

        for digit in my_Digits:
            game_Screen.blit(game_Sprites['numbers'][digit], (X_Offset, screen_Width * 0.12))
            X_Offset += game_Sprites['numbers'][digit].get_width()

        pygame.display.update()
        fps_Clock.tick(FPS)


# Global Variables Initialization...
FPS = 30
screen_Width = 500
screen_Height = 650

game_Screen = pygame.display.set_mode((screen_Width, screen_Height))

ground_Y = screen_Height * 0.8

game_Sprites = {}
game_Sounds = {}

player_Bird = path('FLAPPY Bird Game\\Game_Sprites\\bird.png')
backGround = path('FLAPPY Bird Game\\Game_Sprites\\background.png')
pipe = path('FLAPPY Bird Game\\Game_Sprites\\pipe.png')
logo = path('FLAPPY Bird Game\\Game_Sprites\\logo.png')
base = path('FLAPPY Bird Game\\Game_Sprites\\base.png')

if __name__ == '__main__':
    # main function
    pygame.init()
    fps_Clock = pygame.time.Clock()
    # pygame.time.Clock.tick(FPS)
    pygame.display.set_caption('Flappy Bird Game - YashGames2007.')

    game_Sprites['numbers'] = (
        pygame.image.load(path('FLAPPY Bird Game\\Game_Sprites\\0.png')).convert_alpha(),
        pygame.image.load(path('FLAPPY Bird Game\\Game_Sprites\\1.png')).convert_alpha(),
        pygame.image.load(path('FLAPPY Bird Game\\Game_Sprites\\2.png')).convert_alpha(),
        pygame.image.load(path('FLAPPY Bird Game\\Game_Sprites\\3.png')).convert_alpha(),
        pygame.image.load(path('FLAPPY Bird Game\\Game_Sprites\\4.png')).convert_alpha(),
        pygame.image.load(path('FLAPPY Bird Game\\Game_Sprites\\5.png')).convert_alpha(),
        pygame.image.load(path('FLAPPY Bird Game\\Game_Sprites\\6.png')).convert_alpha(),
        pygame.image.load(path('FLAPPY Bird Game\\Game_Sprites\\7.png')).convert_alpha(),
        pygame.image.load(path('FLAPPY Bird Game\\Game_Sprites\\8.png')).convert_alpha(),
        pygame.image.load(path('FLAPPY Bird Game\\Game_Sprites\\9.png')).convert_alpha()
    )

    game_Sprites['logo'] = pygame.transform.scale((pygame.image.load(logo).convert_alpha()), (400, 500))
    game_Sprites['base'] = pygame.transform.scale((pygame.image.load(base).convert_alpha()), (screen_Width, 150))
    game_Sprites['backGround'] = pygame.transform.scale((pygame.image.load(backGround).convert_alpha()), (screen_Width, screen_Height))
    game_Sprites['player'] = pygame.transform.scale(pygame.image.load(player_Bird).convert_alpha(), (40, 40))
    game_Sprites['pipe'] = (
        pygame.transform.scale(pygame.transform.rotate(pygame.image.load(pipe).convert_alpha(), 180), (70, 500)),
        pygame.transform.scale(pygame.image.load(pipe).convert_alpha(),                               (70, 500))
    )

    game_Sounds['die'] = pygame.mixer.Sound(path('FLAPPY Bird Game\\Game_Audio\\die.wav'))
    game_Sounds['hit'] = pygame.mixer.Sound(path('FLAPPY Bird Game\\Game_Audio\\hit.wav'))
    game_Sounds['wing'] = pygame.mixer.Sound(path('FLAPPY Bird Game\\Game_Audio\\wing.wav'))
    game_Sounds['point'] = pygame.mixer.Sound(path('FLAPPY Bird Game\\Game_Audio\\point.mp3'))
    game_Sounds['swoosh'] = pygame.mixer.Sound(path('FLAPPY Bird Game\\Game_Audio\\swoosh.wav'))
    game_Sounds['upgrade'] = pygame.mixer.Sound(path('FLAPPY Bird Game\\Game_Audio\\levelup.mp3'))

    backGround_Music = pygame.mixer.Sound(path('FLAPPY Bird Game\\Game_Audio\\background.mp3'))

    score = 0
    while True:
        welcome_Screen(score)
        score = main_Game()

# Flappy Bird Game Code Finished.