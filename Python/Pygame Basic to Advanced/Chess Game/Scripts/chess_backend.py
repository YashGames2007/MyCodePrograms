""" Used for game backend controller utilities. """

import game_constants as const
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
        self.check = False
        self.returned = "None"
        self.moved_pos = None
        self.promote_window = const.object_loader("pawn promotion window")


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
            self.returned = self.game_board.move_token(self.game_board.token_board, self.token_pos, selected_pos)
            self.moved_pos = selected_pos
    
            selected_pos = (-1, -1)
            cursor_pos = (-1, -1)
            self.is_selected = False
            self.shift_turn()
            self.is_win()

        elif selected_pos != (-1, -1):
            token = self.game_board.token_board[selected_pos[0]][selected_pos[1]]
            if token is not None and self.current_turn in token:
                self.available_moves = self.game_board.show_moves(selected_pos)
                self.token_pos = selected_pos
                self.is_selected = bool(self.available_moves)

        if (
            self.is_selected
            and selected_pos != self.token_pos
            and selected_pos not in self.available_moves
        ):
            selected_pos = (-1, -1)
            self.is_selected = False

        if self.returned == "Promote":
            self.returned = self.pawn_promotion()
            self.is_win()
        if self.check:
            self.game_board.show_check()
                

        return cursor_pos, False
    
    def is_win(self):
        self.check = self.game_board.is_checked(self.current_turn, self.game_board.token_board)
        if self.game_board.is_mate(self.current_turn, self.game_board.token_board):
            if self.check:
                print("Checkmate !!!")
            else:
                print("Stalemate !!!")

    def pawn_promotion(self):
        self.current_turn = self.game_board.token_board[self.moved_pos[0]][self.moved_pos[1]].split()[0]
        const.game_Window.blit(
            self.promote_window,
            (
                (const.SCREEN_WIDTH / 2 + const.object_offset["pawn promotion window"][0])
                * const.OBJECT_SIZE_RATIO,
                (const.SCREEN_HEIGHT / 2 + const.object_offset["pawn promotion window"][1])
                * const.OBJECT_SIZE_RATIO,
            ),
        )

        pos_y = const.promotion_window_box_y_locations[0]
        for token, x_limits in const.promotion_window_box_x_locations.items():
            pos_x = x_limits[0]
            Game_Token.Token.render_coordinates(f"{self.current_turn} {token}", pos_x, pos_y)


        # Get the User Input by Choice between 4 Options...
        promotion = "None"
        cursor = const.get_cursor()
        if cursor:
            if const.within_limits(cursor[1], const.promotion_window_box_y_locations):
                for token, limits in const.promotion_window_box_x_locations.items():
                    if const.within_limits(cursor[0], limits):
                        promotion = f"{self.current_turn} {token}"
                        self.game_board.token_board[self.moved_pos[0]][self.moved_pos[1]] = promotion
                        self.shift_turn()
                        return "None"

        return "Promote"
