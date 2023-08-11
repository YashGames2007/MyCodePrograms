import os

root_dir = "Python/Pygame Basic to Advanced/Chess Game/"

object_size_ratio = 6.52174

object_locations = {
    "white pawn": os.path.join(root_dir, "Assets/white tokens/pawn.png"),
    "white rock": os.path.join(root_dir, "Assets/white tokens/rock.png"),
    "white knight": os.path.join(root_dir, "Assets/white tokens/knight.png"),
    "white bishop": os.path.join(root_dir, "Assets/white tokens/bishop.png"),
    "white queen": os.path.join(root_dir, "Assets/white tokens/queen.png"),
    "white king": os.path.join(root_dir, "Assets/white tokens/king.png"),
    "black pawn": os.path.join(root_dir, "Assets/black tokens/pawn.png"),
    "black rock": os.path.join(root_dir, "Assets/black tokens/rock.png"),
    "black knight": os.path.join(root_dir, "Assets/black tokens/knight.png"),
    "black bishop": os.path.join(root_dir, "Assets/black tokens/bishop.png"),
    "black queen": os.path.join(root_dir, "Assets/black tokens/queen.png"),
    "black king": os.path.join(root_dir, "Assets/black tokens/king.png"),
    "chess board": os.path.join(root_dir, "Assets/board.jpg")
}

object_sizes = {
    "white pawn": (9, 24.9),
    "white rock": (9.1, 23.1),
    "white knight": (9.7, 24.8),
    "white bishop": (9.7, 22),
    "white queen": (9.9, 19.4),
    "white king": (9.7, 18.8),
    "black pawn": (9, 24.9),
    "black rock": (9.1, 23.1),
    "black knight": (9.7, 24.8),
    "black bishop": (9.7, 22),
    "black queen": (9.9, 19.4),
    "black king": (9.7, 18.8),
    "chess board": (11.5, 11.5)
}