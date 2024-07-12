import io
from stockfish import Stockfish
from game_board import Board


class StockFishEngine:

    def __init__(self, path="C:\\Program Files\\stockfish\\stockfish-windows-x86-64-sse41-popcnt.exe") -> None:
        self.stockfish = Stockfish(path)

        self.move_map = "abcdefgh"
        # Map FEN symbols to chess tokens
        self.piece_mapping_rev = {
            "P": "white pawn",
            "p": "black pawn",
            "R": "white rook",
            "r": "black rook",
            "N": "white knight",
            "n": "black knight",
            "B": "white bishop",
            "b": "black bishop",
            "Q": "white queen",
            "q": "black queen",
            "K": "white king",
            "k": "black king"
        }
        # Map chess tokens to FEN symbols
        self.piece_mapping = {
            "white pawn": "wp",
            "black pawn": "bp",
            "white rook": "wr",
            "black rook": "br",
            "white knight": "wn",
            "black knight": "bn",
            "white bishop": "wb",
            "black bishop": "bb",
            "white queen": "wq",
            "black queen": "bq",
            "white king": "wk",
            "black king": "bk"
        }

    def boards_correspondence(self, board):

        # Transpose the list of lists
        # transposed_board = list(zip(*board))        

        # flattened_board = [piece_mapping[piece] if piece is not None else "" for row in transposed_board for piece in row]
        c_board = [[] for i in range(8)]

        for i, row in enumerate(board):
            for j, piece in enumerate(row):
                if piece is not None:
                    c_board[j].append(self.piece_mapping[piece])
                else:
                    c_board[j].append("em")

        return c_board

    def board_to_fen(self, board, turn="w", rules="KQkq", en_passant="-", half_moves=0, full_moves=1):
        # Use StringIO to build string more efficiently than concatenating

        board = self.boards_correspondence(board)
        with io.StringIO() as s:

            for row in board:

                empty = 0

                for cell in row:

                    c = cell[0]

                    if c in ('w', 'b'):

                        if empty > 0:

                            s.write(str(empty))

                            empty = 0

                        s.write(cell[1].upper() if c == 'w' else cell[1].lower())

                    else:

                        empty += 1

                if empty > 0:

                    s.write(str(empty))

                s.write('/')

            # Move one position back to overwrite last '/'

            s.seek(s.tell() - 1)

            # If you do not have the additional information choose what to put

            s.write(f' {turn} {rules} {en_passant} {half_moves} {full_moves}')

            return s.getvalue()

    def boards_re_correspondence(self, board):

        # Transpose the list of lists
        # transposed_board = list(zip(*board))

        # Map chess tokens to FEN symbols

        c_board = [[] for i in range(8)]

        for i, row in enumerate(board):
            for j, piece in enumerate(row):
                if piece == "em" or piece is None:
                    c_board[j].append(None)
                else:
                    c_board[j].append(self.piece_mapping_rev[piece])

        return c_board

    def fen_to_board(self, fen):
        board = []
        _fen = fen.split(" ")[0]
        for row in _fen.split('/'):
            board.append([])
            for cell in row:
                if cell.isdigit():
                    for _ in range(int(cell)):
                        board[-1].append(None)
                else:
                    board[-1].append(cell)

        return self.boards_re_correspondence(board)

    def get_best_move(self, board, turn="w", rules="KQkq", en_passant="-", half_moves=0, full_moves=1):
        fen = self.board_to_fen(board, turn, rules, en_passant, half_moves, full_moves)
        if self.stockfish.is_fen_valid(fen):
            self.stockfish.set_fen_position(fen)
            best_move = self.stockfish.get_best_move()
            print(fen, best_move)
            return self.al_move_to_tuple_move(best_move)
        print("Wrong FEN")

    def tuple_move_to_al_move(self, move:list[tuple]):
        return f"{self.move_map[move[0][0]]}{move[0][1]+1}{self.move_map[move[1][0]]}{move[1][1]+1}"

    def al_move_to_tuple_move(self, move:str):
        return [(8 - int(move[1]), self.move_map.index(move[0])), (8 - int(move[3]), self.move_map.index(move[2]))]

# Example usage:

board = Board()

board.reset_board()

# board.move_token(board.token_board, (0, 0), (4, 4))

# print(board.token_board)

engine = StockFishEngine()

fen_result = engine.board_to_fen(board.token_board)

print(engine.al_move_to_tuple_move("e2e4"))
print(engine.tuple_move_to_al_move(engine.al_move_to_tuple_move("e2e4")))
# print("FEN:", fen_result)
# print("FEN:", engine.stockfish.get_fen_position())
# print(board.token_board == engine.fen_to_board(fen_result))

# stockfish.set_fen_position(fen_result)

# print(stockfish.get_board_visual())