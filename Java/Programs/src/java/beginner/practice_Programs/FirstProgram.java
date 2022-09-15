import java.util.Scanner;

public class FirstProgram {
    protected static Scanner input = new Scanner(System.in);
    public static void main(String[] args) throws Exception {
        int subject_1, subject_2, subject_3, subject_4, subject_5, total_Marks = 100;
        double percentage;
        
        System.out.println("Hello, CBSE Students! Enter Your Marks 1-By-1 To Calculate Percentage.\n");
        
        
        System.out.print("Enter The 1st Subject Marks: ");
        subject_1 = input.nextInt();
        System.out.print("Enter The 2nd Subject Marks: ");
        subject_2 = input.nextInt();
        System.out.print("Enter The 3rd Subject Marks: ");
        subject_3 = input.nextInt();
        System.out.print("Enter The 4th Subject Marks: ");
        subject_4 = input.nextInt();
        System.out.print("Enter The 5th Subject Marks: ");
        subject_5 = input.nextInt();
        
        
        percentage = ((subject_1 + subject_2 + subject_3 + subject_4 + subject_5) / (5.D * total_Marks)) * 100.D;
        System.out.printf("\nYour CBSE Board Percentage is: %.2f", percentage);
        System.out.println("\n\nThanks For Using The Program... Shuting...");

        input.close();
    }
}
