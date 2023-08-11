import pygame
import game_constants as const

def image(path:str, size:tuple, scale:float) -> pygame.Surface:
    return pygame.transform.scale(pygame.image.load(path).convert_alpha(), (size[0]*scale, size[1]*scale))

def object_loader(name:str):
    return image(const.object_locations[name], const.object_sizes[name], const.object_size_ratio)


white_tokens = []
black_tokens = []

for i in range(2):
    if i == 0:
        tokens = white_tokens
        color = "white"
    else:
        tokens = black_tokens
        color = "black"


    for _ in range(8):
        tokens.append(object_loader(f"{color} pawn"))

    for _ in range(2):
        tokens.append(object_loader(f"{color} rock"))

    for _ in range(2):
        tokens.append(object_loader(f"{color} knight"))

    for _ in range(2):
        tokens.append(object_loader(f"{color} bishop"))

    tokens.append(object_loader(f"{color} queen"))
    tokens.append(object_loader(f"{color} king"))

print(white_tokens)
print(black_tokens)