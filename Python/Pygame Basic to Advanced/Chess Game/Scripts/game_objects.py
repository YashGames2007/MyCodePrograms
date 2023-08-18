""" Used for game objects utilities. """

import pygame
import game_constants as const


# Initializing Pygame Functions and Attributes...
# pygame.init()
pygame.display.init()

clock = pygame.time.Clock()
game_Window = pygame.display.set_mode((const.SCREEN_WIDTH, const.SCREEN_HEIGHT))
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


def object_loader(name: str):
    """
    The function `object_loader` loads an image of an object based on its name and size.

    :param name: The name parameter is a string that represents the name of the object to be loaded
    :type name: str
    :return: an image object.
    """
    return image(
        const.object_locations[name],
        const.object_sizes[name.replace("white ", "").replace("black ", "")],
        const.OBJECT_SIZE_RATIO,
    )


class Token:
    """The Token class is a placeholder for a token object."""

    game_tokens = dict()

    @classmethod
    def init(cls) -> None:
        """
        The `init` function initializes game tokens by loading objects for each color and token
        combination.
        """
        for color in const.colors:
            for token in const.tokens:
                Token.game_tokens[f"{color} {token}"] = object_loader(
                    f"{color} {token}"
                )

    # Used to render one token of the board
    @classmethod
    def render(cls, token_name: str, pos_x: int, pos_y: int) -> None:
        """
        The function `render` takes in a token name, x and y positions, and renders the token on the
        game window at the specified position with an offset.

        :param cls: The parameter `cls` is a reference to the class that the method `render` belongs
        to. It is commonly used as a convention to refer to the class itself within a class method.
        However, in the given code snippet, the parameter `cls` is not used, so it can be safely
        :param token_name: The `token_name` parameter is a string that represents the name of the
        token to be rendered
        :type token_name: str
        :param pos_x: The `pos_x` parameter represents the x-coordinate of the position where the
        token will be rendered on the game board
        :type pos_x: int
        :param pos_y: The parameter `pos_y` represents the y-coordinate of the position where the
        token will be rendered on the game window
        :type pos_y: int
        """
        position = const.board_positions[pos_x][pos_y]
        ofset = const.tokens_ofset[
            token_name.replace("white ", "").replace("black ", "")
        ]
        game_Window.blit(
            Token.game_tokens[token_name],
            (position[0] + ofset[0], position[1] + ofset[1]),
        )


class Board:
    """The Board class represents a game board."""

    board_padding = 50  # Making the board 50 pixel smaller than game_Window
    board = object_loader("chess board")
    box = object_loader("position box")
    dot = object_loader("position dot")

    def __init__(self) -> None:
        Token.init()
        self.token_board = [[None for x in range(8)] for y in range(8)]

    def move_token(self, token_name: str, pos_from: tuple, pos_to: tuple) -> None:
        """
        The function moves a token from one position on a token board to another position.

        :param token_name: The name of the token that you want to move
        :type token_name: str
        :param pos_from: The `pos_from` parameter is a tuple representing the current position of
        the token on the board. It contains two values: the row index and the column index of the
        token's current position
        :type pos_from: tuple
        :param pos_to: The `pos_to` parameter is a tuple representing the position where the token
        should be moved to. It contains two elements: the row index and the column index of the
        position
        :type pos_to: tuple
        """
        if self.token_board[pos_from[0]][pos_from[1]] == token_name:
            self.token_board[pos_from[0]][pos_from[1]] = None
            self.token_board[pos_to[0]][pos_to[1]] = token_name

    def render_tokens(self):
        """
        The function `render_tokens` iterates over the `token_board` and calls the `render` method
        of each non-empty token.
        """
        # print(self.token_board)
        for _x in range(8):
            for _y in range(8):
                token = self.token_board[_x][_y]

                if token is not None:
                    Token.render(token, _x, _y)

    def reset_board(self):
        """
        The function `reset_board` sets up the initial positions of the pawns, rocks, knights,
        bishops, queens, and kings on a chessboard.
        """
        for color in const.colors:
            layer = const.layers[color]
            # Setting Pawns positions...
            for _x in range(8):
                self.token_board[_x][layer[1]] = f"{color} pawn"

            # Setting Rocks, Knights, & Bishops positions...
            for _x, token in enumerate(["rock", "knight", "bishop"]):
                self.token_board[_x][layer[0]] = f"{color} {token}"
                self.token_board[7 - _x][layer[0]] = f"{color} {token}"

            # Setting Queens & Kings positions...
            self.token_board[3][layer[0]] = f"{color} queen"
            self.token_board[4][layer[0]] = f"{color} king"

    def draw_box(self, pos: tuple[int]):
        """
        The function `draw_box` draws a rectangular box on a pygame board at a specified position.

        :param pos: The `pos` parameter is a tuple of two integers representing the position of the
        box on the game board. The first integer represents the row index, and the second integer
        represents the column index
        :type pos: tuple[int]
        """
        game_Window.blit(self.box, (
            const.board_positions[pos[0]][pos[1]][0] + const.BOX_OFSET,
            const.board_positions[pos[0]][pos[1]][1] + const.BOX_OFSET,
        ))
        

    def draw_dot(self, pos: tuple[int]):
        """
        The function `draw_dot` draws a dot on a pygame board at a specified position.

        :param pos: The `pos` parameter is a tuple of two integers representing the position of the
        dot on the game board. The first integer represents the row index, and the second integer
        represents the column index
        :type pos: tuple[int]
        """
        pygame.draw.circle(
            self.board,
            const.pos_marker,
            [
                const.board_positions[pos[0]][pos[1]][0] + const.DOT_OFSET,
                const.board_positions[pos[0]][pos[1]][1] + const.DOT_OFSET,
            ],
            const.DOT_RADIUS,
            const.DOT_WIDTH,
        )

    def get_position(self, cursor_position: tuple[int]) -> tuple[int]:
        """
        The function that detects the board position where user has clicked.

        :param cursor_position: The current cursor position where user has clicked.
        :type token_name: tuple[int]
        """
        for i in range(8):
            for j in range(8):
                current = const.board_positions[i][j]
                right = const.board_positions[i + 1][j]
                down = const.board_positions[i][j + 1]

                if current[0] <= cursor_position[0] < right[0]:
                    if current[1] <= cursor_position[1] < down[1]:
                        print(f"({i}, {j}): {self.token_board[i][j]}")
                        return (i, j)
        return (-1, -1)

    def show_board(self):
        # clock.tick(const.FPS_VALUE)  # Setting The FPS Value For The Game.
        game_Window.fill(const.background)  # Filling The Display With Color.
        game_Window.blit(
            self.board,
            (self.board_padding / 2, self.board_padding / 2),
        )
