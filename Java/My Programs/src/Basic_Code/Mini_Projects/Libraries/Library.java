package Basic_Code.Mini_Projects.Libraries;

import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.HashMap;
import java.util.List;
import java.util.Set;
import Basic_Code.Mini_Projects.Libraries.Mini_Library.Book;

/**
 * This is an Exception class which throws exception when there is insufficient
 * amount while someone issues an Book from the Library.
 * 
 * @author Yash Bhavsar (YashGames2007)
 * @version 1.2
 * @since 2022
 */
class InsufficientAmountException extends Exception {

    private int required_Amount;
    private int given_Amount;

    public InsufficientAmountException(int required_Amount, int given_Amount) {
        this.required_Amount = required_Amount;
        this.given_Amount = given_Amount;
    }

    @Override
    public String getMessage() {

        String message = "\nInsufficientAmountException: Provided " + this.given_Amount + "Rs, but Required "
                + this.required_Amount + "Rs.";
        return message;
    }

    @Override
    public String toString() {
        return this.getMessage();
    }

}

/**
 * This is an Exception class which throws exception when Unknown Book Name is
 * Provided to Issue.
 * 
 * @author Yash Bhavsar (YashGames2007)
 * @version 1.2
 * @since 2022
 */
class NoBookFoundException extends Exception {

    private String name;
    private String author;

    public NoBookFoundException(String name, String author) {
        this.name = name;
        this.author = author;
    }

    @Override
    public String getMessage() {

        String message = "\nNoBookFoundException: No Book Found in Library Named " + this.name + " with Author named "
                + this.author;
        return message;
    }

    @Override
    public String toString() {
        return this.getMessage();
    }

}

/**
 * This is an Exception class which throws exception when supplied unregistered
 * Book which is returned by the User.
 * 
 * @author Yash Bhavsar (YashGames2007)
 * @version 1.2
 * @since 2022
 */
class UnknownAcquiredBookException extends Exception {

    private String name;

    public UnknownAcquiredBookException(String name) {
        this.name = name;
    }

    @Override
    public String getMessage() {

        String message = "\nUnknownAcquiredBookException: No Acquired Book Registered as " + this.name;
        return message;
    }

    @Override
    public String toString() {
        return this.getMessage();
    }

}

/**
 * This is the Book Class Which Extends the Mini Library's Book class with added
 * publisher details and IDs for the Books.
 * 
 * @author Yash Bhavsar (YashGames2007)
 * @version 1.2
 * @since 2022
 */
class _Book extends Book {

    /**
     * The Name of The Book Publisher.
     */
    private String publisher_Name;

    /**
     * The Date of The Book Publishing.
     */
    private LocalDate published_Date;

    /**
     * Identities of Books which will be set automatically to resolve conflicts.
     */
    static private int book_Identity = 100;

    /**
     * The ID of this Book.
     */
    private int book_ID;

    /**
     * Formatter for Date of Publishing.
     */
    @Deprecated
    static DateTimeFormatter format = DateTimeFormatter.ofPattern("dd LLLL yyy");

    /**
     * Constructor for Book Class to create an Book with given properties.
     * 
     * @param name           Name of the Book.
     * @param author_Name    Author's Name of the Book.
     * @param publisher_Name Publisher's Name of the Book
     * @param book_Type      Type of the Book.
     * @param total_Pages    Total Pages of the Book.
     * @param price          Price of the Book.
     */
    public _Book(String name, String author_Name, String publisher_Name, String book_Type, int total_Pages, int price) {
        super(name, author_Name, book_Type, total_Pages, price);

        this.publisher_Name = publisher_Name;
        this.published_Date = LocalDate.now();
        this.book_ID = book_Identity;
        book_Identity++;
    }

    /**
     * @return returns Publisher's Name of the Book.
     */
    public String getPublisher_Name() {
        return publisher_Name;
    }

    /**
     * @return returns Publishing Date of the Book.
     */
    public LocalDate getPublished_Date() {

        return this.published_Date;
    }

    /**
     * @return returns Identity No. of the Book.
     */
    public int getBook_ID() {
        return book_ID;
    }
}

/**
 * This is the Main Library class of the Package which has all the functionality
 * related to Library just like real Library.
 * 
 * @author Yash Bhavsar (YashGames2007)
 * @version 1.2
 * @since 2022
 */
public class Library {
    /**
     * Name of the Library.
     */
    String library_Name;

    /**
     * Total Books Capacity of the Library.
     */
    HashMap<_Book, Integer> total_Books;

    /**
     * Issued Books of the Library.
     */
    HashMap<_Book, Integer> acquired_Books;

    /**
     * Deprecated Books of the Library.
     */
    List<_Book> deprecated_Books;

    /**
     * No. of Total Books of the Library.
     */
    @Deprecated
    int total_Books_Count;

    /**
     * No. of Available Books of the Library.
     */
    @Deprecated
    int available_Books_Count;

    /**
     * No. of Acquired Books of the Library.
     */
    @Deprecated
    int acquired_Books_Count;

    /**
     * Constructor for Library class to Create an Library with given name and books
     * capacity.
     * 
     * @param library_Name Name of the Library.
     * @param books_Count  Total Books Capacity of the Library.
     */
    public Library(String library_Name, int books_Count) {

        this.library_Name = library_Name;
        total_Books = new HashMap<>(books_Count);
        acquired_Books = new HashMap<>();
        total_Books_Count = 0;
        available_Books_Count = 0;
        acquired_Books_Count = 0;
        System.out.printf("\nCreated a New Library: %s", this.library_Name);
    }

