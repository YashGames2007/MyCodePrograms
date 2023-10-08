""" Main User Interface Script for Chess Game in Python """
import sys
import pygame
import time

import chess_backend as chess
import game_constants as const


class GameUI:
    """Main Handler Class for Chess Game."""

    
    chess_board = chess.ChessGame()

    @classmethod
    def welcome_screen(cls):
        """
        The function displays a welcome screen in a Pygame window and waits for the user to
        press the Enter key to start the game  or close to end it.

        :param cls: The parameter "cls" in the function "welcome_screen" is typically used as a
        convention to refer to the class itself.
        """
        while True:
            pygame.display.update()
            const.clock.tick(const.FPS_VALUE)
            const.game_Window.fill(const.background)
            cls.chess_board.show("welcome screen")
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    pygame.quit()
                    sys.exit()
                if event.type == pygame.KEYDOWN:
                    if event.key == pygame.K_RETURN:
                        cls.game_loop()
                if event.type == pygame.MOUSEBUTTONDOWN:
                    # Checking If The Left Mouse Button Is Pressed.
                    if event.button == pygame.BUTTON_LEFT:
                        cls.game_loop()

    @classmethod
    def end_screen(cls, condition:str):
        """
        The function `end_screen` displays a blue screen and waits for the user to press the Enter
        key to start the game loop or close to end it.

        :param cls: The parameter "cls" in the function "end_screen" is typically used as a
        convention to refer to the class itself.
        """
        if condition == "tie":
            screen = "tie screen"
        else:
            screen = f"{condition} win screen"
        pygame.display.update()
        const.clock.tick(const.FPS_VALUE)
        pygame.display.flip()
        time.sleep(3)
        while True:
            pygame.display.update()
            const.clock.tick(const.FPS_VALUE)
            const.game_Window.fill(const.background)
            cls.chess_board.show(screen)
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    pygame.quit()
                    sys.exit()
                if event.type == pygame.KEYDOWN:
                    # Checking If The Enter key Is Pressed.
                    if event.key == pygame.K_RETURN:
                        cls.game_loop()
                if event.type == pygame.MOUSEBUTTONDOWN:
                    # Checking If The Left Mouse Button Is Pressed.
                    if event.button == pygame.BUTTON_LEFT:
                        cls.game_loop()

    @classmethod
    def game_loop(cls):
        """
        The function `game_loop` is a loop that handles the main game logic and events, including
        updating the display, handling mouse and keyboard events, and checking for game over
        conditions.

        :param cls: The parameter "cls" is a reference to the class that the method belongs to.
        It is used to access the class's attributes and methods within the method
        """

        game_over = False
        selected_pos = (-1, -1)
        cls.chess_board.__init__()

        while not game_over:
            const.clock.tick(const.FPS_VALUE)
            pygame.display.flip()
            selected_pos, game_over = cls.chess_board.play(selected_pos)

            for event in pygame.event.get():  # Getting The Event In Pygame.
                if (
                    event.type == pygame.QUIT
                ):  # Checking If The Close Button Is Pressed.
                    pygame.quit()  # Quitting The Game...
                    sys.exit()  # Exiting All Functions...

                # Checking If Any Mouse Button Is Pressed.
                if event.type == pygame.MOUSEBUTTONDOWN:
                    # Checking If The Left Mouse Button Is Pressed.
                    if event.button == pygame.BUTTON_LEFT:
                        selected_pos = (-1, -1)
                        # game_board.show_board()
                        selected_pos = pygame.mouse.get_pos()
                if event.type == pygame.KEYDOWN:  # Checking If Any Key Is Pressed.
                    # Checking If Enter(Return) Key Is Pressed.
                    if event.key == pygame.K_RETURN:
                        pass

        if game_over:  # Checking If The Game Is Over.
            cls.end_screen(game_over)  # Calling Ending Screen...


if __name__ == "__main__":
    GameUI.welcome_screen()  # Calling Welcome Screen...
