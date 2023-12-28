package Basic_Code.Source;

import java.util.Scanner;

class DimensionalException extends Exception {

    @Override
    public String getMessage() {
        return "Negative Dimension Not Allowed: ";
    }

    @Override
    public String toString() {
        return this.getMessage();
    }

}

class MaxRetriesExceededException extends Exception {

    @Override
    public String getMessage() {
        return "Max Number of Retries Exceeded.!!";
    }

    @Override
    public String toString() {
        return this.getMessage();
    }

}

public class Custom_Exceptions {

    public static Scanner input = new Scanner(System.in);

    public static void subMain() throws MaxRetriesExceededException {

        int[] arr = new int[4];
        int maxRetries = 5;

        arr[0] = 1;
        arr[1] = 3;
        arr[2] = 5;
        arr[3] = 7;

        for (int i = 0; true;) {

            try {
                System.out.printf("\nEnter the index: ");
                int in = input.nextInt();
                System.out.printf("\nThe value at index %d is %d", in, arr[in]);
                break;

            } catch (Exception e) {

                i++;
                System.out.printf("\nInvalid Index, Tries Left: %d", maxRetries - i);
            } finally {

                if (i == maxRetries) {
                    throw new MaxRetriesExceededException();
                }
            }
        }
    }

    public static void main(String[] args) {
        // System.out.printf("\nHello World!");

        // System.out.printf("\nEnter The length of the Square: ");
        // float side = input.nextFloat();

        // if (side <= 0) {
        //     try {
        //         throw new DimensionalException();
        //     } catch (Exception error) {

        //         System.out.println(error);
        //         System.out.println(error.getStackTrace());
        //     }
        // } else {
        //     System.out.printf("\nArea of te Square is: %f", side * side);
        // }

        try {
            subMain();   
        } catch (Exception e) {
            System.out.printf("\nSomething Went Wrong.!!" + e);
        }
    }
}