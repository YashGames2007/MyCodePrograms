import java.util.Scanner;
public class Strings {
    public static void main(String[] args) {
        // Program About Strings in java.
        String password;

        // String format_New = "Programs";
        // String format_Old = "Games";

        // System.out.println(password.replace(format_Old, format_New));
        Scanner input = new Scanner(System.in);
        System.out.printf("Enter The Password: ");
        password = input.next();

        switch (password) {
            case "YashGames2007" -> {
                System.out.printf("\nCorrect Password");
            }
            case "YashPrograms2007" -> {
                System.out.printf("\nSecondary Password Accessed!");
            }
            default -> {
                System.out.printf("\nIncorrect Password, Access Denied!!!");
            }
        }
        input.close();
    }
}
