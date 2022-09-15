import java.util.Random;
import java.util.Scanner;

public class Rock_Paper_Scissors {
    static Scanner input = new Scanner(System.in);
    static Random random = new Random();

    public static void main(String[] args) {
        byte comp_Choice = (byte) ((random.nextInt(3)) + 1);

        System.out.printf("\nEnter 1 for Rock 2 for Paper & 3 for Scissors: ");
        byte player_Choice = input.nextByte();

        if ((player_Choice <= 0) || (player_Choice >= 4)) {
            System.out.printf("\nUnexpected Input Program Terminated.!!");
        } else {
            String player, computer;
            switch (comp_Choice) {
                case 1 -> computer = "Rock";
                case 2 -> computer = "Paper";
                default -> computer = "Scissor";
            }
            switch (player_Choice) {
                case 1 -> player = "Rock";
                case 2 -> player = "Paper";
                default -> player = "Scissor";
            }

            System.out.printf("\nPlayer Chosen %s & Computer Chosen %s.", player, computer);
            if (player_Choice == comp_Choice) {
                System.out.printf("\nIt's a Tie");
            } else {
                if ((player_Choice == 1 && comp_Choice == 3) || (player_Choice == 2 && comp_Choice == 1)
                        || (player_Choice == 3 && comp_Choice == 2)) {
                    System.out.printf("\nPlayer Wins!");
                } else {
                    System.out.printf("\nComputer Wins!");
                }
            }
        }
    }
}