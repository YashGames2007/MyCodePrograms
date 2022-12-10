package Basic_Code.Source;

import Basic_Code.Mini_Projects.Libraries.Mini_Library.*;

public class Online_Library_Exercise {

    public static void main(String[] args) {
        System.out.printf("\nHello World!");

        Library my_Library = new Library(5);

        // Initializing Books...
        System.out.printf("\n");
        my_Library.add_Book(new Book("Basic Maths", "Mathematician", "Educational", 400, 750));
        my_Library.add_Book(new Book("Basic Science", "Scientist", "Educational", 800, 1250));
        my_Library.add_Book(new Book("Bollywood Classics", "Legend", "Cinematic", 200, 500));
        my_Library.add_Book(new Book("Baby's Day Out", "International", "Adventurous", 100, 300));
        my_Library.add_Book(new Book("Cavemen", "Comedian", "Comic", 50, 200));

        System.out.printf("\n");
        my_Library.available_Books_Info();
        System.out.printf("\n");
        Book b1 = my_Library.issueBook("Basic Maths");
        Book b2 = my_Library.issueBook("Basic Science");
        System.out.printf("\n");
        my_Library.available_Books_Info();
        System.out.printf("\n");
        my_Library.returnBook(b1);
        my_Library.returnBook(b2);
        System.out.printf("\n");
        my_Library.available_Books_Info();
        my_Library.returnBook(b2);
    }

}
