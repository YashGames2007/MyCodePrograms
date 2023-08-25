""" Used for game backend controller utilities. """

# import game_constants as const
import game_board as Game_Board
import game_token as Game_Token


class ChessGame:
    
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
        self.current_turn = "black" if self.current_turn == "white" else "white"

    def play(self, cursor_pos) -> tuple[tuple[int], bool]:
        selected_pos = self.game_board.get_position(cursor_pos)
        self.game_board.show_board()
        self.game_board.render_tokens()

        if self.is_selected and selected_pos != self.token_pos and selected_pos in self.available_moves:
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
