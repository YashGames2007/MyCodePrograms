package Basic_Code.Mini_Projects.Library;

class Book {
    String name;
    String author_Name;
    String type;
    int total_Pages;
    int price;

    public Book(String name, String author_Name, String type, int total_Pages, int price) {
        this.name = name;
        this.author_Name = author_Name;
        this.type = type;
        this.total_Pages = total_Pages;
        this.price = price;
    }

    public String getName() {
        return name;
    }

    public String getAuthor_Name() {
        return author_Name;
    }

    public String getType() {
        return type;
    }

    public int getTotal_Pages() {
        return total_Pages;
    }

    public int getPrice() {
        return price;
    }

    public boolean equals(Book other_Book) {
        boolean name = (this.name == other_Book.name);
        boolean author_Name = (this.author_Name == other_Book.author_Name);
        boolean type = (this.type == other_Book.type);
        boolean total_Pages = (this.total_Pages == other_Book.total_Pages);
        boolean price = (this.price == other_Book.price);

        if (name && author_Name && type && total_Pages && price) {
            return true;
        }
        return false;
    }
}

class Library {
    Book[] books;
    Book[] acquired_Books;
    int total_Count;
    int available_Count;
    int acquired_Count;

    Library(int total_Books) {
        this.total_Count = total_Books;
        this.available_Count = 0;
        this.books = new Book[this.total_Count];
        this.acquired_Books = new Book[this.total_Count];
        this.acquired_Count = 0;
    }

    public void add_Book(Book new_Book) {

        if (total_Count == available_Count) {
            System.out.printf("\nMax Books Limit Exceeded..!!");
            return;
        }
        for (int i = 0; i < available_Count; i++) {
            Book book = books[i];
            if (book.name == new_Book.name) {
                System.out.printf("\nDuplicate Book Found..!!:: Name: %s", new_Book.name);
                return;
            }
        }
        this.books[available_Count] = new_Book;
        this.available_Count++;
        System.out.printf("\nBook Added Successfully..!!");
    }

    public Book issueBook(String book_Name) {
        for (int i = 0; i < this.available_Count; i++) {
            if (this.books[i].name == book_Name) {
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
            if (this.acquired_Books[i].name == acquired_Book.name) {
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
            System.out.printf("\nBook Name   : %s", books[i].name);
            System.out.printf("\nAuthor      : %s", books[i].author_Name);
            System.out.printf("\nBook Type   : %s Book", books[i].type);
            System.out.printf("\nTotal Pages : %d", books[i].total_Pages);
            System.out.printf("\nPrice       : %d Rs", books[i].price);
            System.out.printf("\n");
        }
        System.out.printf("\n");
    }
}

public class LibraryExercise {
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
        b2.author_Name = "Unknown";
        my_Library.returnBook(b1);
        my_Library.returnBook(b2);
        System.out.printf("\n");
        my_Library.available_Books_Info();
        my_Library.returnBook(b2);
    }
}
