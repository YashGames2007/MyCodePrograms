import java.util.Scanner;

public class Pass_or_Fail {
    static Scanner input = new Scanner(System.in);

    public static void main(String[] args) {
        
        String name;
        byte science_Marks, mathematics_Marks, english_Marks;

        System.out.printf("\nEnter Your Name: ");
        name = input.nextLine();

        System.out.printf("\nEnter Your Science Marks [Out of 100]: ");
        science_Marks = input.nextByte();
        System.out.printf("\nEnter Your Mathematics Marks [Out of 100]: ");
        mathematics_Marks = input.nextByte();
        System.out.printf("\nEnter Your English Marks [Out of 100]: ");
        english_Marks = input.nextByte();

        float total_Percentage = ((mathematics_Marks + english_Marks + science_Marks) / 3.F);

        System.out.printf("\n%s Your Total Percentage is: %.2f%%\n", name, total_Percentage);
        //* Checking Total Total Percentage...
        if ((total_Percentage > 100.F) || (total_Percentage < 0.F)) {
            System.out.printf("\nUnexpected Input.!! Program Terminated.!!");
        }
        else if (total_Percentage < 40.F) {
            System.out.printf("\nSorry %s,\nYou are Failed Due to Less Total Percentage than Expected!!!\nBetter Luck Next Time.!!", name);
        }
        else
        {
            //* Checking Percentage in Each Subject...
            if ((science_Marks < 33.F) || (mathematics_Marks < 33.F) || (english_Marks < 33.F)) {
                System.out.printf("\nSorry %s,\nYou are Failed Due to Less Percentage in particular Subject, than Expected!!!\nBetter Luck Next Time.!!", name);
            }
            else
            {
                System.out.printf("\nCongratulations %s !!!\nYou Aced The Examination.!!\nHave a Great Future.!!", name);
            }
        }
        System.out.printf("\n\nThanks For Using The Program %s,\nHave a Nice Day.!!", name);
    }
}
