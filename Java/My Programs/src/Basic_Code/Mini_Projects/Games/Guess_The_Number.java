package Basic_Code.Mini_Projects.Games;

import java.util.Scanner;
import java.util.Random;

public class Guess_The_Number {

    // static Scanner input = new Scanner(System.in);

    public static void main(String[] args) {

        System.out.printf("\nHello Gamers!\n");

        System.out.printf("\nWelcome to 'Guess The Number' Game..!!");
        System.out.printf("\nEnter your Name: ");
        String name = Game.input.next();

        System.out.printf("\nEnter The Number of Plays: ");
        int rounds = Game.input.nextInt();

        System.out.printf("\nOk.!! Lets Start the Game...\n");
        Game _Game_ = new Game(name);
        int score = 0;

        for (int i = 1; i <= rounds; i++) {
            System.out.printf("\n\nRound: %d\n", i);
            _Game_.restart();
            do {
            } while (!_Game_.check_Guess(_Game_.take_Turn()));
            score += _Game_.show_Turns();
        }
        System.out.printf("\nYour Total Score: %d", (100 - (score - rounds)));

    }
}

class Game {

    // Initializing Game Attributes...
    static Scanner input = new Scanner(System.in);
    static Random rand = new Random();
    private int target = (rand.nextInt(100) + 1);

    private int total_Tries = 0;
    private String player_Name = "";

    // Defining Methods...
    public Game(String player_Name) {
        this.player_Name = player_Name;
    }

    public boolean check_Guess(int guess) {

        this.total_Tries++;

        System.out.printf("\n");
        if (this.target == guess) {
            System.out.printf("\nCongratulations %s, You Guessed The Correct Number.!.!!", this.player_Name);
            return true;
        } else if (this.target < guess) {
            System.out.printf("\nOh.!! Your Guess is Quit High, Try an Lower Number...!!");
        } else {
            System.out.printf("\nOh.!! Your Guess is Quit Low, Try an Higher Number...!!");
        }
        System.out.printf("\n");
        return false;
    }

    public int take_Turn() {

        System.out.printf("\nEnter The Guessed Number Between 1 to 100: ");
        int turn = input.nextInt();
        return turn;
    }

    public int show_Turns() {

        System.out.printf("\nTotal Turns Took: %d", this.total_Tries);
        return this.total_Tries;
    }

    public void restart() {
        this.target = (rand.nextInt(100) + 1);
        this.total_Tries = 0;
    }
}
