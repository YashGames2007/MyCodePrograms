package Basic_Code.Source;

import java.util.Scanner;

public class Exception_Handling {

    public static Scanner input = new Scanner(System.in);
    public static void main(String[] args) {
        
        System.out.printf("\nHello World!");

        System.out.printf("\nEnter the value of A: ");
        float a = input.nextFloat();
        System.out.printf("\nEnter the value of B: ");
        float b = input.nextFloat();

        try {
            System.out.printf("\nThe value of A divided by B is: ");
            System.out.println(a/b);

        } catch (ArithmeticException error) {

            System.out.printf("\nError While Dividing A by B: ");
            System.out.println(error);
        } catch (Exception error) {
            System.out.printf("\nUnknown Error: ");
            System.out.println(error);
        }

        System.out.printf("\nTermination..");
    }
}
