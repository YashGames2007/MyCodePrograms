import java.util.Scanner;

public class Tic_Tac_Toe {

    static Scanner input = new Scanner(System.in);

    static void display_Board(char[] board) {

        System.out.printf("\n");
        System.out.printf(" %c | %c | %c ", board[0], board[1], board[2]);
        System.out.printf("\n---|---|---\n");
        System.out.printf(" %c | %c | %c ", board[3], board[4], board[5]);
        System.out.printf("\n---|---|---\n");
        System.out.printf(" %c | %c | %c ", board[6], board[7], board[8]);
        System.out.printf("\n");
    }

    static byte check_Condition(char[] board) {

        byte result = 0;
        int[][] diagonals = {
                { 0, 4, 8 },
                { 2, 4, 6 }
        };
        int[][] conditions = {
                { 0, 1, 2, 3, 4, 5, 6, 7, 8 },
                { 0, 3, 6, 1, 4, 7, 2, 5, 8 }
        };

        for (int i = 0; i <= 1; i++) {
            for (int j = 0; j <= 6; j += 3) {
                for (int k = j; k < (j + 3); k++) {

                    if (board[conditions[i][k]] == board[conditions[i][(((k + 1) % 3) + j)]]
                            && board[conditions[i][(((k + 1) % 3) + j)]] == board[conditions[i][(((k + 2) % 3) + j)]]) {

                        if (board[conditions[i][(((k + 1) % 3) + j)]] == 'X') {

                            result = 1;
                        } else {

                            result = 2;
                        }
                        return result;
                    }
                }
            }
        }

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {

                if (board[diagonals[i][j]] == board[diagonals[i][((j + 1) % 3)]]
                        && board[diagonals[i][((j + 1) % 3)]] == board[diagonals[i][((j + 2) % 3)]]) {
                    if (board[diagonals[i][j]] == 'X') {
                        result = 1;
                    } else {
                        result = 2;
                    }
                    return result;
                }
            }
        }

        return result;
    }

    static void take_Turn(char[] board, int player) {

        char token;
        byte option;
        boolean correct = false;

        System.out.printf("\nCurrent Board Status...\n");
        display_Board(board);

        if (player == 1) {
            token = 'X';
        } else {
            token = 'O';
        }

        while (!correct) {

            System.out.printf("\nPlayer %d Turn: ", player);
            System.out.printf("\nEnter The Number where you want to place your '%c': ", token);
            option = input.nextByte();
            option--;
            if (option < 0 || option >= 9) {
                System.out.printf("\nInvalid Input! Please Type Between 1 to 9.!");
            } else if (board[option] == 'X' || board[option] == 'O') {
                System.out.printf("\nInvalid Input! Box Already Filled, Try another one.!");
            } else {
                board[option] = token;
                System.out.printf("\nPlaced Player %d Turn Successfully.!!", player);
                correct = true;
            }
            System.out.printf("\n");
        }

        System.out.printf("\nBoard Status after Play...\n");
        display_Board(board);
    }

    public static void main(String[] args) {

        char[] token_Board = {
                '1', '2', '3',
                '4', '5', '6',
                '7', '8', '9'
        };
        byte winner = 0, condition;

        System.out.printf("\n\n*** Tic Tac Toe Game ***\n\n");
        System.out.printf("\nWelcome to The Game.!!\nLet's Start...\n\n");

        for (int turn = 0; turn < 9; turn++) {
            
            take_Turn(token_Board, ((turn % 2) + 1));
            condition = check_Condition(token_Board);
            if (condition != 0) {
                winner = condition;
                break;
            }
        }
        if (winner == 0) {
            System.out.printf("\nOOps !!! It's a Tie Match.!!\nBetter Luck Next Time...");
        }
        else
        {
            System.out.printf("\nCongratulations !!! Player %d Wins The Match.!!\nWell Done...", winner);
        }
        System.out.printf("\n\nTerminating...Shutting...Bye.Friends...");
    }
}
/*
 ** 1 | 2 | 3
 * ---|---|---
 ** 4 | 5 | 6
 * ---|---|---
 ** 7 | 8 | 9
 */