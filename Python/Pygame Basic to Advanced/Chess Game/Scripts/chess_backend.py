""" Used for game backend controller utilities. """

# import game_constants as const
import game_board as Game_Board
import game_token as Game_Token


class ChessGame:
    """The ChessGame class represents a game of chess."""

    def __init__(self) -> None:
        Game_Token.Token()
        self.game_over = False
        self.game_board = Game_Board.Board()
        self.game_board.reset_board()
        self.token_pos = (-1, -1)
        self.available_moves = []
        self.is_selected = False
        self.current_turn = "white"

    def shift_turn(self) -> None:
        """
        The function `shift_turn` changes the current turn from "white" to "black" or vice versa.
        """
        self.current_turn = "black" if self.current_turn == "white" else "white"

    def play(self, cursor_pos) -> tuple[tuple[int], bool]:
        """
        The `play` function handles the logic for selecting and moving tokens on a game board.

        :param cursor_pos: The `cursor_pos` parameter represents the current position of the cursor
        on the game board. It is a tuple of two integers representing the row and column indices of
        the cursor position on the game board
        :return: a tuple containing the updated `cursor_pos` and a boolean value `False`.
        """
        selected_pos = self.game_board.get_position(cursor_pos)
        self.game_board.show_board()
        self.game_board.render_tokens()

        if (
            self.is_selected
            and selected_pos != self.token_pos
            and selected_pos in self.available_moves
        ):
            self.game_board.move_token(self.token_pos, selected_pos)
            selected_pos = (-1, -1)
            cursor_pos = (-1, -1)
            self.is_selected = False
            self.shift_turn()

        elif selected_pos != (-1, -1):
            token = self.game_board.token_board[selected_pos[0]][selected_pos[1]]
            if token is not None and self.current_turn in token:
                self.available_moves = self.game_board.show_moves(selected_pos)
                self.token_pos = selected_pos
                self.is_selected = bool(self.available_moves)

        return cursor_pos, False