    /**
     * Library Class Method that searches for the specified Book in an given Hashmap
     * of Books in the Library.
     * 
     * @param all_Books  Map of Books of Library.
     * @param other_Book Book to search for in the Map.
     * @return Returns true if the given book is present in the map.
     */
    public boolean does_Contain_Book(HashMap<_Book, Integer> all_Books, _Book other_Book) {

        Set<_Book> books = all_Books.keySet();

        for (_Book book : books) {

            boolean _Name = book.getName() == other_Book.getName();
            boolean _Author_Name = book.getAuthor_Name() == other_Book.getAuthor_Name();
            boolean _Total_Pages = book.getTotal_Pages() == other_Book.getTotal_Pages();
            boolean _BookType = book.getBookType() == other_Book.getBookType();
            boolean _Price = book.getPrice() == other_Book.getPrice();
            boolean _publisher_Name = book.getPublisher_Name() == other_Book.getPublisher_Name();
            boolean _published_Date = book.getPublished_Date() == other_Book.getPublished_Date();
            boolean _book_ID = book.getBook_ID() == other_Book.getBook_ID();

            if (_Name && _Author_Name && _Total_Pages && _BookType && _Price && _publisher_Name && _published_Date
                    && _book_ID) {
                return true;
            }
        }
        return false;
    }

    /**
     * Library Class Method that adds the no. of copies of given book to the
     * Library.
     * 
     * @param book  Book to Publish in the Library.
     * @param count Mow many copies of Book will be Published in the Library.
     */
    public void publish_Books(_Book book, int count) {

        if (total_Books.containsKey(book)) {
            total_Books.put(book, (total_Books.get(book) + count));

        } else {
            total_Books.put(book, count);
        }
        System.out.printf("\nPublished %d Books, named %s, to the %s.", count, book.getName(), this.library_Name);
    }

    /**
     * Library Class Method that adds specified Book to the list of Deprecated Books
     * in the Library.
     * 
     * @param book Book to add to list of Deprecated Books in the Library.
     */
    public void deprecate_Book(_Book book) {

        int total = total_Books.get(book);
        deprecated_Books.add(book);
        total_Books.remove(book);
        System.out.printf("\nDeprecated %d Books, named %s, from the %s.", total, book.getName(), this.library_Name);
    }

    /**
     * Library Class Method that searches for specified book in the Library with the
     * help of given info like Book's name and Author's name and returns the
     * specific Book.
     * 
     * @param book_Name Name of the Book to search for in the Library.
     * @param author_Name Name of the Author of the Book specified.
     * @param price Price of the Book.
     * @return returns the Issued book (if present in the Library and satisfied given amount).
     * @throws InsufficientAmountException Thrown exception when provided amount is less than that of given amount.
     * @throws NoBookFoundException Thrown exception when the specified Book isn't found in the Library.
     */
    public _Book issue_Book(String book_Name, String author_Name, int price)
            throws InsufficientAmountException, NoBookFoundException {

        Set<_Book> books = this.total_Books.keySet();
        _Book issued_Book = null;

        for (_Book book : books) {
            if ((book.getName() == book_Name) && (book.getAuthor_Name() == author_Name)) {
                if (book.getPrice() > price) {
                    throw new InsufficientAmountException(book.getPrice(), price);
                } else {
                    issued_Book = book;
                    System.out.printf("\nIssued Book %s, from %s.", issued_Book.getName(), this.library_Name);

                    // ? Add The Book to acquired_Books and remove from total books (only one copy).
                    acquired_Books.put(issued_Book, 1);
                    total_Books.put(book, total_Books.get(issued_Book) - 1);

                    if (total_Books.get(book) == 0) { // ? If the Number of Books Become Zero then remove the
                                                      // ? book from total_Books.
                        total_Books.remove(book);
                    }
                }
                break;
            }
        }
        if (issued_Book == null) {
            throw new NoBookFoundException(book_Name, author_Name);
        }
        return issued_Book;
    }

    /**
     * Library Class Method that re-adds the Issued Book to the Library.
     * @param book Book to Return in the Library.
     * @throws UnknownAcquiredBookException Thrown exception when the given book is not registered as Issued books in the Library.
     */
    public void return_Book(_Book book) throws UnknownAcquiredBookException {
        if (does_Contain_Book(acquired_Books, book)) {

            if (total_Books.get(book) == null) {

                total_Books.put(book, 1);
            } else {

                total_Books.put(book, total_Books.get(book) + 1);
            }

            acquired_Books.put(book, acquired_Books.get(book) - 1);

            if (acquired_Books.get(book) == 0) { // ? If the Number of Books Become Zero then remove book from
                                                 // ? acquired_Books.
                acquired_Books.remove(book);
            }

            System.out.printf("\nReturned Book, named %s, to the %s.", book.getName(), this.library_Name);
        } else {
            throw new UnknownAcquiredBookException(book.getName());
        }
    }

    /**
     * The Main Method of the class Library to Compile the Package.
     * 
     * @param args given command line arguments.
     */
    public static void main(String[] args) {
        LocalDate date = LocalDate.now();
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd LLLL yyy");
        String text = date.format(formatter);
        System.out.printf("\n" + text);

        Library books = new Library("Central Library", 2);

        _Book book1 = new _Book("Wings of Fire", "Arun Tiwari", "Universities Press", "Autobiography", 300, 1000);
        _Book book2 = new _Book("Atomic Habits", "James Clear", "Penguin Random House", "Life Lesson", 280, 1300);

        books.publish_Books(book1, 5);
        books.publish_Books(book2, 10);
        books.publish_Books(book2, 10);

        try {
            _Book my_Book = books.issue_Book("Wings of Fire", "Arun Tiwari", 1000);
            books.return_Book(my_Book);

        } catch (Exception e) {
            System.out.println(e);
        }
    }
}
