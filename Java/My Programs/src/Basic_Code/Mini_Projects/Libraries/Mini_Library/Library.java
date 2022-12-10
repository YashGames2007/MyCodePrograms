package Basic_Code.Mini_Projects.Libraries.Mini_Library;

public class Library {
    private Book[] books;
    private Book[] acquired_Books;
    private int total_Count;
    private int available_Count;
    private int acquired_Count;

    public Library(int total_Books) {
        this.books = new Book[this.total_Count];
        this.acquired_Books = new Book[this.total_Count];
        this.total_Count = total_Books;
        this.available_Count = 0;
        this.acquired_Count = 0;
    }

    public void add_Book(Book new_Book) {

        if (total_Count == available_Count) {
            System.out.printf("\nMax Books Limit Exceeded..!!");
            return;
        }
        for (int i = 0; i < available_Count; i++) {
            Book book = books[i];
            if (book.getName() == new_Book.getName()) {
                System.out.printf("\nDuplicate Book Found..!!:: Name: %s", new_Book.getName());
                return;
            }
        }
        this.books[available_Count] = new_Book;
        this.available_Count++;
        System.out.printf("\nBook Added Successfully..!!");
    }

    public Book issueBook(String book_Name) {
        for (int i = 0; i < this.available_Count; i++) {
            if (this.books[i].getName() == book_Name) {
                Book required_Book = this.books[i];
                for (int j = i; j < this.available_Count - 1; j++) {
                    this.books[j] = this.books[j + 1];
                }
                this.available_Count--;

                this.acquired_Books[this.acquired_Count] = required_Book;
                this.acquired_Count++;
                System.out.printf("\nBook Issued Successfully..!!");
                return required_Book;
            }
        }
        System.out.printf("\nRequired Book Not Found..!!");
        return (new Book("", "", "", -1, -1));
    }

    public void returnBook(Book acquired_Book) {
        for (int i = 0; i < this.acquired_Count; i++) {
            if (this.acquired_Books[i].getName() == acquired_Book.getName()) {
                if (!this.acquired_Books[i].equals(acquired_Book)) {
                    System.out.printf("\nBook Has Been Pirated..!!");
                    return;
                }
                Book required_Book = this.acquired_Books[i];
                for (int j = i; j < this.available_Count - 1; j++) {
                    this.acquired_Books[j] = this.acquired_Books[j + 1];
                }
                this.acquired_Count--;

                this.books[this.available_Count] = required_Book;
                this.available_Count++;
                System.out.printf("\nBook Returned Successfully..!!");
                return;
            }
        }
        System.out.printf("\nAcquired Book Not Found..!!");
    }

    public void available_Books_Info() {
        System.out.printf("\nAvailable Books Information: %d :::\n", available_Count);
        for (int i = 0; i < available_Count; i++) {
            System.out.printf("\n");
            System.out.printf("\nBook Name   : %s", books[i].getName());
            System.out.printf("\nAuthor      : %s", books[i].getAuthor_Name());
            System.out.printf("\nBook Type   : %s Book", books[i].getBookType());
            System.out.printf("\nTotal Pages : %d", books[i].getTotal_Pages());
            System.out.printf("\nPrice       : %d Rs", books[i].getPrice());
            System.out.printf("\n");
        }
        System.out.printf("\n");
    }
}