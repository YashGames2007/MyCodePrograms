package Basic_Code.Source;

import java.util.Scanner;
public class Star_Patterns {
    static Scanner input = new Scanner(System.in);
    public static void main(String[] args) {
        //* Printing Star Pattern 1:
        System.out.printf("\nEnter The Number: ");
        int n = input.nextInt();
        for (int i = 0; i < n; i++) {
            for (int j = (n - i); j > 0; j--) {
                System.out.printf("*");
            }
            System.out.printf("\n");
        }
    }
}
