import pygame
import game_constants as const


# Initializing Pygame Functions and Attributes...
pygame.init()
pygame.display.init()

clock = pygame.time.Clock()
game_Window = pygame.display.set_mode((const.screen_Width, const.screen_Height))
pygame.display.set_caption("Chess - YashGames2007")

def image(path:str, size:tuple, scale:float) -> pygame.Surface:
    return pygame.transform.scale(pygame.image.load(path).convert_alpha(), (size[0]*scale, size[1]*scale))

def object_loader(name:str):
    return image(const.object_locations[name], const.object_sizes[name.replace("white ", "").replace("black ", "")], const.object_size_ratio)

class Token:
    game_tokens = dict()

    def init() -> None:

        for color in const.colors:
            for token in const.tokens:
                Token.game_tokens[f"{color} {token}"] = object_loader(f"{color} {token}")


    # Used to render one token of the board
    @classmethod
    def render(cls, token_name:str, pos_x:int, pos_y:int) -> None:
        position = const.board_positions[pos_x][pos_y]
        ofset = const.tokens_ofset[token_name.replace("white ", "").replace("black ", "")]
        game_Window.blit(Token.game_tokens[token_name], (position[0]+ofset[0], position[1]+ofset[1]))
    

class Board:

    board_padding = 50  #Making the board 50 pixel smaller than game_Window
    board = object_loader("chess board")

    def __init__(self) -> None:
        Token.init()
        self.token_board = [[None for x in range(8)] for y in range(8)]

    def move_token(self, token_name:str, pos_from:tuple, pos_to:tuple) -> None:
        if self.token_board[pos_from[0]][pos_from[1]] == token_name:
            self.token_board[pos_from[0]][pos_from[1]] = None
            self.token_board[pos_to[0]][pos_to[1]] = token_name

    def render_tokens(self):
        # print(self.token_board)
        for x in range(8):
            for y in range(8):
                token = self.token_board[x][y]

                if token != None:
                    Token.render(token, x, y)

    def reset_board(self):
        for color in const.colors:
            layer = const.layers[color]
            # Setting Pawns positions...
            for x in range(8):
                self.token_board[x][layer[1]] = f"{color} pawn"

            # Setting Rocks, Knights, & Bishops positions...
            for x, token in enumerate(["rock", "knight", "bishop"]):
                self.token_board[x][layer[0]] = f"{color} {token}"
                self.token_board[7-x][layer[0]] = f"{color} {token}"
            
            # Setting Queens & Kings positions...
            self.token_board[3][layer[0]] = f"{color} queen"
            self.token_board[4][layer[0]] = f"{color} king"
        