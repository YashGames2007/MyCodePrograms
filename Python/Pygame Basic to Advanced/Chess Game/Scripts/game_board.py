"""
Game Board Class File
"""
# import pygame
import game_constants as const
from game_token import Token


class Board:
    """The Board class represents a game board."""

    board_padding = 50  # Making the board 50 pixel smaller than const.game_Window
    board = const.object_loader("chess board")

    def __init__(self) -> None:
        Token.init()
        self.token_board = [[None for x in range(8)] for y in range(8)]

        self.box = {
            "green": const.object_loader("position box"),
            "red": const.object_loader("position box red"),
        }
        self.dot = {
            "green": const.object_loader("position dot"),
            "red": const.object_loader("position dot red"),
        }

    def move_token(self, pos_from: tuple, pos_to: tuple) -> None:
        """
        The function moves a token from one position on a token board to another position.

        :param pos_from: The `pos_from` parameter is a tuple representing the current position of
        the token on the board. It contains two values: the row index and the column index of the
        token's current position
        :type pos_from: tuple
        :param pos_to: The `pos_to` parameter is a tuple representing the position where the token
        should be moved to. It contains two elements: the row index and the column index of the
        position
        :type pos_to: tuple
        """
        token_name = self.token_board[pos_from[0]][pos_from[1]]
        self.token_board[pos_from[0]][pos_from[1]] = None
        self.token_board[pos_to[0]][pos_to[1]] = token_name

    def render_tokens(self):
        """
        The function `render_tokens` iterates over the `token_board` and calls the `render` method
        of each non-empty token.
        """
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

    def draw_box(self, pos: tuple[int], color: str = "green") -> None:
        const.game_Window.blit(
            self.box[color],
            (
                const.board_positions[pos[0]][pos[1]][0] + const.BOX_OFFSET,
                const.board_positions[pos[0]][pos[1]][1] + const.BOX_OFFSET,
            ),
        )

    def draw_dot(self, pos: tuple[int], color: str = "green") -> None:
        const.game_Window.blit(
            self.dot[color],
            (
                const.board_positions[pos[0]][pos[1]][0] + const.DOT_OFFSET,
                const.board_positions[pos[0]][pos[1]][1] + const.DOT_OFFSET,
            ),
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
                        return (i, j)
        return (-1, -1)

    def show_board(self):
        # clock.tick(const.FPS_VALUE)  # Setting The FPS Value For The Game.
        const.game_Window.fill(const.background)  # Filling The Display With Color.
        const.game_Window.blit(
            self.board,
            (self.board_padding / 2, self.board_padding / 2),
        )

    def show_moves(self, token_pos: tuple[int]) -> list[tuple[int]]:
        token_x, token_y = token_pos
        if self.token_board[token_x][token_y] is None:
            return []

        moves = Token.get_moves(self.token_board, token_x, token_y)

        if not moves:
            self.draw_box(token_pos, "red")
            self.render_tokens()
        else:
            self.draw_box(token_pos)
            self.render_tokens()

            for move in moves:
                _x, _y = move
                if self.token_board[_x][_y] is not None:
                    self.draw_dot(move, "red")
                else:
                    self.draw_dot(move)

        return moves
