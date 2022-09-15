import java.util.Scanner;

public class Leap_Year {
    static Scanner input = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.printf("\nHello World!");

        System.out.printf("\nEnter The Year: ");
        short year = input.nextShort();

        if ((year % 4 == 0) && (((year % 100 == 0) && (year % 400 == 0)) || (year % 100 != 0))) {
            System.out.printf("\nThe Year %d is a Leap Year.", year);
        }
        else
        {
            System.out.printf("\nThe Year %d is not a Leap Year.", year);
        }
    }

}
