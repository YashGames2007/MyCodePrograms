""" All constants related to game is present in ths file. """

import os
import sys
import pygame

ROOT_DIR = "d:/Programming files/Code/Python/Pygame Basic to Advanced/Chess Game/"

OBJECT_SIZE_RATIO = 6.52174  # Constant term to change the objects size
colors = ["white", "black"]
tokens = ["pawn", "rook", "knight", "bishop", "queen", "king"]
layers = {"white": [7, 6], "black": [0, 1]}


object_locations = {
    "chess board": os.path.join(ROOT_DIR, "Assets/board.jpg"),
    "position box": os.path.join(ROOT_DIR, "Assets/box.png"),
    "position box red": os.path.join(ROOT_DIR, "Assets/box_red.png"),
    "position dot": os.path.join(ROOT_DIR, "Assets/dot.png"),
    "position dot red": os.path.join(ROOT_DIR, "Assets/dot_red.png"),
    "check text": os.path.join(ROOT_DIR, "Assets/check.png"),
    "pawn promotion window": os.path.join(ROOT_DIR, "Assets/pawn_promotion_window.png"),
}
# Coping Token Locations in the object_locations dict
for color in colors:
    for token in tokens:
        object_locations[f"{color} {token}"] = os.path.join(
            ROOT_DIR, f"Assets/{color} tokens/{token}.png"
        )

object_sizes = {
    "pawn": (9, 24.9),
    "rook": (9.1, 23.1),
    "knight": (9.7, 24.8),
    "bishop": (9.7, 22),
    "queen": (9.9, 19.4),
    "king": (9.7, 18.8),
    "chess board": (115, 115),
    "position box": (13, 13),
    "position box red": (13, 13),
    "position dot": (2.5, 2.5),
    "position dot red": (2.5, 2.5),
    "check text": (23.76, 10),
    "pawn promotion window": (59.5, 37.9),
}

object_offset = {
    "pawn": (12, -95),
    "rook": (9, -85),
    "knight": (10, -95),
    "bishop": (10, -77),
    "queen": (10, -60),
    "king": (10, -56),
    "check text": (-object_sizes["check text"][0]/2, -object_sizes["check text"][1]/2),
    "pawn promotion window": (-object_sizes["pawn promotion window"][0]/2, -object_sizes["pawn promotion window"][1]/2),
}

tokens_moves = {
    "rook": [(+1, 0), (-1, 0), (0, +1), (0, -1)],
    "knight": [ (+2, +1), (+2, -1), (-2, +1), (-2, -1), 
               (+1, +2), (+1, -2), (-1, +2), (-1, -2)],
    "bishop": [(+1, +1), (+1, -1), (-1, +1), (-1, -1)],
    "queen": [(+1, +1), (+1, 0), (+1, -1), (-1, +1), 
              (-1, 0), (-1, -1), (0, +1), (0, -1)],
    "king": [(+1, +1), (+1, 0), (+1, -1), (-1, +1), 
              (-1, 0), (-1, -1), (0, +1), (0, -1)],
}

block_locations = [67.5, 151, 235.5, 317, 401.5, 484, 567.5, 651, 734.5]
board_positions = [[(x, y) for y in block_locations] for x in block_locations]

# Creating Game Constant Variables...
SCREEN_WIDTH = 122.6666503111133
SCREEN_HEIGHT = 122.6666503111133
FPS_VALUE = 10

BOX_OFFSET = 0
DOT_OFFSET = 32.5

promotion_window_box_x_locations = {
    "rook": (217, 295),
    "knight": (313, 393),
    "bishop": (409, 486),
    "queen": (502, 580),
}

promotion_window_box_y_locations = (435, 510)

# Adding Some Colors...
white = (255, 255, 255)
black = (0, 0, 0)
red = (255, 0, 0)
green = (0, 255, 0)
blue = (0, 0, 255)
background = (255, 191, 141)
pos_marker = (75, 155, 15)


# Initializing Pygame Functions and Attributes...
# pygame.init()
pygame.display.init()

clock = pygame.time.Clock()
game_Window = pygame.display.set_mode((SCREEN_WIDTH*OBJECT_SIZE_RATIO, SCREEN_HEIGHT*OBJECT_SIZE_RATIO))
pygame.display.set_caption("Chess - YashGames2007")


def image(path: str, size: tuple, scale: float) -> pygame.Surface:
    """
    The function takes an image file path, size tuple, and scale
    factor as input, and returns a scaled pygame Surface object of the image.

    :param path: The path parameter is a string that
    represents the file path of the image file you want to load
    :type path: str

    :param size: The size parameter is a tuple that
    represents the desired width and height of the image
    :type size: tuple

    :param scale: The scale parameter is a float value that
    determines the scaling factor for the image.
    It is used to resize the image by multiplying the original size with the scale value
    :type scale: float
    :return: a pygame.Surface object.
    """
    return pygame.transform.scale(
        pygame.image.load(path).convert_alpha(), (size[0] * scale, size[1] * scale)
    )

def object_loader(name: str) -> pygame.Surface:
    """
    The function `object_loader` loads an image of an object based on its name and size.

    :param name: The name parameter is a string that represents the name of the object to be loaded
    :type name: str
    :return: an image object.
    """
    return image(
        object_locations[name],
        object_sizes[name.replace("white ", "").replace("black ", "")],
        OBJECT_SIZE_RATIO,
    )

def get_cursor():
    for event in pygame.event.get():
        if (
            event.type == pygame.QUIT
        ):  # Checking If The Close Button Is Pressed.
            pygame.quit()  # Quitting The Game...
            sys.exit()  # Exiting All Functions...
        if event.type == pygame.MOUSEBUTTONDOWN:
            # Checking If The Left Mouse Button Is Pressed.
            if event.button == pygame.BUTTON_LEFT:
                return pygame.mouse.get_pos()

def within_limits(val:int, limits:tuple[int]) -> bool:
    if limits[0] <= val <= limits[1]:
        return True
    return False