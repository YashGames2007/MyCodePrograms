package Basic_Code.Source;

import java.util.ArrayList;
import java.util.Scanner;

public class Students_Data_Entry {
    static Scanner Input = new Scanner(System.in);
    public static void main(String[] args) {
        System.out.printf("\nHello Students!");

        System.out.printf("\nEnter The Number of Students: ");
        byte total_Students = Input.nextByte();
        
        ArrayList<String> names = new ArrayList<>(total_Students);
        ArrayList<Float> percentage = new ArrayList<>(total_Students);

        for (int index = 0; index < total_Students; index++) {
            
            System.out.printf("\nEnter The Name of Student No. %d: ", index+1);
            names.add(Input.next());
            
            System.out.printf("\nEnter The Percentage of Student No. %d: ", index+1);
            percentage.add(Input.nextFloat());
        }

        System.out.printf("\nAll Information Successfully Saved in The DataBase.!");
        System.out.printf("\n\n\nStudent Details:\n\n");
        System.out.printf("\nMarks : Names\n");
        for (int index = 0; index < total_Students; index++) {
            
            System.out.printf("\n%.2f : %s", percentage.get(index), names.get(index));
        }
        

    }
}
