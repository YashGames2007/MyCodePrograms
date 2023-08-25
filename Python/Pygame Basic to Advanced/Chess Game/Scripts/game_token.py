"""
Game Token Class File
"""

import game_constants as const

class Token:
    """The Token class is a placeholder for a token object."""

    game_tokens = {}

    @classmethod
    def init(cls) -> None:
        """
        The `init` function initializes game tokens by loading objects for each color and token
        combination.
        """
        for color in const.colors:
            for token in const.tokens:
                Token.game_tokens[f"{color} {token}"] = const.object_loader(
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
        offset = const.tokens_offset[
            token_name.replace("white ", "").replace("black ", "")
        ]
        const.game_Window.blit(
            Token.game_tokens[token_name],
            (position[0] + offset[0], position[1] + offset[1]),
        )

    @classmethod
    def get_moves(
        cls, token_board: list[list[int]], token_x: int, token_y: int
    ) -> list[tuple[int]]:
        legal_moves = []
        # Checking for Pawns
        for color, y_offset, pos in [("white pawn", -1, 6), ("black pawn", +1, 1)]:
            if token_board[token_x][token_y] == color:
                if 0 <= (token_y + (1 * y_offset)) <= 7:
                    if token_board[token_x][token_y + (1 * y_offset)] is None:
                        # For 1st forward move
                        legal_moves.append((token_x, token_y + (1 * y_offset)))
                        if (
                            ((0 <= (token_y + (2 * y_offset)) <= 7))
                            and token_board[token_x][token_y + (2 * y_offset)] is None
                            and token_y == pos
                        ):
                            # For 2nd forward move
                            # (Only applies when token is at its initial position)
                            legal_moves.append((token_x, token_y + (2 * y_offset)))

                    for x_offset in [+1, -1]:
                        if (
                            (0 <= (token_x + x_offset) <= 7)
                            and (
                                token_board[token_x + x_offset][
                                    token_y + (1 * y_offset)
                                ]
                                is not None
                            )
                            and (
                                not cls.check_color(
                                    token_board,
                                    (token_x, token_y),
                                    (token_x + x_offset, token_y + (1 * y_offset)),
                                )
                            )
                        ):
                            # For right and left killing positions
                            legal_moves.append(
                                (token_x + x_offset, token_y + (1 * y_offset))
                            )

        for token, moves in (
            (token, moves)
            for token, moves in const.tokens_moves.items()
            if token in token_board[token_x][token_y]
        ):
            # Checking for Knights or Kings
            if token in ["knight", "king"]:
                for move in moves:
                    _x, _y = token_x + move[0], token_y + move[1]
                    if 0 <= _x <= 7 and 0 <= _y <= 7:
                        if not cls.check_color(
                            token_board, (token_x, token_y), (_x, _y)
                        ):
                            legal_moves.append((_x, _y))
            else:
                for move in moves:
                    _x, _y = token_x + move[0], token_y + move[1]
                    while 0 <= _x <= 7 and 0 <= _y <= 7:
                        if token_board[_x][_y] is None:
                            legal_moves.append((_x, _y))
                        else:
                            if not cls.check_color(
                                token_board, (token_x, token_y), (_x, _y)
                            ):
                                legal_moves.append((_x, _y))
                            break
                        _x += move[0]
                        _y += move[1]
        return legal_moves

    @classmethod
    def check_color(
        cls,
        token_board: list[list[int]],
        token1_pos: tuple[int],
        token2_pos: tuple[int],
    ) -> bool:
        token1 = token_board[token1_pos[0]][token1_pos[1]]
        token2 = token_board[token2_pos[0]][token2_pos[1]]
        if token1 is None or token2 is None:
            return False
        if token1.split(" ")[0] == token2.split(" ")[0]:
            return True
        return False
