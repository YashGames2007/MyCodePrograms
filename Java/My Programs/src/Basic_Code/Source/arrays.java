package Basic_Code.Source;

import java.util.Scanner;

public class arrays {
    static Scanner input = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.printf("\nEnter the Number of Elements of the Array: ");
        int size = input.nextInt();

        int[] array = new int[size];

        for (int i = 0; i < array.length; i++) {
            System.out.printf("\nEnter the Value for array[%d]: ", i);
            array[i] = input.nextInt();
        }

        System.out.printf("\nSuccessful Retrieval of Data.!!");
        System.out.printf("\nArray: {");

        if (array.length == 0) {
        }
        else
        {
            System.out.printf("%d", array[0]);
            
            for (int i = 1; i < array.length; i++) {
                System.out.printf(", %d", array[i]);
            }
        }
        System.out.printf("}.");
        
        System.out.printf("\nReverse Array: {");
    
        if (array.length == 0) {
        }
        else
        {
            System.out.printf("%d", array[size - 1]);
            
            for (int i = size - 2; i >= 0; i--) {
                System.out.printf(", %d", array[i]);
            }
        }
        System.out.printf("}.");
    }
}
